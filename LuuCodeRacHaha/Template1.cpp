#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

istream& operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream& operator << (ostream &os, PhanSo p) {
    os << p.tu << "/" << p.mau;
    return os;
}

bool operator < (PhanSo ps1, PhanSo ps2) {
    return ps1.tu / ps1.mau < ps2.tu / ps2.mau;
}

template <typename T>
T timMax(T a, T b, T c) {
    T _max;
    _max = a;
    if (_max < b)
    {
        _max = b;
    }
    if (_max < c) 
    {
        _max = c;
    }
    return _max;
}

template <typename T>
void nhap() {
    T x, y, z;
    cin >> x >> y >> z;
    cout << timMax<T>(x, y, z);
}

int main() {
    char c;
    cin >> c;
    switch (c)
    {
    case 'a':
        nhap<int>();
        break;
    case 'b':
        nhap<double>();
        break;
    case 'c':
        nhap<PhanSo>();
        break;
    default:
        break;
    }
    return 0;
}