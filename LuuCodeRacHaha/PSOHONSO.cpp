#include <iostream>
#include <cstring>
using namespace std;


struct PhanSo {
    int a, b;
    public:
        friend int rutGonPhanSo(PhanSo p);
};

struct HonSo {
    int a;
    struct PhanSo p;
    public:
        HonSo rutGonHonSo(HonSo s);
        int tongCacThanhPhan(HonSo s);
        PhanSo chuyenDoiHonSo(HonSo s);
};

istream& operator >> (istream &is, PhanSo &p) {
    is >> p.a >> p.b;
    return is;
}

ostream& operator << (ostream &os, PhanSo p) {
    os << p.a << "/" << p.b;
    return os;
}

bool operator != (PhanSo p1, PhanSo p2) {
    if (p1.b != p2.b || p1.a != p2.a)
    {
        return true;
    }
    return false; 
}

istream& operator >> (istream &is, HonSo &s) {
    is >> s.a >> s.p;
    return is;
}

ostream& operator << (ostream &os, HonSo s) {
    os << s.a << " " << s.p;
    return os;
}

int ucln(PhanSo p) {
    int a = p.a;
    int b = p.b;
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
    rs.a = p1.a * p2.b + p2.a * p1.b;
    rs.b = p1.b * p2.b;
    int k = ucln(rs);
    rs.a /= k;
    rs.b /= k;
    return rs;
}

HonSo rutgonHonSo(HonSo s) {
    HonSo rs;
    PhanSo p1, p2, p3;
    p1.a = s.a;
    p1.b = 1;
    p2.a = s.p.a;
    p2.b = s.p.b;
    p3 = p1 + p2;
    if ((float)p3.a / p3.b > 0)
    {
        rs.a = p3.a / p3.b;
        rs.p.a = p3.a % p3.b;
        rs.p.b = p3.b;
    }
    else
    {
        rs.a = 0;
        rs.p.a = p3.a;
        rs.p.b = p3.b;
    }
    return rs;
}

PhanSo chuyenDoiHonSo(HonSo s) {
    PhanSo rs;
    PhanSo p1, p2;
    p1.a = s.a;
    p1.b = 1;
    p2.a = s.p.a;
    p2.b = s.p.b;
    rs = p1 + p2;
    return rs;
}

bool operator != (HonSo s1, HonSo s2) {
    if (s1.a != s2.a || s1.p.a != s2.p.a || s1.p.b != s2.p.b)
    {
        return true;
    }
    return false;
}

int tongCacThanhPhan(HonSo s) {
    return s.a + s.p.a + s.p.b;
}

bool operator > (HonSo s1, HonSo s2) {
    return tongCacThanhPhan(s1) > tongCacThanhPhan(s2);
}

int main() {
    HonSo s1, s2;
    string choices;
    cin >> s1 >> s2 >> choices;
    if (s1 != s2)
    { 
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (s1 > s2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (choices == "true")
    {
        cout << rutgonHonSo(s1) << '\n';
        cout << rutgonHonSo(s2) << '\n';
    }
    else
    {
        cout << chuyenDoiHonSo(s1) << '\n';
        cout << chuyenDoiHonSo(s2) << '\n';
    }
    system("Pause");
}