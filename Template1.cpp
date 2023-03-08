#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

istream& operator >> (istream &input, PhanSo &p);
ostream& operator << (ostream &output, PhanSo p);
bool operator > (PhanSo a, PhanSo b);

template <typename T>
void nhap();

template <typename T>
T timmax(T a, T b, T C);

int main() {
    char c;
    cin >> c;
    switch (c)
    {
    case 'a':
        nhap<int>();
        
        break;
    case 'b':
        nhap<float>();
        
        break;
    case 'c':
        nhap<PhanSo>();
        
        break;
    default:
        break;
    }

}

template <typename T>
void nhap() {
    T x, y, z;
    cin >> x >> y >> z;
    cout << timmax<T>(x, y, z);
}

template <typename T>
T timmax(T a, T b, T c) {
    T k = a;
    if (b > k)
    {
        k = b;
    }
    if (c > k)
    {
        k = c;
    }
    return k;
    
}

istream& operator >> (istream &input, PhanSo &p) {
    input >> p.tu >> p.mau;
    return input;
}

ostream& operator << (ostream &output, PhanSo p) {
    output << p.tu << p.mau;
    return output;
}

bool operator > (PhanSo a, PhanSo b) {
    return (float)a.tu / a.mau > (float)b.tu / b.mau;
}

