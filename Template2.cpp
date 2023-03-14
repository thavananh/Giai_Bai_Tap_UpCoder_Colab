#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
    public:
        int ucln(PhanSo);
};


template <typename T>
struct Mang
{
    int n;
    T array[100];
    T &operator[](int i){
        return array[i];
    }
    public:
        T tinhTong(Mang<T>m);
};

istream& operator >> (istream &input, PhanSo &p) {
    input >> p.tu >> p.mau;
    return input;
}

ostream& operator << (ostream &output, PhanSo p) {
    output << p.tu << "/" << p.mau;
    return output;
}

template <typename T>
istream& operator >> (istream &input, Mang <T> &m) { 
    m.n = 0;
    T x;
    while (input >> x)
    {
        m[m.n] = x;
        m.n++;
    } 
   return input;
}

template <typename T>
ostream& operator << (ostream &output, Mang<T> m) {
    for (size_t i = 0; i < m.n; i++)
    {
        output << m.array[i] << '\n';
    } 
    return output;
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


template <typename T>
T tinhTong (Mang<T>m) {
    T rs = m.array[0];
    for (size_t i = 1; i < m.n; i++)
    {
        rs = rs + m.array[i];
    }
    return rs;
}


int main() {
    int c;
    cin >> c;
    if (c == 'a') {
        Mang<int>m;
        cin >> m;
        cout << tinhTong<int>(m);
    }
    else {
        Mang<PhanSo>m;
        cin >> m;
        cout << tinhTong<PhanSo>(m);
    }

}