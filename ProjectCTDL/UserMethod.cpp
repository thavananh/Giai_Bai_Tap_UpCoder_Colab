#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include "User.h"
using namespace std;

User::User(string strID = "", string strPassword = "", string strFirstName = "", string strLastName = "", string strMoneyType = "", string strAccountStatus = "", double dBalance = 0.0) : Person(strID, strPassword)
{
    this->_strFirstName = strFirstName;
    this->_strLastName = strLastName;
    this->_strMoneyType = strMoneyType;
    this->_strAccountStatus = strAccountStatus;
}
User::User(const User& user) : Person(user)
{
    this->_strFirstName = user._strFirstName;
    this->_strLastName = user._strLastName;
    this->_strMoneyType = user._strMoneyType;
    this->_dBalance = user._dBalance;
}