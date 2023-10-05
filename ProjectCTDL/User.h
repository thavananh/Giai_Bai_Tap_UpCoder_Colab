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
    User(string strID = "", string strPassword = "", string strFirstName = "", string strLastName = "", string strMoneyType = "", string strAccountStatus = "", double dBalance = 0.0);
    User(const User& user);
    ~User();
    string getFirstName();
    string getLastName();
    string getMoneyType();
    string getAccountStatus();
    double getBalance();
    int checkNumbersOfUsers();
    void login() override;
    void viewAccountInfo();
    void withdrawMoney();
    void transferMoney();
    void viewTransactionDetails();
    void changePassword();
};