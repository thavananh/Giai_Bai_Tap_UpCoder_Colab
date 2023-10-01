#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    stack<char>stc;
    string s;
    cin >> s;
    int count = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case ')': 
            if (!stc.empty() && stc.top() != '(')
            {
                stc.push(s[i]);
            }
            else
            {
                stc.pop();
            }
            break;
        case ']':
            if (!stc.empty() && stc.top() != '[')
            {
                stc.push(s[i]);
            }
            else
            {
                stc.pop();
            }
            break;
        case '}':
            if (!stc.empty() && stc.top() != '{')
            {
                stc.push(s[i]);
            }
            else
            {
                stc.pop();
            }
            break;
        default:
            stc.push(s[i]);
            break;
        }
    }
    if (stc.empty())
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}