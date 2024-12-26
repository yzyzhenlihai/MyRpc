# pragma once
#include<google/protobuf/service.h>
class MrpcController : public google::protobuf::RpcController
{
public:
    void SetFailed(const std::string& reason);  
    bool Failed() const;
    std::string ErrorText() const;


    void Reset();
    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(google::protobuf::Closure* callback);
private:
    std::string failedReason_;
    bool isFailed_;

};