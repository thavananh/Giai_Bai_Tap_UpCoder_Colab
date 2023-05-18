#include <iostream>
using namespace std;

long long sumTu1DenN(long long n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumTu1DenN(n-1);
}

int main()
{
    long long n;
    cin >> n;
    cout << sumTu1DenN(n);
    system("Pause");
}