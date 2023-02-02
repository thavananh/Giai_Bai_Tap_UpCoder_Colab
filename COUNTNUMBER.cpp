#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map <int, int>mp;
    int n; cin >> n;
    vector<int>v;
    vector<int>::iterator it;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.push_back(x);
        mp[x]++;
    }
    it = unique(v.begin(), v.begin() + v.size());
    v.resize(distance(v.begin(), it));
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    
    system("Pause");
}