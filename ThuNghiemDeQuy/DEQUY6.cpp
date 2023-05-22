#include <iostream>
#include <cmath>
using namespace std;

long long giaiThua(long long n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * giaiThua(n-1);
}

double deQuy(long long n, long long x)
{
    if (n == 0)
    {
        return x;
    }
    return (pow(-1, n))*(pow(x, 2*n + 1))/(giaiThua(2*n+1)) + deQuy(n-1, x);
}

int main()
{
    long long n, x;
    cin >> n >> x;
    cout << roundf(deQuy(n, x)*1000)/1000;
}