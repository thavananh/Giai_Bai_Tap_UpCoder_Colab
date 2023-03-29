#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo();
    PhanSo(int tu, int mau = 1);
    PhanSo(const PhanSo &ps);   
    friend istream &operator >> (istream &is, PhanSo &ps);
    friend ostream &operator << (ostream &os, PhanSo ps);
    int getTu();
    int getMau();
    void setTu(int tu);
    void setMau(int mau);
    PhanSo nghichdao();
    PhanSo rutgon();
    int ucln(PhanSo ps);
    PhanSo operator + (PhanSo ps);
    PhanSo operator - (PhanSo ps);
    PhanSo operator / (PhanSo ps);
    ~PhanSo();
};

PhanSo::PhanSo() { // khởi tạo không có giá trị truyền vào
    this->tu = 0;
    this->mau = 1;
}

PhanSo::PhanSo(int tu, int mau) // khởi tạo với tử và mẫu cho trước
{
    this->tu = tu;
    this->mau = mau;
}

PhanSo::PhanSo(const PhanSo &ps) {
    this->tu = ps.tu;
    this->mau = ps.mau;
}

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

void PhanSo::setMau(int mau) {
    this->mau = mau;
}

void PhanSo::setTu(int tu) {
    this->tu = tu;
}

int PhanSo::ucln(PhanSo ps) {
    int a = ps.tu;
    int b = ps.mau;
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

PhanSo PhanSo::operator+ (PhanSo ps) {
    PhanSo rs;
    rs.tu = this->tu * ps.mau + ps.tu * this->mau;
    rs.mau = this->mau * ps.mau;
    int k = ucln(rs);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}

PhanSo PhanSo::nghichdao() {
    PhanSo rs;
    rs.tu = this->mau;
    rs.mau = this->tu;
    return rs;
}

PhanSo PhanSo::rutgon() {
    PhanSo rs;
    rs.tu = this->tu;
    rs.mau = this->mau;
    int k = ucln(rs);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}


int main() {
    PhanSo ps1;
    cin >> ps1;
    cout << ps1 << '\n';
    cout << ps1.getTu() << '\n';
    cout << ps1.getMau() << '\n';
    cout << ps1.nghichdao() << '\n';
    cout << ps1.rutgon() << '\n';
    cout << ps1 + ps1.nghichdao() << '\n';
}   