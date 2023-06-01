#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class nguoi
{
    string hoten, quequan;
    int namsinh;
    public:
        nguoi(string _hoten = "", string _quequan = "", int _namsinh = 0)
        {
            this->hoten = _hoten;
            this->quequan = _quequan;
            this->namsinh = _namsinh;
        }
        nguoi(const nguoi &ng)
        {
            this->hoten = ng.hoten;
            this->quequan = ng.quequan;
            this->namsinh = ng.namsinh;
        }
        ~nguoi()
        {

        }
        friend istream &operator >> (istream &is, nguoi &ng)
        {
            getline(is, ng.hoten);
            is >> ng.namsinh;
            is.ignore();
            getline(is, ng.quequan);
        }
        friend ostream &operator << (ostream &os, nguoi ng)
        {
            os << "Ho Ten: " << ng.hoten << '\n';
            os << "Nam Sinh: " << ng.namsinh << '\n';
            os << "Que quan: " << ng.quequan << '\n';
            return os;
        }
        string getHoTen()
        {
            return this->hoten;
        }
        string getQueQuan()
        {
            return this->quequan;
        }
        int getNamSinh()
        {
            return this->namsinh;
        }
        void setHoTen(string _hoten)
        {
            this->hoten = _hoten;
        }
        void setQueQuan(string _quequan)
        {
            this->quequan = _quequan;
        }
        void setAll(string _hoten, string _quequan, int _namsinh)
        {
            this->hoten = _hoten;
            this->quequan = _quequan;
            this->namsinh = _namsinh;
        }
};

class SINHVIEN : public nguoi
{
    string khoa;
    int n;
    int a[1000];
    public: 
        SINHVIEN(string _hoten = "", string _quequan = "", int _namsinh = 0, string _khoa = "", int _n = 0, int _a[] = new int{}):nguoi(_hoten, _quequan, _namsinh)
        {
            this->n = n;
            for (size_t i = 0; i < n; i++)
            {
                this->a[i] = _a[i];
            }
            this->khoa = _khoa;
        }
        SINHVIEN(const SINHVIEN &sv) : nguoi(sv)
        {
            this->n = sv.n;
            for (size_t i = 0; i < sv.n; i++)
            {
                this->a[i] = sv.a[i];
            }
            this->khoa = sv.khoa;
        }
        ~SINHVIEN()
        {

        }
        string getKhoa()
        {
            return this->khoa;
        }
        void setKhoa(string _khoa)
        {
            this->khoa = _khoa;
        }
        double getDTB()
        {
            double tong = 0;
            for (size_t i = 0; i < this->n; i++)
            {
                tong = tong + this->a[i];
            }
            return (double)tong/n;
        }
        friend istream &operator >> (istream &is, SINHVIEN &sv)
        {
            string _hoten, _quequan;
            int _namsinh;
            getline(is, _hoten);
            is >> _namsinh;
            is.ignore();
            getline(is, _quequan);
            getline(is, sv.khoa);
            sv.n = 0;
            while (is >> sv.a[sv.n])
            {
                sv.n++;
            }
            sv.setAll(_hoten, _quequan, _namsinh);
            is.ignore();
            return is;
        }
        friend ostream &operator << (ostream &os, SINHVIEN sv)
        {
            os << "Ho Ten: " << sv.getHoTen() << '\n';
            os << "Nam Sinh: " << sv.getNamSinh() << '\n';
            os << "Que quan: " << sv.getQueQuan() << '\n';
            os << "Khoa: " << sv.khoa << '\n';
            os << "Diem cac mon: ";
            for (size_t i = 0; i < sv.n; i++)
            {
                os << sv.a[i] << " ";
            }
            os << '\n';
            os << "Diem trung binh: " << fixed << setprecision(2) << sv.getDTB(); 
            return os;
        }
};

int main()
{
    SINHVIEN sv;
    cin >> sv;
    cout << sv;
}