#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>v;
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << '\n';
    for (vector<int>::iterator it = v.end() - 1; it != v.begin() - 1; it--) {
        cout << *it << " ";
    }
    
}