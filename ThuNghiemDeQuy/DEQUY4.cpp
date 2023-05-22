#include <iostream>
#include <cmath>
using namespace std;

long long deQuy(long long n, long long x)
{
    if (n == 0 || x == 1)
    {
        return 1;
    }
    return pow(x, n) + deQuy(x, n-1);
}

int main()
{
    long long n, x;
    cin >> n >> x;
    cout << deQuy(n, x);
}