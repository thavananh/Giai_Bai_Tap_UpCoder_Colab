#include <iostream>
#include <limits.h>
using namespace std;

long long deQuy(long long n)
{
    if (n <= 1)
    {
        return n;
    }
    long long rs = 0;
        if (n % 2 == 0)
        {
            rs = rs + deQuy(n/2);
        }
        else
        {
            rs = rs + deQuy(n/2) + deQuy(n/2 + 1);
        }
    return rs;
}

int main()
{
    long long n;
    cin >> n;
    long long __max = INT_MIN;
    for (long long i = 0; i <= n; i++)
    {
        if (__max < deQuy(i))
        {
            __max = deQuy(i);
        }
    }
    cout << __max;
}