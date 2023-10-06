#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include "Admin.h"
#include "DateTime.h"
#include "User.h"
using namespace std;

Admin::Admin(string strID = "", string strPassword = "") : Person(strID, strPassword)
{}

Admin::Admin(const Admin& admin) : Person(admin)
{}

Admin::~Admin(){}

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

void Admin::login()
{
    if (Admin::checkNumbersOfAdmins() < 3)
    {
        cout << "Cannot login, not enough admins" << endl;    
        return;
    }
    ifstream ifAdminFile;
    ifAdminFile.open("Admin.txt", ios::in);
    bool isAuth = false;
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
                isAuth = true;
            }
        }
    }
    else
    {
        cout << "error while opening file" << endl;
    }
    if (isAuth)
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
        string strID;
        cout << "Input account to add: ";
        cin >> strID;
        if (Admin::checkAccountDuplicate(strID))
        {
            cout << "Error, found duplicate";
            return;
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
        historyFile << "init account " << getTime() << '\n';
        historyFile.close();
    }
    void Admin::viewAccountList()
    {
        
    }
}