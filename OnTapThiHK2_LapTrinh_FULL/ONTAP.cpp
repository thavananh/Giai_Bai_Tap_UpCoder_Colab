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

int ucln(PhanSo ps)
{
    int a = ps.tu;
    int b = ps.mau;
    while (a != 0 && b!= 0)
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

ostream &operator << (ostream &os, PhanSo ps)
{
    int k = ucln(ps);
    ps.tu /= k;
    ps.mau /= k;
    double test = (double)ps.tu / ps.mau;
    int temp = (int)test;
    if (test - temp == 0)
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
    return (double)ps1.tu/ps1.mau == (double)ps2.tu/ps2.mau;
}

bool operator < (PhanSo ps1, PhanSo ps2)
{
    return (double)ps1.tu/ps1.mau < (double)ps2.tu/ps2.mau;
}

bool operator > (PhanSo ps1, PhanSo ps2)
{
    return !(ps1 < ps2);
}

PhanSo operator + (PhanSo ps1, PhanSo ps2)
{
    PhanSo rs;
    rs.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
    rs.mau = ps1.mau*ps2.mau;
    int k = ucln(rs);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}

template <typename T>
struct Mang
{
    int n;
    T a[1000];
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
    os << m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.a[i] << " ";
    }
    return os;
}

template <typename T>
T tongPhanTu(Mang<T>m)
{
    T rs = m.a[0];
    for (size_t i = 1; i < m.n; i++)
    {
        rs = rs + m.a[i];
    }
    return rs;
}

template<typename T>
T phanTuMax (Mang<T>m)
{
    T _max = m.a[0];
    for (size_t i = 0; i < m.n; i++)
    {
        if (_max < m.a[i])
        {
            _max = m.a[i];
        }
    }
    return _max;
}

template <typename T>
Mang<T> sapXep(Mang<T>m, char option)
{
    T temp;
    if (option == '<')
    {
        for (size_t i = 0; i < m.n - 1; i++)
        {
            for (size_t j = i+1; j < m.n; j++)
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
            for (size_t j = 0; j < count; j++)
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
        for (size_t i = m2.n; i < m1.n; i++)
        {
            rs.a[i] = m1.a[i];
        }
    }
    else
    {
        rs.n = m2.n;
        for (size_t i = 0; i < m1.n; i++)
        {
            rs.a[i] = m1.a[i] + m2.a[i];
        }
        for (size_t i = m1.n; i < m2.n; i++)
        {
            rs.a[i] = m2.a[i];
        }  
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
        Mang<int>m1, m2;
        cin >> m1 >> m2;
        cout << m1 << '\n';
        cout << "MAX 1 = " << phanTuMax<int>(m1) << '\n';
        cout << "SUM 1 = " << tongPhanTu<int>(m1) << '\n';
        Mang<int>m1_le, m1_chan;
        for (size_t i = 0; i < m1.n; i++)
        {
            m1_le.n = 0;
            m1_chan.n = 0;
            if (m1.a[i] % 2 != 0)
            {
                m1_le.a[m1_le.n++] = m1.a[i];
            }
            else
            {
                m1_chan.a[m1_chan.n++] = m1.a[i];

            }
            
        }
        
        break;
    
    default:
        break;
    }
}