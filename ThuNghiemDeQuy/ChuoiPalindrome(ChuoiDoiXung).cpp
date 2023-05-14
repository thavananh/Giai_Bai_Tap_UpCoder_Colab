#include <iostream>
#include <cstring>
using namespace std;

bool kiemTraPalindrome(string s)
{
    if (s.size() == 0 || s.size() == 1)
    {
        return true;
    }
    if (s[0] == s[s.size() - 1])
    {
        return kiemTraPalindrome(s.substr(1, s.size()-1-1));
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << kiemTraPalindrome(s);
    system("Pause");
}