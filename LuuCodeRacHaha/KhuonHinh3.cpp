#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
};


template<typename T>
struct Mang
{
    int n = 0;
    T array[100];
    T &operator[](int i) {
        return array[i];
    }
    public:
        T timmin(Mang<T>m);
};

istream& operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream& operator << (ostream &os, PhanSo p) {
    os << p.tu << "/" << p.mau;
    return os;
}

bool operator < (PhanSo p1, PhanSo p2) {
    return ((float)p1.tu / p1.mau) / ((float)p2.tu / p2.mau); 
}

template<typename T>
ostream& operator << (ostream &os, Mang<T>m) {
    for (size_t i = 0; i < m.n; i++)
    {
        os >> m.array[i];
    }
}

template<typename T>
T timmin(Mang<T>m) {
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


int main() {
    char choice;
    Mang<int>m1;
    Mang<float>m2;
    Mang<PhanSo>m3;
    while (cin >> choice)
    {
        if (choice == 'a')
        {
            cin >> m1.array[m1.n];
            m1.n++;
        }
        else if (choice == 'b') {
            cin >> m2.array[m2.n];
            m2.n++;
        }
        else
        {
            cin >> m3.array[m3.n];
            m3.n++;
        }   
    }
    if (m1.n == 0)
    {
        cout << "khong co" << '\n';
    }
    else
    {
        cout << timmin<int>(m1) << '\n';
    }
    if (m2.n == 0)
    {
        cout << "khong co" << '\n';
    }
    else
    {
        cout << timmin<float>(m2) << '\n';
    }
    if (m3.n == 0)
    {
        cout << "khong co" << '\n';
    }
    else
    {
        cout << timmin<PhanSo>(m3) << '\n';
    }
}