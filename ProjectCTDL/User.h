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
    string _strFirstName, _strLastName, _strCurrencyName, _strAccountStatus;
    double _dBalance;
public:
    User(string strID = "", string strPassword = "", string strFirstName = "", string strLastName = "", string strCurrencyName = "", string strAccountStatus = "", double dBalance = 0.0);
    User(const User& user);
    ~User();
    string getFirstName();
    string getLastName();
    string getCurrencyName();
    string getAccountStatus();
    void setFirstName(string strFirstName);
    void setLastName(string strLastName);
    void setCurrencyName(string strCurrencyName);
    void setAccountStatus(string strAccountStatus);
    void setBalance(double dBalance);
    double getBalance();
    int checkNumbersOfUsers();
    void login() override;
    void viewAccountInfo();
    bool withdrawMoney();
    bool transferMoney();
    void viewTransactionDetails();
    void changePassword();
};