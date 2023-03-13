#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map <int, int>mp;
    int n; cin >> n;
    int a[1000000];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (mp[a[i]] != 0)
        {
            cout << mp[a[i]] << " ";
            mp[a[i]] = 0;
        }
    }

}