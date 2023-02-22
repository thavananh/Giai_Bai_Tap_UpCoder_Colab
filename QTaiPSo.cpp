#include <iostream>
using namespace std;
struct PhanSo {
    int mau, tu;
};
istream& operator >> (istream &input, PhanSo& p) {
    input >> p.tu; input >> p.mau;
    return input;
}
ostream& operator << (ostream &output, PhanSo p) {
    output << p.tu << " " << p.mau << endl;
    return output;
}
PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo rs;
    rs.tu = a.tu * b.mau + b.tu * a.mau;
    rs.mau = a.mau * b.mau;
    return rs;
}
PhanSo operator - (PhanSo a, PhanSo b) {
    PhanSo rs;
    rs.tu = a.tu * b.mau - b.tu * a.mau;
    rs.mau = a.mau * b.mau;
    return rs;
}
bool operator == (PhanSo a, PhanSo b) {
    if (a.mau == b.mau && a.tu == b.tu)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator != (PhanSo a, PhanSo b) {
    if (a.mau != b.mau){
        return true;
    }
    else {
        return false;
    }
}

int ucln(PhanSo x) {
    int a = x.tu;
    int b = x.mau;
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

int main() {
    PhanSo p1, p2, p3, p4;
    cin >> p1 >> p2;
    cout << p1 << p2;
    p3 = p1 + p2;
    p4 = p1 - p2;
    int k = ucln(p3);
    int a = p3.tu / k;
    int b = p3.mau / k;
    cout << a << "/" << b;
    system("Pause");
}