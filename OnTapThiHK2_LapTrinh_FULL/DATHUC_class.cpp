#include <iostream>
using namespace std;

class DaThuc
{
    int a, b;
    public:
        DaThuc(int a = 0, int b = 0);
        ~DaThuc();
        int getA();
        int getB();
        void setA(int a);
        void setB(int b);
        friend istream &operator >> (istream &is, DaThuc &d);
        friend ostream &operator << (ostream &os, DaThuc d);
        friend DaThuc operator + (DaThuc d1, DaThuc d2);
        friend int tinhGiaTri(DaThuc d, int x);
        friend bool operator == (DaThuc d1, DaThuc d2);
        friend bool operator != (DaThuc d1, DaThuc d2);
};

DaThuc::DaThuc(int a, int b)
{
    this->a = a;
    this->b = b;
}

DaThuc::~DaThuc()
{}

int DaThuc::getA()
{
    return this->a;
}

int DaThuc::getB()
{
    return this->b;
}

void DaThuc::setA(int a)
{
    this->a = a;
}

void DaThuc::setB(int b)
{
    this->b = b;
}

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