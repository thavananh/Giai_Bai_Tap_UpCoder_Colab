#include <iostream>
using namespace std;

short int chuSoCuoi(long long n)
{
    if (n / 10 == 0)
    {
        return n;
    }
    return chuSoCuoi(n/10);
}

int main()
{
    long long n;
    cin >> n;
    cout << chuSoCuoi(n);
    system("pause");
}