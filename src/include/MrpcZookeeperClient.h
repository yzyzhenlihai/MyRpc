# pragma once
#include "MrpcApplication.h"
#include <zookeeper/zookeeper.h>
#include <semaphore.h>
class MrpcZookeeperClient{

public:
    MrpcZookeeperClient();
    ~MrpcZookeeperClient();
    void Start();   //连接zookeeper服务器
    void AddZNode(std::string serviceName, std::string methodName, const char* dataBuf, int state);    //添加zookeeper节点
    std::string GetZNodeData(std::string serviceName, std::string methodName);    //获得zookeeper节点的数据
    void CloseConn();
private:
    zhandle_t *clientHandle_;
};