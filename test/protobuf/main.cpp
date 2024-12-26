#include "test.pb.h"
#include<iostream>

int main(){

    contacts::Person p;
    p.add_name("yuzy");
    p.set_age(18);
    p.set_sex(1);
    std::string send_str;
    p.SerializeToString(&send_str);
    //打印序列化后的对象
    std::cout<<"after serial:"<<send_str.data()<<std::endl;
    //反序列化
    contacts::Person p2;
    p2.ParseFromString(send_str);
    std::cout<<"name:"<<p2.name(0)<<std::endl;
    std::cout<<"age:"<<p2.age()<<std::endl;
    std::cout<<"sex:"<<(p2.sex()? "male" : "female")<<std::endl;
    return 0;
}