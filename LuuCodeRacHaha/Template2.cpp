#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
    public:
        friend int ucln(PhanSo ps);
};

template <typename T>
struct Mang
{
    int n;
    T a[100];
    T &operator[](int i)
    {
        return a[i];
    }
    public:
        template <typename U>
        friend U tinhtong(Mang<U>m);
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

template <typename T>
istream &operator >> (istream &is, Mang<T>&m) 
{
    m.n = 0;
    T x;
    while (is >> x)
    {
        m[m.n] = x;
        m.n++;
    }
    return is;
}

template <typename T>
ostream &operator << (ostream &os, Mang<T>m)
{
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.a[i] << '\n';
    }
    return os;
}

int ucln(PhanSo ps) 
{
    int a = ps.tu;
    int b = ps.mau;
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a > 0)
    {
        return a;
    }
    return b;
}

PhanSo operator + (PhanSo ps1, PhanSo ps2) 
{
    PhanSo rs;
    rs.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    rs.mau = ps1.mau * ps2.mau;
    int k = ucln(rs);
    rs.tu = rs.tu / k;
    rs.mau = rs.mau / k;
    return rs;
}

template <typename U>
U tinhtong (Mang<U>m) 
{
    U rs = m.a[0];
    for (size_t i = 1; i < m.n; i++)
    {
        rs = rs + m.a[i];
    }
    return rs;
}

int main() {
    char c;
    cin >> c;
    switch (c)
    {
    case 'a':
        Mang<int>m;
        cin >> m;
        cout << tinhtong<int>(m);
        break;
    case 'b':
        Mang<PhanSo>m1;
        cin >> m1;
        cout << tinhtong<PhanSo>(m1);
        break;
    default:
        break;
    }
}