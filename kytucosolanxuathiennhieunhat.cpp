#include <iostream>
#include <map>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    cin.ignore();
    while (testcase--)
    {
        string s;
        getline(cin, s);
        map<char, int>mp;
        for (auto it : s)
        {
            mp[it]++;
        }
        char result = '\0'; int frequency = INT_MIN;
        for (auto it : mp) {
            if (it.second > frequency)
            {
                result = it.first;
                frequency = it.second;
            }
            
        }
        cout << result << " " << frequency << '\n';
    }
    system("Pause");
}