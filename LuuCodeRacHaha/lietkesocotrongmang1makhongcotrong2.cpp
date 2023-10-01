#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n; cin >> n;
        int m; cin >> m;
        int a[n], b[m];
        map<int, int>mp;
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (size_t i = 0; i < m; i++)
        {
            cin >> b[i];
            mp[b[i]];
        }
        for (size_t i = 0; i < n; i++)
        {
            if (mp.count(a[i]) == 0)
            {
                cout << a[i] << " ";
            }
        }
    }
    system("Pause");
}