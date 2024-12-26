#pragma once
#include<queue>
#include<mutex>
#include<condition_variable>
#include<memory>
//异步写日志，定义的阻塞队列
template<typename T>
class MrpcBlockQueue
{
public:
    MrpcBlockQueue(int maxSize = 1024);
    void Push(T);
    T Pop();
private:
    size_t maxSize_;
    std::queue<T> blockQueue_;
    std::mutex mutex_;
    std::condition_variable isEmpty_;
    std::condition_variable isFull_;
};  



template<class T>
MrpcBlockQueue<T>::MrpcBlockQueue(int maxSize){
    maxSize_ = maxSize;
}

template<class T>
void MrpcBlockQueue<T>::Push(T item){
    std::unique_lock<std::mutex> locker(mutex_);//拿锁
    while(blockQueue_.size()>=maxSize_){
        isEmpty_.wait(locker);
    }
    //加入阻塞队列
    blockQueue_.push(item);
    isFull_.notify_one();
}
template<class T>
T MrpcBlockQueue<T>::Pop(){
    std::unique_lock<std::mutex> locker(mutex_);//拿锁
    while(blockQueue_.size()==0){
        isFull_.wait(locker);
    }
    T item = blockQueue_.front();
    blockQueue_.pop();
    isEmpty_.notify_one();
    return item;
}