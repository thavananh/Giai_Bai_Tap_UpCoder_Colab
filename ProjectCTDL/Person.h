#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>

using namespace std;

class Person
{
private:
    string _strID, _strPassword;
public:
    Person(string strID = "", string strPassword = "");
    Person(const Person& person);
    ~Person();
    string getID();
    string getPassword();
    void setStrID(string strID);
    void setStrPassword(string strPassword);
    virtual void login() = 0;
};