#include <iostream>
using namespace std;

long long deQuy(long long n, long long sum = 0)
{
    if (n == 0)
    {
        return sum/10;
    }
    sum = (n%10 + sum)*10;
    return deQuy(n/10, sum);
}

int main()
{
    long long a[10000];
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << deQuy(a[0]);
    // for (size_t i = 0; i < n; i++)
    // {
    //     if (a[i] == deQuy(a[i]))
    //     {
    //         cout << a[i] << "   ";
    //     } 
    // }
}