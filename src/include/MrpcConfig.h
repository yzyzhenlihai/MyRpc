#pragma once
#include<string>
#include<cstdio>
#include<string.h>
#include<iostream>
#include<unordered_map>
//rpc配置类，负责配置相应的ip和端口号
class MrpcConfig{
public:
    MrpcConfig();
    ~MrpcConfig();
    void LoadConfigFile(const char* configFile);//加载配置文件
    std::string Load(std::string key);//获得某个配置项
private:
    std::unordered_map<std::string,std::string> configMap_;
    void Trim_(std::string &line);//去除字符串两端的空格
};