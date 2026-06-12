#include"addressbook.h"
#include<iostream>
#include<fstream>

void addressbook::addcontact(const std::string&name,const std::string&phone,const std::string&email){
    if(samename(name)){
        std::cout<<"存在同名联系人，无法添加！\n";

        return;
    }
  
    contacts.emplace_back(contact(name,phone,email));
    std::cout<<"添加成功！\n";
}

void addressbook::listcontacts()const{
    if(contacts.empty()){
        std::cout<<"通讯录为空！\n";
        return;
    }
    for(int i=0;i<contacts.size();++i){
        std::cout<<"---联系人"<<i+1<<"---\n";
        contacts[i].print();
    }
}
void addressbook::searchcontact(const std::string& name)const{
    for(const contact&c:contacts){
        if(c.name==name){
            c.print();;
            return ;

        }
    }
    std::cout<<"未找到联系人:"<<name<<std::endl;
}

void addressbook::deletecontact(const std::string& name){
        for(auto it=contacts.begin();it!=contacts.end();++it){
            if(it->name==name){
                contacts.erase(it);
                std::cout<<"删除成功！\n";
                return;
            }
        }
        std::cout<<"未找到联系人:"<<name<<std::endl;
    }

void addressbook::savetofile(const std::string& filename)const
{
    
    std::ofstream file (filename);
     std::cout << "Saving to: " << filename << "\n";  // 加这行
     for(const contact&c: contacts){
        file<<c.name<<"\n";
        file<<c.phone<<"\n";
        file<<c.email<<"\n";

     }
    

}
void addressbook::loadfromfile(const std::string& filename){
    
    std::ifstream file(filename);
    
    if(!file.is_open()){
        std::cout<<"无法打开文件:"<<filename<<std::endl;
        return;
    }
    std::string name,phone,email;
    while(std::getline(file,name)&&std::getline(file,phone)&&std::getline(file,email)){
        contacts.emplace_back(contact(name,phone,email));

    }
}
bool addressbook::samename(const std::string& name)const{
    for(const auto&c:contacts){
        if(c.name==name){
           
            return true;
        }
    }
    return false;
}