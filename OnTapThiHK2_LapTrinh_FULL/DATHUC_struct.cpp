#include <iostream>
using namespace std;

struct DaThuc
{
    int a, b;
};

istream &operator >> (istream &is, DaThuc &d)
{
    is >> d.a >> d.b;
    return is;
}

ostream &operator << (ostream &os, DaThuc d)
{
    os << d.a << "x" << "+" << d.b;
    return os;
}

DaThuc operator + (DaThuc d1, DaThuc d2)
{
    DaThuc rs;
    rs.a = d1.a + d2.a;
    rs.b = d1.b + d2.b;
    return rs;
}

int tinhGiaTri(DaThuc d, int x)
{
    return d.a*x + d.b;
}

bool operator == (DaThuc d1, DaThuc d2)
{
    return (d1.a + d1.b) == (d2.a + d2.b);
}

bool operator != (DaThuc d1, DaThuc d2)
{
    return !(d1 == d2);
}

int main()
{
    DaThuc d1, d2;
    int x;
    cin >> d1 >> d2 >> x;
    cout << d1 << '\n' << d2 << '\n';
    cout << d1 << "+" << d2 << "=" << d1+d2 << '\n';
    cout << tinhGiaTri(d1, x) << '\n';
    cout << tinhGiaTri(d2, x) << '\n';
    if (d1 == d2)
    {
        cout << "TRUE";
        return 0;
    }
    cout << "FALSE";
    return 0;
}