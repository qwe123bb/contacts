#include"addressbook.h"
#include<iostream>
#include<fstream>

int main(){
    addressbook book;
    book.loadfromfile("contacts.txt");
    int choice;
    while(true){
        std::cout<<"---通讯录管理系统---\n";
        std::cout<<"1.添加联系人\n";
        std::cout<<"2.查看联系人\n";
        std::cout<<"3.搜索联系人\n";
        std::cout<<"4.删除联系人\n";
        std::cout<<"5.编辑联系人\n";
        std::cout<<"0.退出\n";
        std::cout<<"请输入您的选择：";
        std::cin>>choice;
        switch(choice){
            case 1:{
                std::string name,phone,email;
                std::cout<<"请输入姓名：";
                std::cin>>name;
                std::cout<<"请输入电话：";
                std::cin>>phone;
                std::cout<<"请输入邮箱：";
                std::cin>>email;
                book.addcontact(name,phone,email);
                break;
            }
            case 2:{

                book.listcontacts();
                break;
            }
            case 3:{
                std::string name;
                std::cout<<"请输入要搜索的姓名：";
                std::cin>>name;
                book.searchcontact(name);
                break;
            }
            case 4:{
                std::string name;
                std::cout<<"请输入要删除的姓名：";
                std::cin>>name;
                book.deletecontact(name);
                break;

            }
            case 5:{
                std::string name;
                std::cout<<"请输入要编辑的姓名：";
                std::cin>>name;
                book.editcontact(name);
                break;
            }
            case 0:
    
    {
         book.savetofile("contacts.txt");
    std::cout<<"退出程序！\n";
    return 0;}
            
            default:
            std::cout<<"无效选择，请重新输入！\n";
            break;
    }
}
    
    
    return 0;
}