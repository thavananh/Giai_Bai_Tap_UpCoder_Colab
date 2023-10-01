#include <iostream>
#include <map>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    
    while (testcase--)
    {
        int n; cin >> n;
        map<int, int>mp;
        for (size_t i = 0; i < n; i++)
        {
            int x; cin >> x;
            mp[x]++;
        }
        long long result, frequency;
        for (auto it : mp) {
            if (it.second > frequency)
            {
                result = it.first;
                frequency = it.second;
            }
        }
        cout << result << " " << frequency;
    }
    
}