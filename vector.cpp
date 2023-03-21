#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool nt(int n) {
    if (n < 2) {
        return false;
    }
    for (size_t i = 0; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int>v;
    int n; cin >> n;
    int x;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    for (auto it : v)
    {
        if (nt(it))
        {
            cout << "1";
        }
        else
        {
            cout << "-1";
        }
        
    }
    
    
}