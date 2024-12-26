#include "MrpcController.h"

void MrpcController::SetFailed(const std::string& reason){
    failedReason_ = reason;
    isFailed_ = true;
}
bool MrpcController::Failed() const{
    return isFailed_;
}
std::string MrpcController::ErrorText() const{
    return failedReason_;
}


void MrpcController::Reset(){
    failedReason_ = "";
    isFailed_ = false;
}
void MrpcController::StartCancel(){}
bool MrpcController::IsCanceled() const{return false;}
void MrpcController::NotifyOnCancel(google::protobuf::Closure* callback){}