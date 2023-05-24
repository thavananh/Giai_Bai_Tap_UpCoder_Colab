#include <iostream>
using namespace std;

long long deQuy(long long n, long long sum = 0)
{
    if (n == 0)
    {
        return sum;
    }
    sum = sum + n%10;
    return deQuy(n/10, sum);
}

int main()
{
    long long n;
    cin >> n;
    while (n > 10)
    {
        n = deQuy(n);
    }
    cout << n;
}