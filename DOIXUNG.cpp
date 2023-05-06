#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        cin >> s;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
            for (char &c : tmp)
            {
                c = tolower(c);
            }
        }
        string s2 = tmp;
        int start = 0;
        int end = s2.size() - 1;
        while (start < end)
        {
            swap(s2[start], s2[end]);
            start++;
            end--;
        }
        if (s2 == tmp) {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    system("Pause");
}