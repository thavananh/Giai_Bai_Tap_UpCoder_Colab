#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>v;
    int x = 0;
    while (cin >> x)
    {
        if(cin.get() == '\n') {
            break;
        }
        v.push_back(x);
    }
    vector<int>v1;
    int k = 0;
    while (cin >> k)
    {
        if(cin.get() == '\n') {
            break;
        }
        v1.push_back(k);
    }
    if (v.size() > 1)
    {
        v1.erase(v.begin(), v.begin()+1);
    }
    else
    {
        if (v[0] < 0)
        {
            v1.clear();
        }
        else
        {
            v1.erase(v.begin() + v[0]);
        }
        
    }
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}