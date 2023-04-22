#include <iostream>
using namespace std;

class PhanSo {
    int tu, mau;
    public:
        //Hàm khởi tạo - huỷ
        PhanSo(int tu = 0, int mau = 1); 
        PhanSo(const PhanSo &p);
        ~PhanSo();
        //Hàm get-set
        int getTu();
        int getMau();
        void setTu(int tu);
        void setMau(int mau);
        //quá tải nhập xuất
        friend istream &operator >> (istream &is, PhanSo &p);
        friend ostream &operator << (ostream &os, PhanSo p);
        friend bool operator == (PhanSo p1, PhanSo p2);
        friend bool operator != (PhanSo p1, PhanSo p2);
        friend PhanSo operator + (PhanSo p1, PhanSo p2); 
};

class MangPhanSo {
    int n;
    PhanSo p[1000];
    public:
        //Hàm get-set
        int getN();
        void setN(int n);
        //Hàm khởi tạo - huỷ
        MangPhanSo(int n = 0, PhanSo p[] = new PhanSo());
        MangPhanSo(const MangPhanSo &m);
        ~MangPhanSo();
        //Quá tải nhập xuất
        friend istream &operator >> (istream &is, MangPhanSo &m);
        friend ostream &operator << (ostream &os, MangPhanSo m);
        PhanSo &operator[](int i);
};

// Phân Số

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}

PhanSo::PhanSo(const PhanSo &p) {
    this->tu = p.tu;
    this->mau = p.mau;
}

PhanSo::~PhanSo() {}

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

istream &operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream &operator << (ostream &os, PhanSo p) {
    os << p.tu << "/" << p.mau;
    return os;
}

bool operator == (PhanSo p1, PhanSo p2) {
    return (float)p1.tu / p1.mau == (float)p2.tu / p2.mau;
}

bool operator != (PhanSo p1, PhanSo p2) {
    return !(p1 == p2);
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
    else
    {
        return b;
    }
}

PhanSo operator + (PhanSo p1, PhanSo p2) {
    PhanSo rs;
    rs.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    rs.mau = p1.mau * p2.mau;
    int k = ucln(rs.tu, rs.mau);
    rs.tu = rs.tu / k;
    rs.mau = rs.mau / k;
    return rs;
}

// Mảng
MangPhanSo::MangPhanSo(int n, PhanSo p[]) {
    this->n = n;
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] = p[i];
    }
}

MangPhanSo::MangPhanSo(const MangPhanSo &m) {
    this->n = m.n;
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] = m.p[i];
    }
}

MangPhanSo::~MangPhanSo() {}

int MangPhanSo::getN() {
    return this->n;
}

void MangPhanSo::setN(int n) {
    this->n = n;
}

istream &operator >> (istream &is, MangPhanSo &m) {
    m.n = 0; // số lượng phần tử
    while (is >> m.p[m.n]) // nhập phần tử của mảng ở vị trị thứ m.n
    {
        m.n++;
    }
    return is;    
}

ostream &operator << (ostream &os, MangPhanSo m) {
    PhanSo rs; // tạo 1 biến kết quả mang kiểu dữ liệu PhanSo
    rs = m.p[0]; // lưu phần tử đầu tiên của mảng vào biến kết quả
    for (size_t i = 1; i < m.n; i++)
    {
        rs = rs + m.p[i]; // p1 + p2
    }
    os << rs;
    return os;
}

PhanSo &MangPhanSo::operator[](int i) {
    return this->p[i]; 
}

int main() {
    MangPhanSo m;
    cin >> m;
    cout << m;
}