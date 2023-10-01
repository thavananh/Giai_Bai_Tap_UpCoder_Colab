#include <iostream>
using namespace std;

struct HCN
{
    int chieudai, chieurong;
    public:
        int chuVi(HCN a);
};

template<typename T>
struct Mang
{
    int n = 0;
    T array[1000];
    T &operator[](int i) {
        return array[i];
    }
    public:
        T tinhTong(Mang<T>m);
};

istream &operator >> (istream &is, HCN &a) {
    is >> a.chieudai >> a.chieurong;
    return is;
}

ostream &operator << (ostream &os, HCN a) {
    os << "[HCN]" << " " << a.chieudai << "," << a.chieurong;
    return os;
}

template<typename T>
ostream &operator << (ostream &os, Mang<T>m) {
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.array[i] << '\n';
    }
    return os;
}

int chuVi(HCN a) {
    return (a.chieudai + a.chieurong)*2;
}

bool operator < (HCN hc_1, HCN hc_2) {
    return chuVi(hc_1) < chuVi(hc_2);
}

HCN operator + (HCN a, HCN b) {
    HCN rs;
    rs.chieudai = a.chieudai + b.chieudai;
    rs.chieurong = a.chieurong + b.chieurong;
    return rs;
}

template<typename T>
T timMin(Mang<T>m) {
    T rs = m.array[0];
    for (size_t i = 1; i < m.n; i++)
    {
        if (m.array[i] < rs)
        {
            rs = m.array[i];
        }
    }
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
    char c;
    Mang<int>m1;
    Mang<HCN>m2;
    while (cin >> c)
    {
        if (c == 'N')
        {
            cin >> m1.array[m1.n];
            m1.n++;
        }
        else
        {
            cin >> m2.array[m2.n];
            m2.n++;
        }
    }
    cout << m1 << '\n';
    cout << m2 << '\n';
}