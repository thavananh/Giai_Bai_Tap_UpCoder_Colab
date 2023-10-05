#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include "DateTime.h"
using namespace std;

string getTime()
{
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d %H:%M:%S");
    string timeString = ss.str();
    return timeString;
}
