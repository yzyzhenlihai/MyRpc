#include "MrpcConfig.h"

MrpcConfig::MrpcConfig(){}
MrpcConfig::~MrpcConfig(){}
//加载配置文件
void MrpcConfig::LoadConfigFile(const char* configFile){
    FILE *file=fopen(configFile,"r");
    if(file==nullptr){
        std::cout<<configFile<<" is not exist"<<std::endl;
        exit(EXIT_FAILURE);
    }
    //开始读取配置文件
    char lineBuf[1024];
    //fgets读取一行，会自动在末尾加上'\0'
    while(fgets(lineBuf,sizeof(lineBuf),file)){
        lineBuf[strcspn(lineBuf,"\n")]='\0';
        std::string line(lineBuf);//转化为字符串
        Trim_(line);
        //判断是否为注释
        if(line.empty() || line[0]=='#') continue;
        std::string key,value;
        //std::cout<<"line:"<<line<<std::endl;
        int idx=line.find('=');
        if(idx==std::string::npos) continue;
        key=line.substr(0,idx);
        Trim_(key);
        value=line.substr(idx+1,line.size()-idx);
        Trim_(value);
        //std::cout<<"key:"<<key<<" "<<"value:"<<value<<std::endl;
        configMap_[key]=value;
    }

}

//获得某个配置项
std::string MrpcConfig::Load(std::string key){
    if(configMap_.count(key)){
        return configMap_[key];
    }
    return "";
}
void MrpcConfig::Trim_(std::string &line){
    //取出字符串两端的空格
    int idx=line.find_first_not_of(' ');
    if(idx!=std::string::npos){
        //字符串前边有空格
        line=line.substr(idx,line.size()-idx);
    }
    idx=line.find_last_not_of(' ');
    if(idx!=std::string::npos){
        //字符串后面有空格
        line=line.substr(0,idx+1);
    }
}