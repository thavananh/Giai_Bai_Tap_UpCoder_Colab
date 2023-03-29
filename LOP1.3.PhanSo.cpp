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

PhanSo::~PhanSo()
{
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

PhanSo PhanSo::operator+ (PhanSo ps) {
    PhanSo rs;
    rs.tu = this->tu * ps.mau + ps.tu * this->mau;
    rs.mau = this->mau * ps.mau;
    return rs;
}
// test merge 123123123123
int main() {

}