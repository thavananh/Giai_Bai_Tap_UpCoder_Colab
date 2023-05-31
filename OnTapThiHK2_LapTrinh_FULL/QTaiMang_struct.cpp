#include <iostream>
using namespace std;

struct M1C 
{
    int n;
    int a[1000];
    public:
        void operator = (const M1C &m)
        {
            this->n = m.n;
            for (size_t i = 0; i < m.n; i++)
            {
                this->a[i] = m.a[i];
            }
        }
        int &operator[](int i)
        {
            return this->a[i];
        }
};

istream &operator >> (istream &is, M1C &m)
{
    is >> m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        cin >> m.a[i];
    }
    return is;
}

ostream &operator << (ostream &os, M1C m)
{
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.a[i] << " ";
    }
    return os;
}

M1C operator + (M1C m1, M1C m2)
{
    M1C rs;
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

bool operator == (M1C m1, M1C m2)
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

bool operator != (M1C m1, M1C m2)
{
    return !(m1 == m2);
}

int main()
{
    M1C m1, m2;
    cin >> m1 >> m2;
    if (m1 == m2)
    {
        cout << "yes";
        return 0;
    }
    cout << "no";
    return 0;
}