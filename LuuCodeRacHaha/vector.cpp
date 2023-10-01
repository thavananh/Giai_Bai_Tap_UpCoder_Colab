#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool nt(int n);
int tinhTongKhongNguyenTo(int n)
{
    int sum = 0;
    while (n)
    {
        if (!nt(n%10))
        {
            sum = sum + n % 10;
        }
        n = n / 10;
    }
    return sum;
}

bool nt(int n) {
    if (n < 2) {
        return false;
    }
    int m = sqrt(n);
    for (size_t i = 2; i <= m; i++)
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
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (nt(v[i]))
        {
            cout << tinhTongKhongNguyenTo(v[i]) << '\n';
        }
        else
        {
            cout << "-1" << '\n';
        }
    }
}