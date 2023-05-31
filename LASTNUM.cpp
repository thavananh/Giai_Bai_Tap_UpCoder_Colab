#include <iostream>
using namespace std;

<<<<<<< HEAD
long long deQuy(long long n, long long rs)
{
    
    if (n == 0)
    {
        return
    }
    
=======
long long deQuy(long long n, long long sum = 0)
{
    if (n == 0)
    {
        return sum;
    }
    sum = sum + n%10;
>>>>>>> 53688cc7325471dc1a188b40a022479a196627d8
    return deQuy(n/10, sum);
}

int main()
{
    long long n;
    cin >> n;
<<<<<<< HEAD
    cout << deQuy(n);
=======
    while (n > 10)
    {
        n = deQuy(n);
    }
    cout << n;
>>>>>>> 53688cc7325471dc1a188b40a022479a196627d8
}