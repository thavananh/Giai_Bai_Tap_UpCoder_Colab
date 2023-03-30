#include <iostream>
using namespace std;

class Diem {
    int n;
    float a[100];
    public:
    //Hàm khởi tạo - huỷ
    Diem(int n = 1, float a[] = new float{1});
    Diem(const Diem &d);
    ~Diem();
    //Hàm get - set
    float getDTB();
    int getN();
    void setN(int n);
    //Quá tải nhập - xuất, lấy giá trị từ mảng, quá tải bằng
    friend istream& operator >> (istream &is, Diem &d);
    friend ostream& operator << (ostream &os, Diem d);
    float& operator[](int i) {
        return a[i];
    }
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
    //Hàm khởi tạo - huỷ
    SinhVien(string hoten = "", string msv = "", Diem d = Diem());
    SinhVien(const SinhVien &sv);
    ~SinhVien();
    //Hàm get - set
    friend istream& operator >> (istream &is, SinhVien &sv);
    friend ostream& operator << (ostream &os, SinhVien sv);    
};

class MangSinhVien {
    int n;
    SinhVien sv[100];
    public:
    MangSinhVien(int n = 1, SinhVien sv[] = new SinhVien());
    
};


int main() {

}