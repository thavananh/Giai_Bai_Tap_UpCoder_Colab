#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    // int testcase;
    // cin >> testcase;
    // while (testcase--)
    // {
    //     int n;
    //     cin >> n;
    //     map<int, int>mp;
    //     int count = 0;
    //     for (size_t i = 0; i < n; i++)               -> sử dụng map
    //     {
    //         int x; cin >> x;
    //         mp[x];
    //     }
    //     for (auto it : mp) {
    //         count++;
    //     }
    //     cout << count << "\n";
    // }

    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n;
        cin >> n;
        set<int>s;
        int count = 0;
        for (size_t i = 0; i < n; i++)
        {
            int x; cin >> x;                       // -> sử dụng set
            s.insert(x);
        }
        for (auto it : s) {
            count++;
        }
        cout << count << '\n';
    }
    
    system("Pause");
}