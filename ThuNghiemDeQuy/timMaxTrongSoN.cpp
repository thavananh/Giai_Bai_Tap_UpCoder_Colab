#include <iostream>
#include <limits.h>
using namespace std;

long long timMaxTrongSoN(long long n, long long rs = INT_MIN)
{
    if (n == 0 || rs == 9)
    {
        return rs;
    }
    int k = n % 10;
    if (k > rs)
    {
        rs = k;
    }
    return timMaxTrongSoN(n/10, rs);
}

int main()
{
    long long n;
    cin >> n;
    cout << timMaxTrongSoN(n);
    system("Pause");
}