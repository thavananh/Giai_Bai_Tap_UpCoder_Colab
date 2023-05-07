#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
    char c;
    void operator = (int x) {
        tu = x;
        mau = 1;
    }
    public:
        friend int ucln(PhanSo ps);
};

istream &operator >> (istream &is, PhanSo &ps)
{
    is >> ps.tu >> ps.c >> ps.mau;
    return is;
}

ostream &operator << (ostream &os, PhanSo ps)
{
    int k = ucln(ps);
    ps.tu /= k;
    ps.mau /= k;
    double test = (double)ps.tu / ps.mau;
    int temp = static_cast<int>(test);
    if (test - temp == 0.0)
    {
        os << ps.tu;
    }
    else
    {
        os << ps.tu << "/" << ps.mau;
    }
    return os;
}

bool operator == (PhanSo ps1, PhanSo ps2) 
{
    return (double)ps1.tu / ps1.mau == (double)ps2.tu / ps2.mau;
}

bool operator < (PhanSo ps1, PhanSo ps2)
{
    return (double)ps1.tu / ps1.mau < (double)ps2.tu / ps2.mau;
}

bool operator > (PhanSo ps1, PhanSo ps2)
{
    return (double)ps1.tu / ps1.mau > (double)ps2.tu / ps2.mau;
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

template <typename T>
struct Mang 
{
    int n;
    T a[1000];
    public:
        template <typename U>
        friend U tongPhanTu (Mang<U>m);
        template <typename A>
        friend A phanTuMax (Mang<A>m);
        template <typename B>
        friend Mang<B> sapXep(Mang<B>m, char option);
};

template <typename T>
istream &operator >> (istream &is, Mang<T>&m)
{
    is >> m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        is >> m.a[i];
    }
    return is;
}

template <typename T>
ostream &operator << (ostream &os, Mang<T>m)
{
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.a[i] << " ";
    }
    return os;
}

template <typename U>
U tongPhanTu (Mang<U>m) 
{
    U rs = m.a[0];
    for (size_t i = 1; i < m.n; i++)
    {
        rs = rs + m.a[i];
    }
    return rs;
}

template <typename U>
U phanTuMax (Mang<U>m)
{
    U _max = m.a[0];
    for (size_t i = 0; i < m.n; i++)
    {
        if (_max < m.a[i])
        {
            _max = m.a[i];
        }
    }
    return _max;
}

template <typename U>
Mang<U> sapXep(Mang<U>m, char option)
{
    U temp;
    if (option == '<')
    {
        for (size_t i = 0; i < m.n - 1; i++)
        {
            for (size_t j = i + 1; j < m.n ; j++)
            {
                if (m.a[i] > m.a[j])
                {
                    temp = m.a[i];
                    m.a[i] = m.a[j];
                    m.a[j] = temp;
                } 
            }
        } 
    }
    else
    {
        for (size_t i = 0; i < m.n - 1; i++)
        {
            for (size_t j = i + 1; j < m.n ; j++)
            {
                if (m.a[i] < m.a[j])
                {
                    temp = m.a[i];
                    m.a[i] = m.a[j];
                    m.a[j] = temp;
                } 
            }
        } 
    }
    return m;
}

template <typename T>
Mang<T> operator + (Mang<T>m1, Mang<T>m2)
{
    Mang<T>rs;
    if (m1.n > m2.n)
    {
        rs.n = m1.n;
        for (size_t i = 0; i < m2.n; i++)
        {
            rs.a[i] = m1.a[i] + m2.a[i];
        }
        rs.a[m1.n - 1] = m1.a[m1.n - 1];
    }
    else
    {
        rs.n = m2.n;
        for (size_t i = 0; i < m1.n; i++)
        {
            rs.a[i] = m1.a[i] + m2.a[i];
        }
        rs.a[m2.n - 1] = m2.a[m2.n-  1];
    }
    return rs;
}

int main() 
{
    char c;
    cin >> c;
    switch (c)
    {
    case 'I':
        Mang<int>m1;
        cin >> m1;
        Mang<int>m2;
        cin >> m2;
        cout << m1 << '\n';
        cout << "MAX 1 = " << phanTuMax<int>(m1) << '\n';
        cout << "SUM 2 = " << tongPhanTu<int>(m1) << '\n';
        Mang<int>m1_le;
        Mang<int>m1_chan;
        
        for (size_t i = 0; i < m1.n; i++)
        {
            if (m1.a[i] % 2 != 0)
            {

                m1_le.a[m1_le.n] = m1.a[i];
                m1_le.n++;
            }
            else
            {
                m1_chan.a[m1_chan.n] = m1.a[i];
                m1_chan.n++;
            }
            
        }
        cout << sapXep<int>(m1_chan, '<');
        cout << sapXep<int>(m1_le, '<');
        cout << '\n';
        cout << m2 << '\n';
        cout << "MAX 2 = " << phanTuMax<int>(m2) << '\n';
        cout << "SUM 2 = " << tongPhanTu<int>(m2) << '\n';
        Mang<int>m2_le;
        Mang<int>m2_chan;
        for (size_t i = 0; i < m2.n; i++)
        {
            if (m2.a[i] % 2 != 0)
            {
                m2_le.a[m2_le.n] = m2.a[i];
                m2_le.n++;
            }
            else
            {
                m2_chan.a[m2_chan.n] = m2.a[i];
                m2_chan.n++;
            }
        }
        cout << sapXep<int>(m2_le, '>');
        cout << sapXep<int>(m2_chan, '>');
        cout << '\n';
        cout << m1 + m2;
        break;
    case 'F':
        Mang<PhanSo>m3;
        cin >> m3;
        Mang<PhanSo>m4;
        cin >> m4;
        cout << m3 << '\n';
        cout << "MAX 1 = " << phanTuMax<PhanSo>(m3) << '\n';
        cout << "SUM 1 = " << tongPhanTu<PhanSo>(m3) << '\n';
        cout << sapXep<PhanSo>(m3, '<') << '\n';
        cout << m4 << '\n';
        cout << "MAX 2 = " << phanTuMax<PhanSo>(m4) << '\n';
        cout << "SUM 2 = " << tongPhanTu<PhanSo>(m4) << '\n';
        cout << sapXep<PhanSo>(m4, '>') << '\n';
        cout << m3 + m4 << '\n';
    default:
        break;
    }
    system("Pause");
}