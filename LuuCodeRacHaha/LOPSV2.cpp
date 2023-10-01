#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Diem {
    float a[100];
    int n;
    public:
    void setN(int n);
    int getN();
    float& operator[](int i) {
        return a[i];
    }
    Diem(int n = 1, float a[] = new float{1});
    Diem(const Diem &d);
    ~Diem();
    friend istream& operator >> (istream &is, Diem &d);
    friend ostream& operator << (ostream &os, Diem d);
    float getDTB();
    void operator = (Diem d) {
        this->n = d.n;
        for (size_t i = 0; i < d.n; i++)
        {
            this->a[i] = d.a[i];
        }
        
    }
};

class SinhVien {
    string hoten, msv;
    Diem d;
    public:
    SinhVien(string hoten = "", string msv = "", Diem d = Diem());
    SinhVien(const SinhVien& sv);
    ~SinhVien();
    friend istream& operator >> (istream &is, SinhVien &sv);
    friend ostream& operator << (ostream &os, SinhVien sv);
};

// Bắt đầu xây dựng hàm cho lớp Điểm
void Diem::setN(int n) {
    this->n = n;
}

int Diem::getN() {
    return this->n;
}

Diem::Diem(int n, float a[]) {
    this->n = n;
    for (size_t i = 0; i < n; i++)
    {
        this->a[i] = a[i];
    }
}

Diem::Diem(const Diem &d) {
    this->n = d.n;
    for (size_t i = 0; i < d.n; i++)
    {
        this->a[i] = d.a[i];
    }
}
Diem::~Diem(){}

istream& operator >> (istream &is, Diem &d) {
    d.n = 0;
    while (is >> d.a[d.n])
    {
       d.n++;
    }
    return is;
}

ostream& operator << (ostream &os, Diem d) {
    for (size_t i = 0; i < d.n; i++)
    {
        os << d.a[i];
    }
    return os;
}

float Diem::getDTB() {
    float sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    return sum / n;
}

// Kết thúc xây dựng hàm cho lớp Diem

// Bắt đầu xây dựng hàm cho lớp SinhVien
SinhVien::SinhVien(string hoten, string msv, Diem d) {
    this->hoten = hoten;
    this->msv = msv;
    this->d = d;
}

SinhVien::SinhVien(const SinhVien &sv) {
    this->hoten = sv.hoten;
    this->msv = sv.msv;
    this->d = sv.d;
}

SinhVien::~SinhVien(){}

istream& operator >> (istream &is, SinhVien &sv) {
    getline(is, sv.hoten);
    is >> sv.msv;
    is >> sv.d;
    return is;
}

ostream& operator << (ostream &os, SinhVien sv) {
    os << sv.hoten << '\n';
    os << sv.msv << '\n';
    os << "DTB: " << sv.d.getDTB();
    return os;
}

int main() {
    SinhVien sv;
    cin >> sv;
    cout << sv;
}