#include "MrpcChannel.h"

// 将调用请求序列化，并通过网络发送给RPC服务器
// 按照RPC框架自定义协议规定，请求格式如下:
// headerSize + serviceName + methodName + argSize + args
// 其中serviceName + methodName + argSize由proto定义的message进行包装序列化
void MrpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                          google::protobuf::RpcController* controller, 
                          const google::protobuf::Message* request,
                          google::protobuf::Message* response, 
                          google::protobuf::Closure* done)
{
    controller->Reset();
    const google::protobuf::ServiceDescriptor *serviceDes = method->service();
    // 获得服务名称serviceName
    std::string serviceName = serviceDes->name();
    // 获得方法名称methodName
    std::string methodName = method->name();
    // 序列化参数args
    std::string args;
    request->SerializeToString(&args);
    uint32_t argSize = args.size();
    // 构造rpcHeader
    RpcHeader::RpcHeader rpcHeader;
    rpcHeader.set_servicename(serviceName);
    rpcHeader.set_methodname(methodName);
    rpcHeader.set_argsize(argSize);
    std::string rpcHeaderStr;
    rpcHeader.SerializeToString(&rpcHeaderStr);
    uint32_t headerSize = rpcHeaderStr.size();
    // 构造最终通过网络发送的数据
    std::string sendData;
    sendData = std::string((char*)&headerSize,4) + rpcHeaderStr + args;

    //通过网络发送数据
    // MrpcConfig config = MrpcApplication::GetInstance().GetRpcConfig();
    // std::string rpcServerIp = config.Load("rpcserverip");
    // std::string rpcServerPort = config.Load("rpcserverport");
    MrpcZookeeperClient zkClient;
    zkClient.Start();
    std::string data = zkClient.GetZNodeData(serviceName, methodName);
    zkClient.CloseConn();
    if(data == ""){
        controller->SetFailed("GetZNodeData is null");
        return;
    }
    LOG_DEBUG("GetZNodeData is '%s'", data.c_str());
    int colonLoc = data.find(":");
    std::string rpcServerIp = data.substr(0,colonLoc);
    std::string rpcServerPort = data.substr(colonLoc+1,data.size()-(colonLoc+1));
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientfd == -1){
        controller->SetFailed("create socket error");
        return;
    }
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET,rpcServerIp.c_str(),&serverAddr.sin_addr.s_addr);
    serverAddr.sin_port = htons(atoi(rpcServerPort.c_str()));
    if(connect(clientfd, (struct sockaddr*)&serverAddr,sizeof(serverAddr)) == -1){
        controller->SetFailed("client connection failed");
        return;
    }else{
        //发送数据给RPC服务端
        ssize_t sendSize = send(clientfd, sendData.c_str(), sendData.size(), 0);
        if(sendSize == -1){
            controller->SetFailed("send data error");
            return;
        }
        std::cout<<"send bytes "<<sendSize<<std::endl;
        sleep(1);
        //从服务端接收数据
        char responseData[1024];
        ssize_t recvSize = recv(clientfd, responseData, sizeof(responseData), 0);
        if(recvSize == -1){
        
            controller->SetFailed("receive data error");
            return;
        }
        std::cout<<"recvive bytes "<<recvSize<<std::endl;
        //反序列化
        std::string responseStr = std::string(responseData);
        if(!response->ParseFromString(responseStr)){
            controller->SetFailed("ParseFromString error");
            return;
        }
        
    }

    
    
}