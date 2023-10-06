#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include "Admin.h"
#include "User.h"
#include "DateTime.h"
using namespace std;

Admin::Admin(string strID, string strPassword) : Person(strID, strPassword)
{}

Admin::Admin(const Admin& admin) : Person(admin)
{}

Admin::~Admin() {}

int Admin::checkNumbersOfAdmins()
{
    int iNumbersOfAdmins = 0;
    ifstream ifAdminFile;
    ifAdminFile.open("Admin.txt", ios::in);
    if (ifAdminFile.is_open())
    {
        string line;
        while (getline(ifAdminFile, line))
        {
            iNumbersOfAdmins++;
        }
    }
    return iNumbersOfAdmins;
}

void Admin::inputLogin()
{
    string strID, strPassword;
    cin >> strID >> strPassword;
    Admin::setStrID(strID);
    Admin::setStrPassword(strPassword);
}

void Admin::login()
{
    if (Admin::checkNumbersOfAdmins() < 3)
    {
        cout << "Cannot login, not enough admins" << endl;
        return;
    }
    Admin::inputLogin();
    ifstream ifAdminFile;
    ifAdminFile.open("Admin.txt", ios::in);
    bool bIsAuth = false;
    if (ifAdminFile.is_open())
    {
        string strFileLine;
        while (getline(ifAdminFile, strFileLine))
        {
            stringstream ss(strFileLine);
            string ID;
            string Pin;
            ss >> ID;
            ss >> Pin;
            if (ID == Admin::getID() && Pin == Admin::getID())
            {
                bIsAuth = true;
            }
        }
    }
    else
    {
        cout << "error while opening file" << endl;
    }
    if (bIsAuth)
    {
        cout << "login successfully" << endl;
        return;
    }
    cout << "login failed" << endl;
}

bool Admin::checkAccountDuplicate(string strID)
{
    ifstream ifAccountListFile;
    ifAccountListFile.open("TheTu.txt", ios::in);
    if (ifAccountListFile.is_open())
    {
        string strFileLine;
        while (getline(ifAccountListFile, strFileLine))
        {
            stringstream ss(strFileLine);
            string strTmp;
            ss >> strTmp;
            if (strID == strTmp)
            {
                return true;
            }
        }
        ifAccountListFile.close();
    }
    return false;
}

void Admin::addUserAccount()
{
    ofstream ofAccountListFile;
    ofAccountListFile.open("TheTu.txt", ios::app);
    User usr;
    if (ofAccountListFile.is_open())
    {
    loop:
        string strID;
        cout << "Input account to add: ";
        cin >> strID;
        if (Admin::checkAccountDuplicate(strID))
        {
            cout << "Error, found duplicate !!!";
            goto loop;
        }
        usr.setStrID(strID);
        usr.setStrPassword("123456");
        cin.ignore();
        ofAccountListFile << usr.getID() << " " << usr.getPassword() << endl;
        ofAccountListFile.close();
    }
    else
    {
        cout << "Error while opening file";
    }
    ofstream FileID;
    FileID.open(usr.getID() + ".txt", ios::out);
    if (FileID.is_open())
    {
        FileID << usr.getID() << '\n';
        FileID << usr.getFirstName() + " " + usr.getLastName() << '\n';
        FileID << usr.getBalance() << '\n';
        FileID << usr.getCurrencyName() << '\n';
        FileID << usr.getAccountStatus() << '\n';
        FileID.close();
    }
    ofstream historyFile;
    historyFile.open("LichSu" + usr.getID() + ".txt", ios::out);
    if (historyFile.is_open())
    {
        historyFile << "init account successfully" << getTime() << '\n';
        historyFile.close();
    }
}

void Admin::viewAccountList()
{
    ifstream ifAccountListFile;
    ifAccountListFile.open("TheTu.txt", ios::in);
    if (ifAccountListFile.is_open())
    {
        string strFileLine;
        while (getline(ifAccountListFile, strFileLine))
        {
            cout << strFileLine << endl;
        }
    }
}

void Admin::removeAccount()
{
    string strID;
    cout << "Input an account to remove: ";
    cin >> strID;
    if (remove((strID + ".txt").c_str()) == 0)
    {
        cout << "remove successfully" << endl;
    }
    else
    {
        cout << "Error while removing account" << endl;
        return;
    }
    ifstream ifAccountListFile;
    ifAccountListFile.open("TheTu.txt", ios::in);
    vector<string>vFileLine;
    if (ifAccountListFile.is_open())
    {
        string strFileLine;
        while (getline(ifAccountListFile, strFileLine))
        {
            stringstream ss(strFileLine);
            string strTmp;
            ss >> strTmp;
            if (strTmp == strID)
            {
                continue;
            }
            else
            {
                vFileLine.push_back(strFileLine);
            }
        }
        ifAccountListFile.close();
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
    ofstream ofAccountListFile;
    ofAccountListFile.open("TheTu.txt", ios::out);
    if (ofAccountListFile.is_open())
    {
        for (auto it : vFileLine)
        {
            ofAccountListFile << it << '\n';
        }
        ofAccountListFile.close();
    }
    else
    {
        cout << "Error while opening file";
    }
    ofstream ofAccountHistoryFile;
    ofAccountHistoryFile.open("LichSu" + strID + ".txt", ios::app);
    if (ofAccountHistoryFile.is_open())
    {
        ofAccountHistoryFile << "Account removed successfully " << getTime() << '\n';
        ofAccountHistoryFile.close();
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
}

void Admin::unlockAccount()
{
    ifstream ifAccountListFile;
    string strID;
    cout << "Please input account to unlock: ";
    cin >> strID;
    vector<string>vFileLine;
    ifAccountListFile.open(strID + ".txt", ios::in);
    if (ifAccountListFile.is_open())
    {
        string strFileLine;
        while (getline(ifAccountListFile, strFileLine))
        {
            vFileLine.push_back(strFileLine);
            if (strFileLine == "false")
            {
                vFileLine.push_back("true");
            }
        }
        ifAccountListFile.close();
    }
    ofstream writeAccountFile;
    writeAccountFile.open(strID + ".txt", ios::out);
    for (auto it : vFileLine)
    {
        writeAccountFile << it << '\n';
    }
}