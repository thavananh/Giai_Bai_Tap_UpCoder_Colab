#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std; // tạo set;

int main() // Quaaaaaaqua
{ // temp qu
    string s;
    cin >> s;
    vector<char>temp;
    char c = s[0];
    s[0] = tolower(c);
    int count = 1;
    vector<vector<char>>luuTru;
    bool flag = false;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != s[i+1])
        {
            if (i > 0 && s[i] == s[i-1])
            {
                if (luuTru.size() > 0)
                {
                    for (auto row : luuTru)
                    {
                        int i = 0;
                        for (auto it : row)
                        {
                            if (it == temp[i])
                            {
                                flag = true;
                            }
                            else
                            {
                                flag = false;
                                break;
                            }
                            i++;
                        }
                    }
                    if (!flag)
                    {
                        count++;
                    }
                    else
                    {
                        luuTru.push_back(temp);
                    }
                }
                else
                {
                    luuTru.push_back(temp);
                }
                temp.clear();
                continue;
            }
            temp.push_back(s[i]);
        }
        else if (s[i] == s[i+1])
        {
            if (s[i] != s[i-1])
            {
                temp.push_back(s[i]);
            }
        }
    }
    cout << count;
    system("pause");
}