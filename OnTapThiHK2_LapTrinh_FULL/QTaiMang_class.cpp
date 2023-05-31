#include <iostream>
using namespace std;

class Mang
{
    int n;
    int a[1000];
    public:
        Mang(int n = 0, int a[] = {});
        ~Mang();
        int getN();
        void setN(int n);
        friend istream &operator >> (istream &is, Mang &m);
        friend ostream &operator << (ostream &os, Mang m);
        friend Mang operator + (Mang m1, Mang m2);
        friend bool operator == (Mang m1, Mang m2);
        friend bool operator != (Mang m1, Mang m2);
};

Mang::Mang(int n, int a[])
{
    this->n = n;
    for (size_t i = 0; i < n; i++)
    {
        this->a[i] = a[i];
    }
}

Mang::~Mang()
{}

int Mang::getN()
{
    return this->n;
}

void Mang::setN(int n)
{
    this->n = n;
}

istream &operator >> (istream &is, Mang &m)
{
    is >> m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        is >> m.a[i];
    }
    return is;
}

ostream &operator << (ostream &os, Mang m)
{
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.a[i] << " ";
    }
    return os;
}

Mang operator + (Mang m1, Mang m2)
{
    Mang rs;
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

bool operator == (Mang m1, Mang m2)
{
    if (m1.n == m2.n)
    {
        for (size_t i = 0; i < m1.n; i++)
        {
            if (m1.a[i] != m2.a[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator != (Mang m1, Mang m2)
{
    return !(m1 == m2);
}

int main()
{
    Mang m1, m2;
    cin >> m1 >> m2;
    if (m1 == m2)
    {
        cout << "yes";
        return 0;
    }
    cout << "no";
    return 0;
}