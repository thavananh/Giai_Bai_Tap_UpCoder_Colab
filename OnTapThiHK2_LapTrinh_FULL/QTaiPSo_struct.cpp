#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
};

istream &operator >> (istream &is, PhanSo &ps)
{
    is >> ps.tu >> ps.mau;
    return is;
}

ostream &operator << (ostream &os, PhanSo ps)
{
    os << ps.tu << "/" << ps.mau;
    return os;
}

long ucln(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ucln(b, a%b);
}

PhanSo operator + (PhanSo ps1, PhanSo ps2)
{
    PhanSo rs;
    rs.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    rs.mau = ps1.mau*ps2.mau;
    int k = ucln(rs.tu, rs.mau);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}

bool operator == (PhanSo ps1, PhanSo ps2)
{
    return (double)(ps1.tu/ps1.mau) == (double)(ps2.tu/ps2.mau);
}

bool operator != (PhanSo ps1, PhanSo ps2)
{
    return !(ps1 == ps2);
}

int main()
{
    PhanSo ps1, ps2;
    cin >> ps1 >> ps2;
    cout << ps1 + ps2;
}