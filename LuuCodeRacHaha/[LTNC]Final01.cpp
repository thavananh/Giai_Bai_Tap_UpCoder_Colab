#include <iostream>
#include <cmath>
using namespace std;

long long deQuyGiaiThua(long long n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * deQuyGiaiThua(n-1);
}

double deQuySin(double x, int n = 5)
{
    if (n == 0)
    {
        return x;
    }
    return pow(-1, n)*((pow(x, 2*n + 1))/deQuyGiaiThua(2*n+1)) + deQuySin(x, n-1);
}

double deQuyCos(double x, int n = 5)
{
    if (n == 0)
    {
        return 1;
    }
    return pow(-1, n)*((pow(x, 2*n))/deQuyGiaiThua(2*n)) + deQuyCos(x, n-1);
}

int main()
{
    double x;
    cin >> x;
    double ketquaSin = deQuySin(x);
    double lamtron = roundf(ketquaSin*1000)/1000;
    cout << lamtron << '\n';
    double ketquaCos = deQuyCos(x);
    lamtron = roundf(ketquaCos*1000)/1000;
    cout << lamtron << '\n';
    system("Pause");
}