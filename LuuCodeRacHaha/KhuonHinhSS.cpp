#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

istream& operator >> (istream &input, PhanSo &p) {
    input >> p.tu >> p.mau;
    return input;
}

ostream& operator << (ostream &output, PhanSo p) {
    output << p.tu << p.mau;
    return output;
}

bool operator == (PhanSo p1, PhanSo p2) {
    return (float)p1.tu/p1.mau == (float)p2.tu/p2.mau;
}

template <typename T>
void nhap() {
    T a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "true";
    }
    else
    cout << "false";
    
}

int main(){
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
    system("Pause");
}