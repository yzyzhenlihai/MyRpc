#pragma once
#include<iostream>
#include<unistd.h>
#include "MrpcConfig.h"
#include "MrpcChannel.h"
#include "MrpcController.h"
#include "MrpcLogger.h"
//单例模式定义rpc应用类
class MrpcApplication{
public:
    static MrpcApplication& GetInstance();
    static void Init(int argc,char** argv);
    static MrpcConfig GetRpcConfig();
private:
    MrpcApplication(){};
    MrpcApplication(MrpcApplication&) = delete;
    MrpcApplication(MrpcApplication&&) = delete;
    static MrpcConfig rpcConfig_;
};