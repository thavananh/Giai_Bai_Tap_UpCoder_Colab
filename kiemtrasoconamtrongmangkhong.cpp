#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    // int testcase;
    // cin >> testcase;
    // while (testcase--)
    // {
    //     int n;
    //     cin >> n;
    //     map <int, int>mp;
    //     for (size_t i = 0; i < n; i++)
    //     {
    //         int x; cin >> x;
    //         mp[x];
    //     }
    //     int q; cin >> q;
    //     while (q--)
    //     {                                                        -> sử dụng map
    //         int x; cin >> x;
    //         if (mp.count(x) != 0)
    //         {
    //             cout << "Yes" << '\n';
    //         }
    //         else
    //         {
    //             cout << "No" << '\n';
    //         }
            
    //     }
    // }

    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n; cin >> n;
        set<int>s;
        for (size_t i = 0; i < n; i++)
        {
            int x; cin >> x;
            s.insert(x);
        }
        int q;
        cin >> q;
        while (q--)
        {
            int x; cin >> x;
            if (s.count(x) != 0)
            {
                cout << "Yes" << '\n';
            }
            else
            {
                cout << "No" << '\n';
            }
            
        }
        
        
        
    }
    
    system("Pause");
}