#include <iostream>
using namespace std;

long long luyThua(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    return a*luyThua(a, b-1);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << luyThua(a, b);
    system("Pause");
}