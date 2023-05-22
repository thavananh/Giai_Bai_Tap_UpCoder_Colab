#include <iostream>
using namespace std;

long long deQuy(long long n, long long k)
{
    if (n == k || k == 1)
    {
        return n;
    }
    return deQuy(n-1, k) + deQuy(n-1, k-1);
}

int main()
{
    long long n, k;
    cin >> n >> k;
    cout << deQuy(n, k);
}