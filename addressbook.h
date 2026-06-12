#pragma once
#include"contact.h"
#include<vector>
#include<string>
class addressbook{
    private:
    std::vector<contact>contacts;
    public:
    void addcontact(const std::string&name,const std::string&phone,const std::string&email);
    void listcontacts()const;
    void searchcontact(const std::string& name)const;
    void deletecontact(const std::string&name);
    void savetofile(const std::string& filename)const;
    void loadfromfile(const std::string& filename);
  bool samename(const std::string& name)const;
    void editcontact(const std::string& name);
    

};