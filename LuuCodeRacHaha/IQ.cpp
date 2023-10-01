#include <iostream>
#include <climits>
#include <set>
using namespace std;

int main() 
{
    set<int>s;
    long long max = INT_MIN;
    long long min = INT_MAX;
    int x;
    while (cin >> x)
    {
        s.insert(x);   
    }
    s.erase(s.begin());
    s.erase(--s.end());
    for (auto it : s)
    {
        cout << it << " ";
    }
}