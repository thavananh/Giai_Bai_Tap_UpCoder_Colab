#include <iostream>
#include <string>
#include <iomanip> 
#include <cmath>
using namespace std;

class SinhVien {
    private:
        static int thuTuSinhVien;
        string msv;
        string ten;
        string ngayThangNamSinh;
        string noiSinh;
        string hoTenCha;
        string hoTenMe;
        double diemQuaTrinh;
        double diemGiuaKy;
        double diemCuoiKy;
        double diemTrungBinhMon;
    public:
    SinhVien(); // constructor;
    SinhVien(string, string, string, string, string, string, double, double, double, double);
    void nhap();
    void in();
    void tangThuTuSinhVien();
    friend void inThongTin(SinhVien);
};

int SinhVien::thuTuSinhVien = 0;
 
void SinhVien::tangThuTuSinhVien() {
    thuTuSinhVien++;
}

SinhVien::SinhVien() {
    this->msv = this->ten = this->ngayThangNamSinh = this->noiSinh = this->hoTenCha = this->hoTenMe = "";
    this->diemQuaTrinh = this->diemGiuaKy = this->diemCuoiKy = this->diemTrungBinhMon = 0;
}

SinhVien::SinhVien(string msv, string ten, string ngayThangNamSinh, string noiSinh, string hoTenCha, string hoTenMe, double diemQuaTrinh, double diemGiuaKy, double diemCuoiKy, double diemTrungBinhMon) {
    this->msv = msv;
    this->ten = ten;
    this->ngayThangNamSinh = ngayThangNamSinh;
    this->noiSinh = noiSinh;
    this->hoTenCha = hoTenCha;
    this->hoTenMe = hoTenMe;
    this->diemQuaTrinh = diemQuaTrinh;
    this->diemGiuaKy = diemGiuaKy;
    this->diemCuoiKy = diemCuoiKy;
    this->diemTrungBinhMon = diemTrungBinhMon;
}

void SinhVien::nhap() {
    cout << "Sinh vien thu " << SinhVien::thuTuSinhVien << endl;
    cout << "Nhap ma sinh vien: "; getline(cin, this->msv);
    cout << "Nhap ten: "; getline(cin, this->ten);
    cout << "Nhap ngay Thang Nam Sinh: "; getline(cin, this->ngayThangNamSinh);
    cout << "Nhap noi Sinh: "; getline(cin, this->ngayThangNamSinh);
    cout << "Nhap Ho ten cha: "; getline(cin, this->hoTenCha);
    cout << "Nhap Ho ten me: "; getline(cin, this->hoTenMe);
    cout << "Nhap diem qua trinh: "; cin >> this->diemQuaTrinh;
    cout << "Nhap diem giua ky: "; cin >> this->diemGiuaKy;
    cout << "Nhap diem trung binh: "; cin >> this->diemCuoiKy;
    cin.ignore();
    
}


void inThongTin(SinhVien x) {
    cout << "Sinh vien thu " << SinhVien::thuTuSinhVien << endl;
    cout << "MSV: " << x.msv << endl;
    cout << "Ten: " << x.ten << endl;
    cout << "Ngay Thang Nam Sinh: " << x.ngayThangNamSinh << endl;
    cout << "Noi Sinh: " << x.noiSinh << endl;
    cout << "Ho Ten Cha: " << x.hoTenCha << endl;
    cout << "Ho Ten Me: " << x.hoTenMe << endl;
    cout << "Diem qua trinh: " << x.diemQuaTrinh << endl;
    cout << "Diem giua ky: " << x.diemGiuaKy << endl;
    cout << "Diem cuoi ky: " << x.diemCuoiKy << endl;
    cout << "Diem trung binh: " << fixed << setprecision(2)<< (x.diemQuaTrinh*(10/100) + x.diemGiuaKy*(40/100) + x.diemCuoiKy*(60/100));

}

int main() {
    SinhVien x[100];
    int n;
    cout << "nhap so luong sinh vien can nhap: ";
    cin >> n;
    cin.ignore();
    for (size_t i = 0; i < n; i++)
    {
        x[i].tangThuTuSinhVien();
        x[i].nhap();
    }
    for (size_t i = 0; i < n; i++)
    {
        inThongTin(x[i]);
    }
    
    system("Pause");
}