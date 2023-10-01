#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char>stc;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            if (!(stc.empty()))
            {
                cout << stc.top();
                stc.pop();
            }
        }
        else
        {
            stc.push(s[i]);
        }
    }
    system("Pause");
}