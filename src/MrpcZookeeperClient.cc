#include "MrpcZookeeperClient.h"

MrpcZookeeperClient::MrpcZookeeperClient(){}
MrpcZookeeperClient::~MrpcZookeeperClient(){
    if(clientHandle_){
        zookeeper_close(clientHandle_);
    }
}

void GlobalWatcher(zhandle_t *zh, int type, 
        int state, const char *path,void *watcherCtx)
{
    if(type == ZOO_SESSION_EVENT){
        //表示连接已经建立
        if(state == ZOO_CONNECTED_STATE){
            sem_t *sem = (sem_t*)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}
//连接zookeeper服务器
void MrpcZookeeperClient::Start(){

    //获得zookeeper的IP+port
    MrpcConfig config = MrpcApplication::GetRpcConfig();
    std::string ip = config.Load("zookeeperip");
    std::string port = config.Load("zookeeperport");
    std::string host = ip + ":" + port;
    /*
        因为连接建立是异步的，返回zhandle_t并不代表已经与服务器建立连接
        只有当返回状态为 ZOO_CONNECTED_STATE 才表示建立成功
     */
    sem_t sem;
    sem_init(&sem, 0, 0);
    //将信号量添加至句柄的上下文中
    clientHandle_ = zookeeper_init(host.c_str(), GlobalWatcher, 60000, nullptr, nullptr, 0);
    if(clientHandle_ == nullptr){
        LOG_ERROR("zookeeper handle is nullptr");
        return;
    }
    zoo_set_context(clientHandle_, reinterpret_cast<void*>(&sem));
    sem_wait(&sem);
    LOG_INFO("Zookeeper server successfully connected");
}

//添加zookeeper节点
void MrpcZookeeperClient::AddZNode(std::string serviceName, std::string methodName,
                                    const char* dataBuf, int state){

    std::string dataPath  = "/" + serviceName;
    int ret = zoo_exists(clientHandle_, dataPath.c_str(), 0, nullptr);
    if(ret == ZNONODE){
        //当前无此节点
        int result = zoo_create(clientHandle_, dataPath.c_str(), nullptr, -1, 
                                    &ZOO_OPEN_ACL_UNSAFE, state, nullptr, 0);
        if(result == ZNOAUTH){
            LOG_ERROR("No permission to create '%s'", dataPath.c_str());
            return;
        }else if(result == ZOK){
            LOG_INFO("'%s' is created successfully", dataPath.c_str());
        }else if(result == ZNOCHILDRENFOREPHEMERALS){
            LOG_INFO("'%s' cannot create children of ephemeral nodes", dataPath.c_str());
        }
    }
    dataPath = dataPath + "/" + methodName;
    ret = zoo_exists(clientHandle_, dataPath.c_str(), 0, nullptr);
    if(ret == ZNONODE){
        //当前无此节点
        int result = zoo_create(clientHandle_, dataPath.c_str(), dataBuf, 
                                strlen(dataBuf), &ZOO_OPEN_ACL_UNSAFE, state, nullptr, 0);
        if(result == ZNOAUTH){
            LOG_ERROR("No permission to create '%s'", dataPath.c_str());
            return;
        }else if(result == ZOK){
            LOG_INFO("'%s' is created successfully", dataPath.c_str());
        }
    }

}

//获得zookeeper节点的数据
std::string MrpcZookeeperClient::GetZNodeData(std::string serviceName, std::string methodName){
    
    std::string dataPath = "/" + serviceName + "/" + methodName;
    //服务不存在
    int ret = zoo_exists(clientHandle_, dataPath.c_str(), 0, nullptr);
    if(ret == ZNONODE){
        LOG_INFO("'%s' does not exist", dataPath.c_str());
        return "";
    }
    char dataBuf[512];
    int dataLen = sizeof(dataBuf);
    ret = zoo_get(clientHandle_, dataPath.c_str(), 0, dataBuf, &dataLen, nullptr);
    if(ret == ZOK){
        LOG_INFO("'%s' data query successfully",dataPath.c_str());
        return std::string(dataBuf,dataLen);
    }else{
        LOG_INFO("'%s' data query failed",dataPath.c_str());
    }
    return "";
}   

void MrpcZookeeperClient::CloseConn(){
    if(clientHandle_){
        zookeeper_close(clientHandle_);
    }
}