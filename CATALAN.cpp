#include <iostream>
using namespace std;

long long deQuy(long long n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    long long res = 0;
    for (size_t i = 0; i < n; i++)
    {
        res += deQuy(i)*deQuy(n-i-1);
    }
    return res;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        cout << deQuy(n);
    }
    
    
}