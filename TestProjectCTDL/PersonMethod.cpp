#include "Person.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
using namespace std;

Person::Person(string strID, string strPassword)
{
    this->_strID = strID;
    this->_strPassword = strPassword;
}

Person::Person(const Person& person)
{
    this->_strID = person._strID;
    this->_strPassword = person._strPassword;
}

Person::~Person() {}

string Person::getID()
{
    return this->_strID;
}

string Person::getPassword()
{
    return this->_strPassword;
}

void Person::setStrID(string strID)
{
    this->_strID = strID;
}

void Person::setStrPassword(string strPassword)
{
    this->_strPassword = strPassword;
}
