#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <set>
using namespace std; // tạo set;

int main() // Quaaaaaaqua
{ // temp qu
    string s;
    cin >> s;
    string temp = "";
    char c = s[0];
    s[0] = tolower(c);
    bool flag = false;
    set<string>string_set;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != s[i+1])
        {
            if (i > 0 && s[i] == s[i-1])
            {
                string_set.insert(temp);
                temp = "";
                continue;
            }
            temp = temp + s[i];
        }
        else if (s[i] == s[i+1])
        {
            if (s[i] != s[i-1])
            {
                temp = temp + s[i];
            }
        }
    }
    cout << string_set.size();
    system("pause");
}