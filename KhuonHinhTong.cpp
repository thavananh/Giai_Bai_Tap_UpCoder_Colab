//Thanks Tuấn Anh nhiều
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
    int n = 0;
    T array[100];
    T &operator[](int i) {
        return array[i];
    }
    public:
        T tinhTong(Mang<T>m);
};

istream& operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream& operator << (ostream &os, PhanSo p) {
    os << p.tu << "/" << p.mau;
    return os;
}

// template <typename T>
// istream& operator >> (istream &is, Mang<T>&m) {
//     m.n = 0;
//     T x;
//     while (is >> x) 
//     {
//         m[m.n] = x;
//         m.n++;
//     }
//     return is;
// }

template<typename T>
ostream& operator << (ostream &os, Mang<T>m) {
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.array[i];
    }
    return os;
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
    if (a > 0) {
        return a;
    }
    return b;
}

PhanSo operator + (PhanSo p1, PhanSo p2) {
    PhanSo rs;
    rs.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    rs.mau = p1.mau * p2.mau;
    int k = ucln(rs);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}

template<typename T>
T tinhTong(Mang<T>m) {
    T rs = m.array[0];
    for (size_t i = 1; i < m.n; i++)
    {
        rs = rs + m.array[i];
    }
    return rs;
}
int main() {
    char choice;
    Mang<int>m1;
    Mang<PhanSo>m2;
    while (cin >> choice)
    {
        switch (choice)
        {
        case 'a':
            cin >> m1.array[m1.n];
            m1.n++;
            break;
        
        case 'b':
            cin >> m2.array[m2.n];
            m2.n++;
            break;
        }
        
    }
    if (m1.n == 0)
    {
        cout << "khong co" << '\n';
    }
    else
    {
        cout << tinhTong<int>(m1) << '\n';
    }
    if (m2.n == 0)
    {
        cout << "khong co" << '\n';
    }
    else
    {
        cout << tinhTong<PhanSo>(m2) << '\n';
    }
    system("Pause");
}