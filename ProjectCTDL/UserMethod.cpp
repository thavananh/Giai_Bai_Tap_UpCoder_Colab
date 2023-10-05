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

User::User(string strID, string strPassword, string strFirstName, string strLastName, string strCurrencyName, string strAccountStatus, double dBalance) : Person(strID, strPassword)
{
    this->_strFirstName = strFirstName;
    this->_strLastName = strLastName;
    this->_strCurrencyName = strCurrencyName;
    this->_strAccountStatus = strAccountStatus;
}

User::User(const User& user) : Person(user)
{
    this->_strFirstName = user._strFirstName;
    this->_strLastName = user._strLastName;
    this->_strCurrencyName = user._strCurrencyName;
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

string User::getCurrencyName()
{
    return this->_strCurrencyName;
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
                cout << "Login failed, id or password incorrect";
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

void User::viewAccountInfo()
{
    ifstream ifAccountFile;
    string strArray[4];
    ifAccountFile.open(User::getID() + ".txt", ios::in);
    for (size_t i = 0; i < 4; i++)
    {
        getline(ifAccountFile, strArray[i]);
    }
    cout << "Your account details: " << endl;
    cout << "ID: " << strArray[0] << endl;
    cout << "Full name: " << strArray[1] << endl;
    cout << "Balance: " << strArray[2] << endl;
    cout << "Currency name: " << strArray[3] << endl;
}

bool User::withdrawMoney()
{
    double dWithdrawAmount;
loop:
    cout << "Enter withdraw amount: ";
    cin >> dWithdrawAmount;
    if (dWithdrawAmount == 0)
    {
        return false;
    }
    if (dWithdrawAmount < 50000)
    {
        system("cls");
        cout << "Withdraw at least above 50000. Please enter your withdraw amount again !!!" << endl;
        goto loop;
    }
    double dBalance;
    ifstream ifAccountFile;
    vector<string>vFileLine(5, ""); // use to update file
    ifAccountFile.open(User::getID() + ".txt", ios::in);
    if (ifAccountFile.is_open())
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (i == 2)
            {
                ifAccountFile >> dBalance;
            }
            else
            {
                getline(ifAccountFile, vFileLine[i]);
            }
        }
        ifAccountFile.close();
    }
    else
    {
        cout << "Error while openning file";
    }
    if (dWithdrawAmount > dBalance) // 
    {
        system("cls");
        cout << "Your balance amount not enough. Please enter your withdraw amount again !!!" << endl; 
        // có lỗi khi balance nhỏ hơn 50000, và số tiền nhập lại ko đủ 50000 =))))) và kết quả là vòng lặp vĩnh cửu
        goto loop;
    }
    cout << "Ban co chac muon rut khong (co/khong): ";
    string strSelection;
    cin >> strSelection;
    if (strSelection == "co")
    {
        dBalance -= dWithdrawAmount;
    }
    else
    {
        return false;
    }
    cout << "Transaction successful !!!" << endl;
    ofstream ofAccountRecordFile;
    ofAccountRecordFile.open("LichSu" + User::getID() + ".txt", ios::app);
}