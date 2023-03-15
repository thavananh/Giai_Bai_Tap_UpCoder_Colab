#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
    public:
        int ucln(PhanSo);
};

template<typename T>
struct M1C
{
    static int n;
    T array[100];
    T &operator[](int i){
        return array[i];
    }
    M1C(){
        n = 0;
    }
    public:
        T tinhTong(M1C<T>m);
};

istream& operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream& operator << (ostream &os, PhanSo p) {
    os << p.tu << "/" << p.mau;
    return os;
}

template<typename T>
istream& operator >> (istream &is, M1C<T>&m) {
    T x;
    while (is >> x)
    {
        m.array[m.n] = x;
        m.n++;
    }
    return is;
}

template<typename T>
ostream& operator << (ostream &os, M1C<T>m) {
    for (size_t i = 0; i < m.n; i++)
    {
        os >> m.array[i];
    }
    
}

int ucln(PhanSo p) {
    int a = p.tu;
    int b = p.mau;
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

PhanSo operator + (PhanSo p1, PhanSo p2) {
    PhanSo rs;
    rs.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    rs.mau = p1.mau * p2.mau;
    int k = ucln(rs);
    rs.tu = rs.tu / k;
    rs.mau = rs.mau / k;
    return rs;
}

template<typename T>
T tinhTong(M1C<T>m) {
    T rs = m.array[0];
    for (size_t i = 0; i < m.n; i++)
    {
        rs =  rs + m.array[i];
    }
    return rs;
}

int main(){
   char c;
   char k;
   M1C<int>m1;
   M1C<PhanSo>m2;
   while (cin >> c)
   {
        k = c;
        if (k = 'a')
        {
            cin >> m1;
        }
        
   }
    
}