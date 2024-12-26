#include<iostream>
#include<string>
#include "user.pb.h"
#include "MrpcApplication.h"
#include "MrpcProvider.h"

class UserService : public UserServiceRpc{
public:
    UserService(){}
    ~UserService(){}
    //本地业务
    bool Login(std::string name,std::string passwd){
        std::cout<<"local login service is called"<<std::endl;
        std::cout<<"name: "<<name<<" "<<"passwd: "<<passwd<<std::endl;
        return true;
    }
    //重写rpc的Login业务,由框架负责调用这个函数
    void Login(::google::protobuf::RpcController* controller,
                       const ::UserRequest* request,
                       ::UserResponse* response,
                       ::google::protobuf::Closure* done)
    {
        //取出参数
        std::string name=request->name(),passwd=request->password();
        if(Login(name,passwd)){
            ResultCode *resultCode=response->mutable_result();
            resultCode->set_errcode(200);
            resultCode->set_errmsg("success");
            response->set_success(true);
        }
        //运行回调函数
        done->Run();
    }
};

int main(int argc,char** argv){
    //初始化RPC框架
    MrpcApplication::Init(argc,argv);
    //添加rpc业务，把UserService对象发布到rpc节点上
    MrpcProvider provider;
    provider.NotifyService(new UserService());
    provider.Run();//阻塞，等待远程调用
}