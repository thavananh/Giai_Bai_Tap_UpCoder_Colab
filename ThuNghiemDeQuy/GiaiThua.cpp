#include <iostream>
using namespace std;

long long giaithua(long long n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * giaithua(n-1);
}

int main()
{
    long long n;
    cin >> n;
    cout << giaithua(n);
    system("Pause");
}