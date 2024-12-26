#pragma once
#include<google/protobuf/service.h>
#include<google/protobuf/descriptor.h>
#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
#include<muduo/net/InetAddress.h>
#include<muduo/net/TcpConnection.h>
#include<memory> 
#include<string>
#include<functional>
#include<unordered_map>
#include "MrpcApplication.h"
#include "RpcHeader.pb.h"
#include "MrpcZookeeperClient.h"
class MrpcProvider{

public:
    MrpcProvider();
    void NotifyService(google::protobuf::Service *service);//添加rpc服务
    void Run();//阻塞运行，等待远程调用
private:
   muduo::net::EventLoop eventLoop_;//muduo库中利用epoll循环监听
   void OnConnection(const muduo::net::TcpConnectionPtr&);
   void OnMessage(const muduo::net::TcpConnectionPtr&,muduo::net::Buffer*,muduo::Timestamp);
   
   //服务信息
    struct ServiceInfo{
        google::protobuf::Service *m_service;//保存服务对象
        std::unordered_map<std::string ,const google::protobuf::MethodDescriptor*> methodMap;//服务的方法
    };
    std::unordered_map<std::string,ServiceInfo> serviceMap;
    //CallMethod的回调函数
    void SendResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);
};