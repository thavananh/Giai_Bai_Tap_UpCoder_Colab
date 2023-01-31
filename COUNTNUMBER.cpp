#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map <long int, long int>mp;
    long int n; cin >> n;
    vector<long int>a;
    for (size_t i = 0; i < n; i++)
    {
        long int x; cin >> x;
        a.push_back(x);
        mp[a[i]]++;
    }
    for (size_t i = 0; i < n; i++)
    {
        if (mp[a[i]] != 0)
        {
            cout << mp[a[i]] << " ";
            mp[a[i]] = 0;
        }
    }
    system("Pause");
}