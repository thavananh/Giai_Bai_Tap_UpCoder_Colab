#include <iostream>

using namespace std;

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo(); // khởi tạo mặc định
    PhanSo(int tu, int mau); // khởi tạo với giá trị tử và mẫu cho trước
    PhanSo(int n); // Khởi tạo với giá trị nguyên cho trước;
    PhanSo(const PhanSo &ps);
    friend istream &operator >> (istream &is, PhanSo &p);
    friend ostream &operator << (ostream &os, PhanSo p);
    int getTu();
    int getMau();
    void setTu(int);
    void setMau(int);
    ~PhanSo();
};

PhanSo::PhanSo()
{
    this->tu = 0;
    this->mau = 1;
}

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}

PhanSo::PhanSo(int n) {
    this->tu = n;
    this->mau = 1;
}

PhanSo::PhanSo(const PhanSo &ps) {
    this->tu = ps.tu;
    this->mau = ps.mau;
}

istream &operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream &operator << (ostream &os, PhanSo p) {
    os << p.tu << "/" << p.mau;
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

int main() {
    PhanSo p1;
}
