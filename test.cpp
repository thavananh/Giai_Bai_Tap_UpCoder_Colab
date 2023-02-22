#include <iostream>
using namespace std;
struct PhanSo {
    int tu, mau;
};
PhanSo operator&= (PhanSo a, PhanSo b);

int main() {
    PhanSo p1, p2, p3;
    p1.tu = 1;
    p1.mau = 2;
    p2.tu = 1;
    p2.mau = 3;
    p3 = p1 = p2;
}

PhanSo operator&= (PhanSo a, PhanSo b) {
    PhanSo rs;
    if (a.tu == b.tu && a.mau == b.mau)
    {
        rs = 1;
    }
    return rs;
}
