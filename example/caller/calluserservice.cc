#include<iostream>
#include "MrpcApplication.h"
#include "user.pb.h"
#include<google/protobuf/message.h>
//调用远程rpc方法
int main(int argc, char** argv){

    MrpcApplication::Init(argc, argv);
    UserServiceRpc_Stub stub = UserServiceRpc_Stub(new MrpcChannel());

    UserRequest request;
    request.set_name("yzy");
    request.set_password("888888");
    UserResponse response;
    MrpcController controller;
    stub.Login(&controller, &request, &response, nullptr);

    //远程调用成功
    if(controller.Failed()){
        std::cout<<"remote rpc failed"<<std::endl;
        std::cout<<"the reason is "<<controller.ErrorText()<<std::endl;
    }else{
        if(response.result().errcode() == 0){
            //表示登录失败
            std::cout<<"remote login failed"<<std::endl;
            std::cout<<"error message: "<<response.result().errmsg();
        }else{
            //表示登录成功
            std::cout<<"remote login successfully"<<std::endl;
            std::cout<<"errcode: "<<response.result().errcode()<<std::endl;
            std::cout<<"errmsg: "<<response.result().errmsg()<<std::endl;
            std::cout<<"success: "<<response.success()<<std::endl;
        }
    }
    
}