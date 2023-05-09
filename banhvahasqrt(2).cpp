#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    long long a[10000];
    long long tienthuong = 0;
    long long max = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        tienthuong = tienthuong + a[i];
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    tienthuong = (tienthuong*2 + max)/(n+1);
    cout << tienthuong << '\n';
    if (tienthuong >= pow(10, n))
    {
        cout << "yes" << '\n';
    }
    else
    {
        cout << "no" << '\n';
    }
    string s = to_string(tienthuong);
    long long nam_tu = pow(2, s.size());
    if (nam_tu > 100)
    {
        cout << "death";
    }
    else
    {
        cout << nam_tu;
    }
}