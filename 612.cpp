#include <iostream>
#include <string>
#include <cstring> 
#include <algorithm>
using namespace std;

bool cay(char born)
{
    if (born == '_' || born == '*' || born == '-' || born == ' ')
    {
        return true;
    }
    return false;
}

int main()
{ //02032004
    string id, name, born;
    cin >> id;
    cin.ignore();
    getline(cin, name);
    getline(cin, born);
    cout << id << '\n';
    cout << name << '\n';
    for (size_t i = 0; i < born.size(); i++)
    {
        born.erase(remove_if(born.begin(), born.end(), cay));
    }
    char day[3], month[3], year[5];
    strncpy(day, born.c_str(), 2);
    day[3] = '/';
    strncpy(month, born.c_str() + 2, 2);
    month[3] = '/'; 
    strncpy(year, born.c_str() + 4, 4);
    cout << day << month << year;
}