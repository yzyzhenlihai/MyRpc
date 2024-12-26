#pragma once
#include<google/protobuf/service.h>
#include<string>
#include "RpcHeader.pb.h"
#include "MrpcApplication.h"
#include "MrpcController.h"
#include<google/protobuf/service.h>
#include<google/protobuf/descriptor.h>
#include<muduo/net/TcpClient.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include "MrpcZookeeperClient.h"
class MrpcChannel : public google::protobuf::RpcChannel{

public:
    void CallMethod(const google::protobuf::MethodDescriptor* method,
                          google::protobuf::RpcController* controller, 
                          const google::protobuf::Message* request,
                          google::protobuf::Message* response, 
                          google::protobuf::Closure* done);
    
};