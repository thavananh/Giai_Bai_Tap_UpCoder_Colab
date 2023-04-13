#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s1;
        getline(cin, s1);
        string tmp;
        string s2;
        stringstream ss(s1);
        while (ss >> tmp) {
            s2.append(tolower(tmp));
        }
        cout << s2 << '\n';
        tmp = s2;
        int start = 0;
        int end = s2.length() - 1;
        while (start <= end)
        {
            swap(tmp[start], tmp[end]);
            start++;
            end--;
        }
        if (tmp == s2)
        {
            cout << 1 << '\n';
        } 
        else
        {
            cout << 0 << '\n';
        }
        
    }
    system("Pause");
}