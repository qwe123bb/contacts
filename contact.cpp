#include"contact.h"
#include<iostream>

contact::contact(std::string name,std::string phone,std::string email){
    this->name=name;
    this->phone=phone;
    this->email=email;
}

void contact::print()const{
    std::cout<<"姓名:"<<name<<std::endl;
    std::cout<<"电话："<<phone<<std::endl;
    std::cout<<"邮箱："<<email<<std::endl;
}