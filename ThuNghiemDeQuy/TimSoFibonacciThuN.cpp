#include <iostream>
using namespace std;

long long fibonacci(long long n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    long long n;
    cin >> n;
    cout << fibonacci(n);
}