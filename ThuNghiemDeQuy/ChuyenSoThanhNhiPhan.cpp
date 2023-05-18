#include <iostream>
#include <string>
using namespace std;

string chuyenDoiSoSangNhiPhan(int n, string s = "")
{
    if (n == 0)
    {
        return s;
    }
    char c = '0' + n % 2;
    s = c + s; // nhớ là không được ghi là s + c sẽ bị ngược mà hãy sử dụng c + s để đảo ngược lại
    return chuyenDoiSoSangNhiPhan(n/2, s);
}

int main()
{
    int n;
    cin >> n;
    cout << chuyenDoiSoSangNhiPhan(n);
    system("Pause");
}