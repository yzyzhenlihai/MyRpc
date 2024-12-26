#pragma once
#include "MrpcBlockQueue.h"
#include <thread>
#include <string>
#include <sys/stat.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
class MrpcLogger
{
public:
    static MrpcLogger* GetInstance();
    void Write(int level, const char* format, ...);
    void Init(const char* path="./log", const char* suffix=".log");//初始化日志系统
private:
    MrpcLogger();
    static void ThreadWriteLog_();
    void AsynWrite_();//异步写日志
    
private:
    MrpcBlockQueue<std::string> blockQueue_;//阻塞队列
    std::unique_ptr<std::thread> writeThread_;//写线程
    FILE* logFd_;
    int year_;
    int month_;
    int day_;
    const char* path_;
    const char* suffix_;
    std::mutex mutex_;//互斥访问日志文件
};

#define LOG_BASE(level, format, ...)\
    do{\
        MrpcLogger *log = MrpcLogger::GetInstance();\
        log->Write(level, format, ##__VA_ARGS__);\
        \
    }while(0);

#define LOG_INFO(format, ...) do{LOG_BASE(1, format, ##__VA_ARGS__)}while(0);
#define LOG_DEBUG(format, ...) do{LOG_BASE(2, format, ##__VA_ARGS__)}while(0);
#define LOG_ERROR(format, ...) do{LOG_BASE(3, format, ##__VA_ARGS__)}while(0);