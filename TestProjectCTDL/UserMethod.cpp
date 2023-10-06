#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include "User.h"
#include "DateTime.h"
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

void User::inputLogin()
{
loop:
    string strID, strPassword;
    cin >> strID >> strPassword;
    for (size_t i = 0; i < strPassword.size(); i++)
    {
        if (isdigit(strPassword[i]))
        {
            cout << "do not input password have character" << endl;
            goto loop;
        }
    }
    User::setStrID(strID);
    User::setStrPassword(strPassword);
}

void User::login()
{
    if (checkNumbersOfUsers() < 10)
    {
        cout << "Login failed, not enough users";
    }
    else
    {
        User::inputLogin();
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
        cout << "Error while opening file";
        return false;
    }
    if (dWithdrawAmount > dBalance) // 
    {
        system("cls");
        cout << "Your balance amount not enough. Please enter your withdraw amount again !!!" << endl; 
        // có lỗi khi balance nhỏ hơn 50000, và số tiền nhập lại ko đủ 50000 =))))) và kết quả là vòng lặp vĩnh cửu
        goto loop;
    }
    cout << "Do you want to withdraw ? (yes/no): ";
    string strSelection;
    cin >> strSelection;
    if (strSelection == "yes")
    {
        dBalance -= dWithdrawAmount;
        cout << "Transaction successful !!!" << endl;
        ofstream ofAccountRecordFile, ofTransactionRecordFile;
        ofAccountRecordFile.open("LichSu" + User::getID() + ".txt", ios::app);
        if (ofAccountRecordFile.is_open())
        {
            ofAccountRecordFile << "You withdraw " << dWithdrawAmount << getTime(); 
            ofAccountRecordFile.close();
        }
        else
        {
            cout << "Error while opening file";
        }

        if (ofTransactionRecordFile.is_open())
        {
            ofTransactionRecordFile << "You withdraw " << dWithdrawAmount << getTime() << endl;;
        }
        else
        {
            cout << "Error while opening file" << endl;
        }
        return true;
    }
    return false;
}

bool User::transferMoney()
{
    string strDestinationAccount;
    double dTransferAmount;
loop:
    cout << "Enter destination account: ";
    cin >> strDestinationAccount;
    cout << "Enter transfer amount: ";
    cin >> dTransferAmount;
    cin.ignore();
    if (dTransferAmount < 50000)
    {
        system("cls");
        cout << "You need to transfer more than 50000. Please enter your transfer amount" << endl;
        goto loop;
    }
    double dBalance;
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
        cout << "Error while opening file";
    }
    if (dTransferAmount > dBalance) // 
    {
        system("cls");
        cout << "Your balance amount not enough. Please enter your transfer amount again !!!" << endl; 
        // có lỗi khi balance nhỏ hơn 50000, và số tiền nhập lại ko đủ 50000 =))))) và kết quả là vòng lặp vĩnh cửu
        goto loop;
    }
    cout << "Do you want to transfer ? (yes/no): ";
    string strSelection;
    cin >> strSelection;
    if (strSelection == "yes")
    {
        dBalance -= dTransferAmount;
        cout << "Transaction successful !!!" << endl;
        ofstream ofAccountRecordFile, ofTransactionRecordFile;
        ofAccountRecordFile.open("LichSu" + User::getID() + ".txt", ios::app);
        ofTransactionRecordFile.open("Transaction" + User::getID() + ".txt", ios::app);
        if (ofAccountRecordFile.is_open())
        {
            ofAccountRecordFile << "You transfer " << dTransferAmount << getTime() << endl;; 
            ofAccountRecordFile.close();
        }
        else
        {
            cout << "Error while opening file" << endl;
        }
        if (ofTransactionRecordFile.is_open())
        {
            ofTransactionRecordFile << "You transfer " << dTransferAmount << getTime() << endl;;
        }
        else
        {
            cout << "Error while opening file" << endl; // nen luu may cai cout nay` vo file =))
        }
        return true;
    }
    return false;
}

void User::viewTransactionDetails()
{
    ifstream ifAccountTrasactionFile;
    ifAccountTrasactionFile.open("Transaction" + User::getID() + ".txt", ios::in);
    if (ifAccountTrasactionFile.is_open())
    {
        string strFileLine;
        while (getline(ifAccountTrasactionFile, strFileLine))
        {
            cout << strFileLine << endl;
        }
        ifAccountTrasactionFile.close();
    }
    else
    {
        cout << "Error while opening file";
    }
}

void User::changePassword()
{
    ifstream ifAccountListFile;
    vector<string>vFileLine;
    string strNewPassword, strOldPassword;
    ifAccountListFile.open("TheTu.txt", ios::in);
    if (ifAccountListFile.is_open())
    {
        string strFileLine;
        while (getline(ifAccountListFile, strFileLine))
        {
            vFileLine.push_back(strFileLine);
            stringstream ss(strFileLine);
            string strID;
            ss >> strID;
            if (strID != User::getID())
            {
                continue;     
            }
            string strVerifyNewPassword, strVerifyOldPassword;
            ss >> strOldPassword;
loop:
            cout << "Please enter your old pin: ";
            cin >> strVerifyOldPassword;
            if (strOldPassword != strVerifyNewPassword)
            {
                system("cls");
                cout << "You enter wrong pin. Please enter your pin again !!! " << endl;
                goto loop;
            }
            cout << "Please enter your new pin: ";
            cin >> strNewPassword;
loop1:
            cout << "Please re-enter your pin again: ";
            cin >> strVerifyNewPassword;
            if (strVerifyNewPassword != strNewPassword)
            {
                cout << "You enter wrong new pin. Please enter your new pin again !!! " << endl;
                goto loop1;
            }
            cout << "Changed password successfully" << endl;
        }
        ifAccountListFile.close();
    }
    ofstream ofAccountList;
    ofAccountList.open("TheTu.txt", ios::out);
    if (ofAccountList.is_open())
    {
        for (auto it : vFileLine)
        {
            stringstream ss(it);
            string strID;
            ss >> strID;
            if (strID == User::getID())
            {
                ofAccountList << strID << " " << strNewPassword << endl;
                continue;
            }
            ofAccountList << it << endl;
        }
        ofAccountList.close();
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
}