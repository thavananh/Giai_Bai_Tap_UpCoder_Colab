#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include "Person.h"
using namespace std;

class User : public Person
{
private:
    string _strFirstName, _strLastName, _strMoneyType, _strAccountStatus;
    double _dBalance;
public:
    User(string strID = "", string strPassword = "", string strFirstName = "", string strLastName = "", string strMoneyType = "", string strAccountStatus = "");
    User(const User& user);
    
};