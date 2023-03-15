#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool cp(int a) {
    int sqrt_num = sqrt(a);
    if (sqrt_num * sqrt_num == a)
    {
        return true;
    }
    return false;
}

bool sochan(int a) {
    if (a % 2 == 0)
    {
        return true;
    }
    return false;
    
}

int main() {
    vector<int>v;
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }
    vector<int>::iterator itvar1 = remove_if(v.begin(), v.end(), cp);
    v.erase(itvar1, v.end());
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
}