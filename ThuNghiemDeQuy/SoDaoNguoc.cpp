#include <iostream>
using namespace std;

long long soDaoNguoc(long long n, long long sum = 0)
{
    if (n == 0)
    {
        return sum/10;
    }
    sum = ((n % 10) + sum)*10;
    return soDaoNguoc(n/10, sum);
}

int main()
{
    long long n;
    cin >> n;
    cout << soDaoNguoc(n);
    system("Pause");
}