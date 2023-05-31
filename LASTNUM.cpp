#include <iostream>
using namespace std;

long long deQuy(long long n, long long rs)
{
    
    if (n == 0)
    {
        return
    }
    
    return deQuy(n/10, sum);
}

int main()
{
    long long n;
    cin >> n;
    cout << deQuy(n);
}