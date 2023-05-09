#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n)
    {
        string s;
        cin >> s;
        vector<long long>v1;
        string temp = "";
        char current_dau;
        char previous_dau;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]) && i != s.size() - 1)
            {
                temp = temp + s[i];
            }
            else
            {
                if (i == s.size() - 1)
                {
                    temp = temp + s[i];
                }
                else
                {
                    current_dau = s[i];
                }
                v1.push_back(stoi(temp));
                temp = "";
                if (v1.size() > 1)
                { 
                    long long k; 
                    switch (previous_dau)
                    {
                    case '-':
                        k = v1[0] - v1[1];
                        v1.clear();
                        v1.push_back(k);
                        break;
                    case '+':
                        k = v1[0] + v1[1];
                        v1.clear();
                        v1.push_back(k);
                        break;
                    case '/':
                        k = v1[0] / v1[1];
                        v1.clear();
                        v1.push_back(k);
                        break;
                    case '*':
                        k = v1[0] / v1[1];
                        v1.clear();
                        v1.push_back(k);
                        break;
                    default:
                        break;
                    }  
                }              
            }
            previous_dau = current_dau;
        }
        
        cout << v1[0] << '\n';
        n--;
    }
}