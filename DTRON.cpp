#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define pi 3.14

struct Diem {
    int x, y;
    public:
};

struct DTRON {
    Diem tam;
    double r;
    public:
        friend string vitrituongdoi(DTRON dt1, DTRON dt2);
};

// Cấu trúc Điểm
istream &operator >> (istream &is, Diem &d) {
    is >> d.x >> d.y;
    return is;
}

ostream &operator << (ostream &os, Diem d) {
    os << "(" << d.x << "," << d.y << ")";
    return os;
}

double operator - (Diem d1, Diem d2) {
    return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
}

bool operator == (Diem d1, Diem d2) {
    return d1.x == d2.x && d1.y == d2.y;
}

// Cấu trúc DTRON
istream &operator >> (istream &is, DTRON &dt) {
    is >> dt.tam >> dt.r;
    return is;
}

ostream &operator << (ostream &os, DTRON dt) {
    os << dt.tam << " " << dt.r;
    return os;
}

bool operator == (DTRON dt1, DTRON dt2) {
    return dt1.r*2*pi == dt2.r*2*pi;
}

bool operator < (DTRON dt1, DTRON dt2) {
    return dt1.r*2*pi < dt2.r*2*pi;
}

double operator + (DTRON dt1, DTRON dt2) {
    return pi*pow(dt1.r, 2) + pi*pow(dt2.r, 2);
}

string vitrituongdoi(DTRON dt1, DTRON dt2) {
    string rs;
    double khoang_cach_tam = dt1.tam - dt2.tam;
    double R_Tru__R = abs(dt1.r - dt2.r);
    double R_Cong__R = dt1.r + dt2.r;
    if (khoang_cach_tam > R_Tru__R && khoang_cach_tam < R_Cong__R)
    {
        rs = "C";
    }
    else if (khoang_cach_tam == R_Tru__R)
    {
        rs = "TXT";
    }
    else if (khoang_cach_tam == R_Cong__R)
    {
        rs = "TXN";
    }
    else if (khoang_cach_tam > R_Cong__R)
    {
        rs = "NN";
    }
    else if (khoang_cach_tam < R_Tru__R)
    {
        rs = "DN";
    }
    else if (khoang_cach_tam == 0)
    {
        rs = "DT";
    }
    return rs;
}
 
int main() {
    DTRON dt1, dt2;
    cin >> dt1 >> dt2;
    cout << dt1 << '\n';
    cout << dt2 << '\n';
    double kq = dt1 + dt2;
    double rounded_n = roundf(kq * 1000) / 1000;
    cout << rounded_n << '\n';
    if (dt1 == dt2)
    {
        cout << "1 == 2" << '\n';
    }
    else if (dt1 < dt2)
    {
        cout << "1 < 2" << '\n';
    }   
    else
    {
        cout << "1 > 2" << '\n';
    }
    cout << vitrituongdoi(dt1, dt2);
}