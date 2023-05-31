#include <iostream>
#include <string>
using namespace std;

struct PhanSo {
    int a, b;
};

struct HonSo {
    int a;
    PhanSo p;
};

istream& operator>>(istream& is, PhanSo& p) {
    is >> p.a >> p.b;
    return is;
}

ostream& operator<<(ostream& os, const PhanSo& p) {
    os << p.a << "/" << p.b;
    return os;
}

bool operator!=(const PhanSo& p1, const PhanSo& p2) {
    return (p1.a != p2.a || p1.b != p2.b);
}

istream& operator>>(istream& is, HonSo& s) {
    is >> s.a >> s.p;
    return is;
}

ostream& operator<<(ostream& os, const HonSo& s) {
    os << s.a << " " << s.p;
    return os;
}

int ucln(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    if (a > 0) {
        return a;
    }
    return b;
}

PhanSo rutGonPhanSo(const PhanSo& p) {
    PhanSo rs = p;
    int k = ucln(rs.a, rs.b);
    rs.a /= k;
    rs.b /= k;
    return rs;
}

HonSo rutGonHonSo(const HonSo& s) {
    HonSo rs = s;
    rs.p = rutGonPhanSo(rs.p);
    rs.a += rs.p.a / rs.p.b;
    rs.p.a %= rs.p.b;
    rs.p = rutGonPhanSo(rs.p);  // Tối giản kết quả của phần số trong hỗn số
    return rs;
}

PhanSo chuyenDoiHonSo(const HonSo& s) {
    PhanSo rs;
    rs.a = s.a * s.p.b + s.p.a;
    rs.b = s.p.b;
    rs = rutGonPhanSo(rs);  // Tối giản kết quả của phân số trong hỗn số
    return rs;
}

bool operator!=(const HonSo& s1, const HonSo& s2) {
    return (s1.a != s2.a || s1.p != s2.p);
}

int tongCacThanhPhan(const HonSo& s) {
    return s.a + s.p.a + s.p.b;
}

bool operator>(const HonSo& s1, const HonSo& s2) {
    return tongCacThanhPhan(s1) > tongCacThanhPhan(s2);
}

int main() {
    HonSo s1, s2;
    string choices;
    cin >> s1 >> s2 >> choices;

    if (s1 != s2) {
        cout << "TRUE" << '\n';
    }
    else {
        cout << "FALSE" << '\n';
    }

    if (s1 > s2) {
        cout << "TRUE" << '\n';
    }
    else {
        cout << "FALSE" << '\n';
    }

    if (choices == "true") {
        cout << rutGonHonSo(s1) << '\n';
        cout << rutGonHonSo(s2) << '\n';
    }
    else {
        cout << chuyenDoiHonSo(s1) << '\n';
        cout << chuyenDoiHonSo(s2) << '\n';
    }

    return 0;
}
