#include <iostream>
using namespace std;

long long demSoLuongChuSo(long long n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1 + demSoLuongChuSo(n/10);
}

int main()
{
    long long n;
    cin >> n;
    cout << demSoLuongChuSo(n);
    system("Pause");
}