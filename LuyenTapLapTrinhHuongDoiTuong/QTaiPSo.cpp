#include <iostream>
using namespace std;

class PhanSo {
    int tu, mau;
    public:
        PhanSo(int tu = 0, int mau = 1);
        PhanSo(const PhanSo &ps);
        ~PhanSo();
        int getTu();
        int getMau();
        void setTu(int tu);
        void setMau(int mau);
        friend istream &operator >> (istream &is, PhanSo &ps);
        friend ostream &operator << (ostream &os, PhanSo ps);
        PhanSo operator + (PhanSo p2);
        bool operator == (PhanSo p2);
        bool operator != (PhanSo p2);
};

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}

PhanSo::PhanSo(const PhanSo &ps) {
    this->tu = ps.tu;
    this->mau = ps.mau;
}

PhanSo::~PhanSo() {}

istream &operator >> (istream &is, PhanSo &ps) {
    is >> ps.tu >> ps.mau;
    return is;
}

ostream &operator << (ostream &os, PhanSo ps) {
    os << ps.tu << "/" << ps.mau;
    return os;
}

int PhanSo::getTu() {
    return this->tu;
}

int PhanSo::getMau() {
    return this->mau;
}

void PhanSo::setTu(int tu) {
    this->tu = tu;
}

void PhanSo::setMau(int mau) {
    this->mau = mau;
}

int ucln(int a, int b) {
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

PhanSo PhanSo::operator + (PhanSo p2) {
    PhanSo rs;
    rs.tu = this->tu * p2.mau + p2.tu * this->mau;
    rs.mau = this->mau * p2.mau;
    int k = ucln(rs.tu, rs.mau);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}

bool PhanSo::operator == (PhanSo p2) {
    return (float)this->tu / this->mau == (float)p2.tu / p2.mau;
}

bool PhanSo::operator!= (PhanSo p2) {
    return !PhanSo::operator==(p2);
}

int main() {
    PhanSo ps1, ps2, ps3;
    cin >> ps1 >> ps2;
    ps3 = ps1 + ps2;
    cout << ps3;
    system("Pause");
}