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

class Admin : public Person
{
    Admin(string strID = "", string strMaPin = "");
    Admin(const Admin& admin);
    ~Admin();
    int checkNumbersOfAdmins();
    void login() override;
    bool checkAccountDuplicate(string strID);
    void addUserAccount();
    void viewAccountList();
    void removeAccount();
    void unlockAccount();
};