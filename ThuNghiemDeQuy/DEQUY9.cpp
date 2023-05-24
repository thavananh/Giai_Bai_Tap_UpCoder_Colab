#include <iostream>
using namespace std;

long long giaiThua(long long n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * giaiThua(n-1);
}

long long deQuyTong(long long n)
{
    if (n == 1)
    {
        return n;
    }
    return n + deQuyTong(n);
}

long long deQuyS(long long n)
{
    if (n == 1)
    {
        return 1;
    }
    return deQuyTong(n) + deQuyS(n-1);
}

long long deQuyP(long long n)
{
    if (n==1)
    {
        return 1;
    }
    return giaiThua(n) + deQuyP(n-1);
}


int main()
{
    long long n;
    cin >> n;
    cout << "S" << "(" << n << ")" << " = " << deQuyS(n) << '\n';
    cout << "P" << "(" << n << ")" << " = " << deQuyP(n);
}