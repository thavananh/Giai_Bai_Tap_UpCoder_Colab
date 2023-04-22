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
        friend istream& operator >> (istream &is, PhanSo &ps);
        friend ostream& operator << (ostream &os, PhanSo ps);
        bool operator == (PhanSo ps2);
        bool operator != (PhanSo ps2);
        PhanSo operator + (PhanSo ps2);
};

class MPS {
    int n;
    PhanSo ps[1000];
    public:
        MPS(int n = 0, PhanSo ps[] = new PhanSo());
        MPS(const MPS &m);
        ~MPS();
        friend istream& operator >> (istream &is, MPS &m);
        friend ostream& operator << (ostream &os, MPS m);
        PhanSo& operator[](int i);
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

bool PhanSo::operator == (PhanSo ps2) {
    return (float)this->tu / this->mau == (float)ps2.tu / ps2.mau;
}

bool PhanSo::operator != (PhanSo ps2) {
    return !PhanSo::operator==(ps2);
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

PhanSo PhanSo::operator+(PhanSo ps2) {
    PhanSo rs;
    rs.tu = this->tu * ps2.mau + ps2.tu * this->mau;
    rs.mau = this->mau * ps2.mau;
    int k = ucln(rs.tu, rs.mau);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
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

MPS::MPS(int n, PhanSo ps[]) {
    this->n = n;
    for (size_t i = 0; i < n; i++)
    {
        this->ps[i] = ps[i];
    }
}

MPS::MPS(const MPS &m) {
    this->n = m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        this->ps[i] = m.ps[i];
    }
}

MPS::~MPS() {}

istream& operator >> (istream &is, MPS &m) {
    m.n = 0;
    while (is >> m.ps[m.n])
    {
        m.n++;
    }
    return is;
}

ostream& operator << (ostream &os, MPS m) {
    PhanSo rs = m.ps[0];
    for (size_t i = 1; i < m.n; i++)
    {
        rs = rs + m.ps[i];
    }
    os << rs;
    return os;
}
 
PhanSo &MPS::operator[](int i) {
    return ps[i];
}

int main() {
    MPS m;
    cin >> m;
    cout << m;
}