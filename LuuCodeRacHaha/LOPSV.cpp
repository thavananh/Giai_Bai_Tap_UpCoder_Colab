#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class nguoi
{
    string hoten, quequan;
    int namsinh;
    public:
        nguoi(string _hoten = "", string _quequan = "", int _namsinh = 0);
        nguoi(const nguoi &ng);
        ~nguoi();
        friend istream &operator >> (istream &is, nguoi &ng);
        friend ostream &operator << (ostream &os, nguoi ng);
        int getNamSinh();
        string getHoTen();
        string getQueQuan();
        void setNamSinh(int _namsinh);
        void setHoTen(string _hoten);
        void setQueQuan(string _quequan);
        void setAll(int _namsinh, string _hoten, string _quequan);
};

nguoi::nguoi(string _hoten, string _quequan, int _namsinh)
{
    this->hoten = _hoten;
    this->quequan = _quequan;
    this->namsinh =_namsinh;
}

nguoi::nguoi(const nguoi &ng)
{
    this->hoten = ng.hoten;
    this->quequan = ng.quequan;
    this->namsinh = ng.namsinh;
}

nguoi::~nguoi()
{}

istream &operator >> (istream &is, nguoi &ng)
{
    getline(is, ng.hoten);
    getline(is, ng.quequan);
    is >> ng.namsinh;
    is.ignore();
    return is;
}

ostream &operator << (ostream &os, nguoi ng)
{
    os << ng.hoten << '\n';
    os << ng.namsinh << '\n';
    os << ng.quequan << '\n';
    return os;
}

int nguoi::getNamSinh()
{
    return this->namsinh;
}

string nguoi::getHoTen()
{
    return this->hoten;
}

string nguoi::getQueQuan()
{
    return this->quequan;
}

void nguoi::setNamSinh(int _namsinh)
{
    this->namsinh = _namsinh;
}

void nguoi::setHoTen(string _hoten)
{
    this->hoten = _hoten;
}

void nguoi::setQueQuan(string _quequan)
{
    this->quequan = _quequan;
}

void nguoi::setAll(int _namsinh, string _hoten, string _quequan)
{
    this->namsinh = _namsinh;
    this->hoten = _hoten;
    this->quequan = _quequan;
}

class sinhvien : public nguoi
{
    string khoaHocTap;
    int n;
    double diem[1000];
public:
    sinhvien(string _khoahoctap = "", string _hoten = "", string _quequan = "", int _namsinh = 0, int n = 0, double _diem[] = new double{1});
    sinhvien(const sinhvien &sv);
    ~sinhvien();
    double getDTB();
    double operator[](int i);
    friend istream &operator>>(istream &is, sinhvien &sv);
    friend ostream &operator<<(ostream &os, sinhvien sv);
    string getKhoaHocTap() const;
    void setKhoaHocTap(string _khoaHocTap);
};

sinhvien::sinhvien(string _khoahoctap, string _hoten, string _quequan, int _namsinh, int n, double _diem[])
    : nguoi(_hoten, _quequan, _namsinh)
{
    this->khoaHocTap = _khoahoctap;
    this->n = n;
    for (int i = 0; i < n; i++)
    {
        this->diem[i] = diem[i];
    }
}

sinhvien::sinhvien(const sinhvien &sv)
    : nguoi(sv)
{
    this->khoaHocTap = sv.khoaHocTap;
    this->n = sv.n;
    for (int i = 0; i < n; i++)
    {
        this->diem[i] = sv.diem[i];
    }
}

sinhvien::~sinhvien()
{
}

double sinhvien::getDTB()
{
    double tong = 0;
    for (int i = 0; i < this->n; i++)
    {
        tong += this->diem[i];
    }
    return tong / n;
}

double sinhvien::operator[](int i)
{
    return this->diem[i];
}

istream &operator>>(istream &is, sinhvien &sv)
{
    string _hoten, _quequan;
    int _namsinh;
    getline(is, _hoten);
    is >> _namsinh;
    is.ignore();
    getline(is, _quequan);
    sv.setAll(_namsinh, _hoten, _quequan);
    is >> sv.khoaHocTap;
    sv.n = 0;
    while (is >> sv.diem[sv.n])
    {
        sv.n++;
    }
    return is;
}

ostream &operator<<(ostream &os, sinhvien sv)
{
    os << "Ho Ten: " << sv.getHoTen() << '\n';
    os << "Nam Sinh: " << sv.getNamSinh() << '\n';
    os << "Que quan: " << sv.getQueQuan() << '\n';
    os << "Khoa: " << sv.khoaHocTap << '\n';
    os << "Diem cac mon: ";
    for (int i = 0; i < sv.n; i++)
    {
        os << sv.diem[i] << " ";
    }
    os << '\n';
    os << "Diem trung binh: " << fixed << setprecision(2) << sv.getDTB();
    return os;
}

int main()
{
    sinhvien sv;
    cin >> sv;
    cout << sv;
    return 0;
}