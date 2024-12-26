#include "MrpcProvider.h"

MrpcProvider::MrpcProvider(){}   

//阻塞运行，等待调用者调用
void MrpcProvider::Run(){
    //使用muduo网络库建立网络通信
    //获得rpc服务器的IP和port
    MrpcConfig rpcConfig=MrpcApplication::GetInstance().GetRpcConfig();
    std::string rpcserverip=rpcConfig.Load("rpcserverip");
    uint16_t rpcserverport=atoi(rpcConfig.Load("rpcserverport").c_str());


    muduo::net::InetAddress rpcAddr(rpcserverip,rpcserverport);
    muduo::net::TcpServer server(&eventLoop_,rpcAddr,"RpcServer");
    //定义监听和消息收发的回调函数
    server.setConnectionCallback(std::bind(&MrpcProvider::OnConnection,this,std::placeholders::_1));
    server.setMessageCallback(std::bind(&MrpcProvider::OnMessage,this,std::placeholders::_1,
                            std::placeholders::_2,std::placeholders::_3));
    server.setThreadNum(4);
    std::string dataStr = rpcserverip + ":" + rpcConfig.Load("rpcserverport");
    MrpcZookeeperClient zkClient;
    zkClient.Start();
    for(auto m : serviceMap){
        std::string serviceName = m.first;
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> methodmap = m.second.methodMap;
        for(auto method : methodmap){
            std::string methodName = method.first;  
            zkClient.AddZNode(serviceName, methodName, dataStr.c_str(), 0);
        }
    }

    server.start();
    eventLoop_.loop();
}
//注册rpc服务（将注册服务的相关信息保存下来）
void MrpcProvider::NotifyService(google::protobuf::Service *service){
    ServiceInfo serviceInfo;
    //获得服务的描述指针
    const google::protobuf::ServiceDescriptor *serviceDesc = service->GetDescriptor();
    serviceInfo.m_service=service;
    //获得服务的名称
    const std::string serviceName = serviceDesc->name();
    //std::cout<<serviceName<<" is registered"<<std::endl;
    LOG_INFO("%s is registered", serviceName.c_str());
    
    //获得服务的方法数量
    const int methodCnt = serviceDesc->method_count();
    //std::cout<<"there are "<<methodCnt<<" method totally"<<std::endl;
    LOG_INFO("there are %d method totally", methodCnt);
    for(int i=0;i<methodCnt;i++){
        const google::protobuf::MethodDescriptor *methodDesc = serviceDesc->method(i);
        const std::string methodName = methodDesc->name();//获得方法的名称
        serviceInfo.methodMap.insert({methodName,methodDesc});
    }
    serviceMap.insert({serviceName,serviceInfo});
   
}
//rpc服务器监听的回调函数
void MrpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn){
    //std::cout<<"connection successfully"<<std::endl;
    if(!conn->connected()){
        //表示客户端关闭
        conn->shutdown();//关闭连接
    }
}
//rpc服务器接收消息和发送消息的回调函数
void MrpcProvider::OnMessage(const muduo::net::TcpConnectionPtr& conn,
                            muduo::net::Buffer* buffer,
                            muduo::Timestamp)
{
    std::string requestData = buffer->retrieveAllAsString(); 
    uint32_t headerSize = 0;
    requestData.copy((char*)&headerSize, 4, 0);   
    //获得请求数据头
    std::string header = requestData.substr(4,headerSize);
    //反序列化成RPC框架定义的RpcHeader
    RpcHeader::RpcHeader rpcHeader;
    rpcHeader.ParseFromString(header);
    std::string serviceName = rpcHeader.servicename();
    std::string methodName = rpcHeader.methodname();
    uint32_t argSize = rpcHeader.argsize();
    //获得请求参数
    std::string args = requestData.substr(4 + headerSize, argSize);

    //获得对应的服务和方法
    google::protobuf::Service *curService;
    if(serviceMap.count(serviceName)){
        curService=serviceMap[serviceName].m_service;
    }else{
        //不存在对应服务
        LOG_ERROR("Service: %s is not exist", serviceName);
        //std::cout<<"Service: "<<serviceName<<" is not exist"<<std::endl;
        return;
    }
    const google::protobuf::MethodDescriptor *curMethod;
    if(serviceMap[serviceName].methodMap.count(methodName)){
        curMethod = serviceMap[serviceName].methodMap[methodName];
    }
    //获得服务中方法的请求格式和响应格式
    google::protobuf::Message *request = curService->GetRequestPrototype(curMethod).New();
    google::protobuf::Message *response = curService->GetResponsePrototype(curMethod).New();
    request->ParseFromString(args);
    //构造CallMethod方法的回调函数
    google::protobuf::Closure *done = google::protobuf::NewCallback<MrpcProvider,
                                                                const muduo::net::TcpConnectionPtr&,
                                                                google::protobuf::Message*>
                                                                (this,
                                                                &MrpcProvider::SendResponse,
                                                                conn,
                                                                response);
    //调用远程请求的方法
    curService->CallMethod(curMethod,nullptr,request,response,done);
}   

//CallMethod的回调函数，再业务执行完后会自动调用，将响应结果序列化后发送给调用者
void MrpcProvider::SendResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* response){
    std::string responseData;
    if(response->SerializeToString(&responseData)){
        conn->send(responseData);
    }else{
        //响应结果序列化失败
        LOG_ERROR("Response result serialization failed");
        //std::cout<<"Response result serialization failed"<<std::endl;
    }
    
}