#include <iostream>
<<<<<<< HEAD

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
=======
using namespace std;

class SinhVien {
    float d[10];
    string ten, msv;
    int n = 0;
    public:
        friend istream &operator >> (istream &is, SinhVien &sv);
        friend ostream &operator << (ostream &os, SinhVien sv);
        int dTB(SinhVien sv);
};

class MangSinhVien {
    int n = 0;
    SinhVien sv[100]; 
    SinhVien &operator[](int i) {
        return sv[i];
    }
    
    public:
        MangSinhVien(int n, SinhVien sv[] = new SinhVien{});
        MangSinhVien(const MangSinhVien &m);
        ~MangSinhVien();
        friend istream &operator >> (istream &is, MangSinhVien &m);
        friend ostream &operator << (ostream &os, MangSinhVien m);
};

istream &operator >> (istream &is, SinhVien &sv) {
    cin.ignore();
    getline(is, sv.ten);
    is >> sv.msv;
    while (is >> sv.d[sv.n])
    {
        sv.n++;
    }
    return is;
}

istream &operator >> (istream &is, MangSinhVien &m) {
    is >> m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        is >> m.sv[i];
    }
    return is;
}

int SinhVien::dTB(SinhVien sv) {
    int rs = 0;
    for (size_t i = 0; i < sv.n; i++)
    {
        rs = rs + d[i];
    }
    return rs / sv.n;
}

ostream &operator << (ostream &os, SinhVien sv) {
    os << sv.ten << '\n';
    os << sv.msv << '\n';
    os << sv.dTB(sv);
    return os;
}

ostream &operator << (ostream &os, MangSinhVien msv) {
    for (size_t i = 0; i < msv.n; i++)
    {
        os << msv.sv[i];
    }
    return os; 
}



int main() {

}
>>>>>>> 586e7e7ff2c649669f75637e6b9dc1cdfde5c316
