#include <iostream>
#include <cmath>
using namespace std;

class Diem
{
    int a, b;
    public:
        Diem(int a = 0, int b = 0);
        ~Diem();
        int getA();
        int getB();
        void setA(int a);
        void setB(int b);
        friend istream &operator >> (istream &is, Diem &d);
        friend ostream &operator << (ostream &os, Diem d);
        friend double khoangCach(Diem d1, Diem d2);
        friend bool operator == (Diem d1, Diem d2);
};

Diem::Diem(int a, int b)
{
    this->a = a;
    this->b = b;
}

Diem::~Diem()
{}

int Diem::getA()
{
    return this->a;
}

int Diem::getB()
{
    return this->b;
}

void Diem::setA(int a)
{
    this->a = a;
}

void Diem::setB(int b)
{
    this->b = b;
}

class Tgiac
{
    int n = 3;
    Diem d[3];
    public:
        Tgiac(int n = 3, Diem d[] = {});
        ~Tgiac();
        int getN();
        void setN(int n);
        friend istream &operator >> (istream &is, Tgiac &tg);
        friend ostream &operator << (ostream &os, Tgiac tg);
        friend double chuVi(Tgiac tg);
        friend bool operator < (Tgiac tg1, Tgiac tg2);
        friend bool operator == (Tgiac tg1, Tgiac tg2);
};

Tgiac::Tgiac(int n, Diem d[])
{
    this->n = n;
    for (size_t i = 0; i < n; i++)
    {
        this->d[i] = d[i];
    }
}

Tgiac::~Tgiac()
{}

int Tgiac::getN()
{
    return this->n;
}

void Tgiac::setN(int n)
{
    this->n = n;
}

istream &operator >> (istream &is, Diem &d)
{
    is >> d.a >> d.b;
    return is;
}

ostream &operator << (ostream &os, Diem d)
{
    os << "(" << d.a << "," << d.b << ")";
    return os;
}

istream &operator >> (istream &is, Tgiac &tg)
{
    for (size_t i = 0; i < tg.n; i++)
    {
        is >> tg.d[i];
    }
    return is;
}

ostream &operator << (ostream &os, Tgiac tg)
{
    for (size_t i = 0; i < tg.n; i++)
    {
        os << tg.d[i];
    }
    return os;
}

double khoangCach(Diem d1, Diem d2)
{
    return (double)(sqrt(pow(d2.a - d1.a, 2) + pow(d2.b - d1.b, 2)));
}

bool operator == (Diem d1, Diem d2)
{
    return (d1.a == d2.a) && (d1.b == d2.b);
}

double chuVi(Tgiac tg)
{
    double chuvi = 0;
    chuvi = khoangCach(tg.d[0], tg.d[1]) + khoangCach(tg.d[0], tg.d[2]) + khoangCach(tg.d[1], tg.d[2]);
    return chuvi;
}

double operator + (Tgiac tg1, Tgiac tg2)
{
    return chuVi(tg1) + chuVi(tg2);
}

bool operator < (Tgiac tg1, Tgiac tg2)
{
    return chuVi(tg1) < chuVi(tg2);
}

bool operator == (Tgiac tg1, Tgiac tg2)
{
    return chuVi(tg1) == chuVi(tg2) && (tg1.d[0] == tg2.d[0] && tg1.d[1] == tg2.d[1] && tg1.d[2] == tg2.d[2]);
}

int main()
{
    Tgiac tg1, tg2;
    cin >> tg1 >> tg2;
    cout << tg1 << '\n' << tg2 << '\n';
    if (tg1 < tg2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (tg1 == tg2)
    {
        cout << "TRUE";
        return 0;
    }
    cout << "FALSE";
    return 0;
}