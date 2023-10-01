#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Diem {
    int n;
    float a[100];
    public:
        //Hàm khởi tạo - hàm hủy
        Diem(int n = 1, float* a = nullptr);
        Diem(const Diem &d);
        ~Diem();
        //Hàm get - set
        int getN();
        void setN(int n);
        float getTBC();
        //Quá tải toán tử nhập - xuất >> <<, quá tải toán tử lấy giá trị mảng[], quá tải toán tử gán =
        friend istream& operator >> (istream &is, Diem &d);
        friend ostream& operator << (ostream &os, Diem d);
        float& operator[](int i) {
            return a[i];
        } 
        void operator = (Diem d) {
            n = d.n;
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
        //Hàm khởi tạo - hủy
        SinhVien(string hoten = "", string msv = "", Diem d = Diem());
        SinhVien(const SinhVien &sv);
        ~SinhVien();
        //Hàm get - set
        string getHoTen();
        string getMSV();
        Diem getDiem();
        void setHoTen(string hoten);
        void setMSV(string msv);
        void setDiem(Diem d);
        //Quá tải toán tử nhập - xuất >> <<
        friend istream& operator >> (istream &is, SinhVien &sv);
        friend ostream& operator << (ostream &os, SinhVien sv);
        bool operator < (SinhVien sv);
};

class MangSinhVien {
    int soluongsinhvien;
    SinhVien sv[100];
    public:
        //Hàm khởi tạo - hủy
        MangSinhVien(int n = 1, SinhVien* sv = nullptr);
        MangSinhVien(const MangSinhVien &sv);
        //Hàm get - set, hàm trung bình cộng
        int getN();
        void setN(int n);
        //Quá tải toán tử nhập - xuất >> <<, quá tải toán tử lấy giá mảng[], quá tải toán tử  =
        friend istream& operator >> (istream &is, MangSinhVien &m);
        friend ostream& operator << (ostream &os, MangSinhVien m);
        SinhVien& operator[](int i) {
            return sv[i];
        }
        void operator = (MangSinhVien m) {
            soluongsinhvien = m.soluongsinhvien;
            for (size_t i = 0; i < m.soluongsinhvien; i++)
            {
                this->sv[i] = m.sv[i];
            }   
        }
};

//Bắt đầu xây dựng hàm Diem
Diem::Diem(int n, float* a) {
    if (a == nullptr) {
        this->n = 1;
        this->a[0] = 1;
    } else {
        this->n = n;
        for (size_t i = 0; i < n; i++) {
            this->a[i] = a[i];
        }
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


int Diem::getN() {
    return this->n;
}

void Diem::setN(int n) {
    this->n = n;
}

float Diem::getTBC() {
    float sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    return sum / n;
}

istream& operator >> (istream &is, Diem &d) {
    d.n = 0;
    while (is >> d.a[d.n]) {
        d.n++;
    }
    return is;
}

ostream& operator << (ostream &os, Diem d) {
    for (size_t i = 0; i < d.n; i++)
    {
        os << d.a[i] << " ";
    }
    return os;
}
//Kết thúc xây dựng hàm lớp Diem

//Bắt đầu xây dựng hàm lớp SinhVien
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

string SinhVien::getHoTen() {
    return this->hoten;
}

string SinhVien::getMSV() {
    return this->msv;
}

Diem SinhVien::getDiem() {
    return this->d;
}

void SinhVien::setHoTen(string hoten) {
    this->hoten = hoten;
}

void SinhVien::setMSV(string msv) {
    this->msv = msv;
}

void SinhVien::setDiem(Diem d) {
    this->d = d;
}

istream& operator >> (istream &is, SinhVien &sv) {
    cin.ignore();
    cin.clear();
    getline(is, sv.hoten);
    is >> sv.msv;
    is >> sv.d;
    return is;
}

ostream& operator << (ostream &os, SinhVien sv) {
    os << "Ho Ten: " << sv.hoten << '\n';
    os << "Ma Sinh Vien: " << sv.msv << '\n';
    os << "DTB: " << fixed << setprecision(1) << sv.d.getTBC();
    return os;
}

bool SinhVien::operator < (SinhVien sv) {
    return this->d.getTBC() < sv.d.getTBC();
}

//Kết thúc xây dựng hàm của lớp SinhVien

//Bắt đầu xây dựng hàm của lớp MangSinhVien
MangSinhVien::MangSinhVien(int n, SinhVien* sv) {
    if (sv == nullptr) {
        this->soluongsinhvien = 1;
        this->sv[0] = SinhVien();
    } else {
        this->soluongsinhvien = n;
        for (size_t i = 0; i < n; i++) {
            this->sv[i] = sv[i];
        }
    }
}

MangSinhVien::MangSinhVien(const MangSinhVien &m) {
    this->soluongsinhvien = m.soluongsinhvien;
    for (size_t i = 0; i < m.soluongsinhvien; i++)
    {
        this->sv[i] = m.sv[i];
    }
}

istream& operator >> (istream &is, MangSinhVien &m) {
    is >> m.soluongsinhvien;
    for (size_t i = 0; i < m.soluongsinhvien; i++)
    {
        is >> m.sv[i];
    }
    return is;
}

ostream& operator << (ostream &os, MangSinhVien m) {
    SinhVien temp = m.sv[0];
    for (size_t i = 1; i < m.soluongsinhvien; i++)
    {
        if (temp < m.sv[i]) {
            temp = m.sv[i];
        }
    }
    os << temp;
    return os;
}

//Kết thúc xây dựng hàm của lớp MangSinhVien

int main() {
    MangSinhVien m;
    cin >> m;
    cout << m;

}