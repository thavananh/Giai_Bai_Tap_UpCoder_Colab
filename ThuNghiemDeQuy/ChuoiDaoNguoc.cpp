#include <iostream>
#include <string>
using namespace std;

string daoNguocChuoi(string s)
{
    if (s[0] == '\0')
    {
        return "";
    }
    return daoNguocChuoi(s.substr(1)) + s[0];
}

int main()
{
    string s;    
    getline(cin, s);
    string s1 = daoNguocChuoi(s);
    cout << s1;
    system("Pause");
}