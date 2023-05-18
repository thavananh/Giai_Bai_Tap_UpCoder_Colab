#include <iostream>
using namespace std;

long long tinhTongMang(long long n, long long a[])
{
    if (n == 0)
    {
        return a[0];
    }
    return a[n] + tinhTongMang(n-1, a);
}

int main()
{
    long long n;
    long long a[10000];
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << tinhTongMang(n, a);
    system("Pause");
}