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

User::User(string strID, string strPassword, string strFirstName, string strLastName, string strMoneyType, string strAccountStatus, double dBalance) : Person(strID, strPassword)
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

User::~User(){}

string User::getFirstName()
{
    return this->_strFirstName;
}

string User::getLastName()
{
    return this->_strLastName;
}

string User::getMoneyType()
{
    return this->_strLastName;
}

string User::getAccountStatus()
{
    return this->_strAccountStatus;
}

double User::getBalance()
{
    return this->_dBalance;
}

int User::checkNumbersOfUsers()
{
    int iNumbersOfUsers = 0;
    ifstream ifUserListFile;
    ifUserListFile.open("TheTu.txt", ios::in);
    if (ifUserListFile.is_open())
    {
        string strFileLine;
        while (getline(ifUserListFile, strFileLine))
        {
            iNumbersOfUsers++;
        }
    }
    return iNumbersOfUsers;
}

void User::login()
{
    if (checkNumbersOfUsers() < 10)
    {
        cout << "Login failed, not enough users";
    }
    else
    {
        ifstream ifUserListFile;
        ifUserListFile.open("TheTu.txt", ios::in);
        bool bIsAuth = false;
        if (ifUserListFile.is_open())
        {
            string strFileLine;
            while (getline(ifUserListFile, strFileLine))
            {
                stringstream ss(strFileLine);
                string strID, strPassword;
                ss >> strID;
                ss >> strPassword;
                if (strID == User::getID() && strID == User::getPassword())
                {
                    bIsAuth = true;
                }
            }
            if (!bIsAuth)
            {
                cout << "Login failed, username or password incorrect";
            }
            else
            {
                cout << "Login successfully";
            }
            
        }
        else
        {
            cout << "Error while opening file";
        }
    }   
}
