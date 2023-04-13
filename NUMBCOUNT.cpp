#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    string s;
    while (getline(cin, s))
    {
        string tmp;
        int count = 0;
        stringstream ss(s);
        while (ss >> tmp) {
            count++;
        }
        cout << count << '\n';
    }
    system("Pause");
}