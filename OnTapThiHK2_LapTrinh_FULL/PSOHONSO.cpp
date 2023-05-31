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

int ucln(int a, int b)
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
    rs.mau = ps1.mau * ps2.mau;
    int k = ucln(rs.tu, rs.mau);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}

bool operator != (PhanSo ps1, PhanSo ps2)
{
    return ps1.tu != ps2.tu && ps1.mau != ps2.mau;
}

struct HonSo
{
    int a;
    PhanSo ps;
};

istream &operator >> (istream &is, HonSo &hs)
{
    is >> hs.a >> hs.ps;
    return is;
}

ostream &operator << (ostream &os, HonSo hs)
{
    os << hs.a << " " << hs.ps;
    return os;
}

HonSo rutGonHonSo(HonSo hs)
{
    HonSo rs;
    PhanSo p1, p2, p3;
    p1.tu = hs.a;
    p1.mau = 1;
    p2.tu = hs.ps.tu;
    p2.mau = hs.ps.mau;
    p3 = p1 + p2;
    if ((double)p3.tu / p3.mau)
    {
        rs.a = p3.tu / p3.mau;
        rs.ps.tu = p3.tu % p3.mau;
        rs.ps.mau = p3.mau;
    }
    else
    {
        rs.a = 0;
        rs.ps.tu = p3.tu;
        rs.ps.mau = p3.mau;
    }
    return rs;
}

PhanSo chuyenDoiPhanSo(HonSo hs)
{
    PhanSo rs;
    PhanSo ps1, ps2;
    ps1.tu = hs.a;
    ps1.mau = 1;
    ps2.tu = hs.ps.tu;
    ps2.mau = hs.ps.mau;
    rs = ps1 + ps2;
    return rs;
}

int tongCacThanhPhan(HonSo hs)
{
    return hs.a + hs.ps.tu + hs.ps.mau;
}

bool operator != (HonSo hs1, HonSo hs2)
{
    return hs1.a != hs2.a || hs1.ps.tu != hs2.ps.tu || hs1.ps.mau != hs2.ps.mau;
}

bool operator > (HonSo hs1, HonSo hs2)
{
    return tongCacThanhPhan(hs1) > tongCacThanhPhan(hs2);
}

int main()
{
    HonSo hs1, hs2;
    bool flag;
    cin >> hs1 >> hs2 >> flag;
    if (hs1 != hs2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (hs1 > hs2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (flag)
    {
        cout << rutGonHonSo(hs1) << '\n';
        cout << rutGonHonSo(hs2) << '\n';
    }
    else
    {
        cout << chuyenDoiPhanSo(hs1) << '\n';
        cout << chuyenDoiPhanSo(hs2) << '\n';
    }
}