#include "MrpcApplication.h"
MrpcConfig MrpcApplication::rpcConfig_;
MrpcApplication& MrpcApplication::GetInstance(){

    static MrpcApplication rpcApplication;
    return rpcApplication;
}

void ShowArgHelp(){
    std::cout<<"format: command -i <configfile>"<<std::endl;
}

//初始化rpc框架
void MrpcApplication::Init(int argc,char** argv){
    //表示没有传入参数
    if(argc<2){
        ShowArgHelp();
        exit(EXIT_FAILURE);
    }
    //用getopt提取参数
    int option;//参数选项，这里设置配置文件的参数选项为 -i
    std::string configFile="";
    //optarg:选项正确匹配后的参数字符串
    //optopt:选项匹配失败，无效选项字符
    while((option=getopt(argc,argv,"i:"))!=-1){
        switch (option)
        {
        case 'i' :
            configFile=optarg;
            break;
        case '?' :
            std::cout<<"invalid option: "<<optopt<<std::endl;
            ShowArgHelp();
            break;
        case ':' :
            std::cout<<"missing <configfile>"<<std::endl;
            ShowArgHelp();
            break;
        default:
            ShowArgHelp();
            break;
        }
    }
     //启动日志系统
    MrpcLogger::GetInstance()->Init();
    LOG_INFO("===============Log system startup==============");
    //开始加载配置文件
    rpcConfig_.LoadConfigFile(configFile.c_str());
    LOG_INFO("configFile: %s",configFile.c_str());
    LOG_INFO("rpcserverip: %s",rpcConfig_.Load("rpcserverip").c_str());
    LOG_INFO("rpcserverport: %s",rpcConfig_.Load("rpcserverport").c_str());
    LOG_INFO("zookeeperip: %s",rpcConfig_.Load("zookeeperip").c_str());
    LOG_INFO("zookeeperport: %s",rpcConfig_.Load("zookeeperport").c_str());
   
    
}
MrpcConfig MrpcApplication:: GetRpcConfig(){
    return rpcConfig_;
}