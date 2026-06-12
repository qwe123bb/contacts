#pragma once
#include<string>
class contact{
    public:
    std::string name;
    std::string phone;
    std::string email;
    contact(std::string name,std::string phone,std::string email);
    void print()const;

};