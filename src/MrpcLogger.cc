#include "MrpcLogger.h"

MrpcLogger::MrpcLogger(){
   
}

MrpcLogger* MrpcLogger::GetInstance(){
    static MrpcLogger logger;
    return &logger;
}

void MrpcLogger::Write(int level, const char* format, ...){
    va_list valist;
    va_start(valist,format);
    //判断是否需要重新创建文件
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    int hour = now->tm_hour;
    int minute = now->tm_min;
    int sec = now->tm_sec;
    if(year!=year_ || month!=month_ || day!=day_){
        {
            std::unique_lock<std::mutex> locker(mutex_);
            if(logFd_){
                fflush(logFd_);
                fclose(logFd_);
            }
            year_ = year;
            month_ = month;
            day_ = day;
            char fileName[1024];
            snprintf(fileName, sizeof(fileName), "%s/%d_%d_%d%s", path_, year_, month_, day_, suffix_);
            logFd_ = fopen(fileName, "a");
            assert(logFd_);
        }
    }
    char writeContent[1024];
    vsnprintf(writeContent, sizeof(writeContent), format, valist);
    std::string writeStr(writeContent,strlen(writeContent));
    writeStr.insert(writeStr.size(),"\n");
    char timestamp[1024];
    if(level == 1){
        //INFO
        snprintf(timestamp, sizeof(timestamp), "[INFO] %d-%d-%d-%d:%d:%d\t"
                                                ,year_, month_, day_, hour, minute, sec);
    }else if(level == 2){
        //DEBUG
        snprintf(timestamp, sizeof(timestamp), "[DEBUG] %d-%d-%d-%d:%d:%d\t"
                                                ,year_, month_, day_, hour, minute, sec);
    }else if(level == 3){
        //ERROR
        snprintf(timestamp, sizeof(timestamp), "[DEBUG] %d-%d-%d-%d:%d:%d\t"
                                                ,year_, month_, day_, hour, minute, sec);
    }
    writeStr.insert(0,timestamp);
    blockQueue_.Push(writeStr);
    va_end(valist);
}

//初始化日志系统，创建log文件夹，生成.log文件
void MrpcLogger::Init(const char* path, const char* suffix){
    //strcpy(path_,path);
    //strcpy(suffix_,suffix);
    path_ = path;
    suffix_ = suffix;
    //启动写线程
    std::unique_ptr<std::thread> writeThread(new std::thread(ThreadWriteLog_));
    writeThread_ = std::move(writeThread);
    writeThread_->detach();
    //构造文件路径
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    year_ = now->tm_year + 1900;
    month_ = now->tm_mon + 1;
    day_ = now->tm_mday;
    char fileName[1024] = {0};
    snprintf(fileName, sizeof(fileName), "%s/%d_%d_%d%s", path_, year_, month_, day_, suffix_);
    if(logFd_){
        fflush(logFd_);
        fclose(logFd_);
    }
    logFd_ = fopen(fileName, "a");
    if(logFd_ == nullptr){
        //当前文件夹不存在
        mkdir(path,0777);
        logFd_ = fopen(fileName, "a");
    }
    assert(logFd_);
}

//异步写
void MrpcLogger::AsynWrite_(){
    while(1){
        std::string content = blockQueue_.Pop();
        {
            std::unique_lock<std::mutex> locker(mutex_);
            if(logFd_){
                fputs(content.c_str(),logFd_);
                fflush(logFd_);//立刻将缓冲区的数据写入文件
            }
        }
    }
}

void MrpcLogger::ThreadWriteLog_(){
    MrpcLogger::GetInstance()->AsynWrite_();
}