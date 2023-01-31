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
    public:
        SinhVien(); // constructor;
        SinhVien(string, string, string, string, string, string, double, double, double, double);
        void nhap();
        void in();
        void tangThuTuSinhVien();
        friend double tinhDiemTrungBinh(SinhVien);
        friend void inThongTin(SinhVien);
        friend istream& operator >> (istream&, SinhVien&);
        friend ostream& operator << (ostream&, SinhVien);
};

int SinhVien::thuTuSinhVien = 0;
 
void SinhVien::tangThuTuSinhVien() {
    thuTuSinhVien++;
}

SinhVien::SinhVien() {
    this->msv = this->ten = this->ngayThangNamSinh = this->noiSinh = this->hoTenCha = this->hoTenMe = "";
    this->diemQuaTrinh = this->diemGiuaKy = this->diemCuoiKy = 0;
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

}

// void SinhVien::nhap() {
//     // cout << "Sinh vien thu " << SinhVien::thuTuSinhVien << endl;
//     // cout << "Nhap ma sinh vien: "; getline(cin, this->msv);
//     // cout << "Nhap ten: "; getline(cin, this->ten);
//     // cout << "Nhap ngay Thang Nam Sinh: "; getline(cin, this->ngayThangNamSinh);
//     // cout << "Nhap noi Sinh: "; getline(cin, this->ngayThangNamSinh);
//     // cout << "Nhap Ho ten cha: "; getline(cin, this->hoTenCha);
//     // cout << "Nhap Ho ten me: "; getline(cin, this->hoTenMe);
//     cout << "Nhap diem qua trinh: "; cin >> this->diemQuaTrinh;
//     cout << "Nhap diem giua ky: "; cin >> this->diemGiuaKy;
//     cout << "Nhap diem cuoi ky: "; cin >> this->diemCuoiKy;
//     cin.ignore();
//     diemTrungBinhMon = diemQuaTrinh*((10*1.0/100)) + diemGiuaKy*((40*1.0/100)) + diemCuoiKy*((60*1.0/100));
    

// void inThongTin(SinhVien x) {
//     // cout << "Sinh vien thu " << SinhVien::thuTuSinhVien << endl;
//     // cout << "MSV: " << x.msv << endl;
//     // cout << "Ten: " << x.ten << endl;
//     // cout << "Ngay Thang Nam Sinh: " << x.ngayThangNamSinh << endl;
//     // cout << "Noi Sinh: " << x.noiSinh << endl;
//     // cout << "Ho Ten Cha: " << x.hoTenCha << endl;
//     // cout << "Ho Ten Me: " << x.hoTenMe << endl;
//     cout << "Diem qua trinh: " << x.diemQuaTrinh << endl;
//     cout << "Diem giua ky: " << x.diemGiuaKy << endl;
//     cout << "Diem cuoi ky: " << x.diemCuoiKy << endl;
//     cout << "Diem trung binh: " << fixed << setprecision(2)<< x.diemTrungBinhMon;
// }

double tinhDiemTrungBinh(SinhVien a) {
    return a.diemQuaTrinh*(10*1.0/100) + a.diemGiuaKy*(30*1.0/100) + a.diemCuoiKy*(60*1.0/100);
}

istream& operator >> (istream& input, SinhVien& a) {
    cout << "Sinh vien thu " << SinhVien::thuTuSinhVien << endl;
    cout << "Nhap ma sinh vien: "; getline(input, a.msv);
    cout << "Nhap ten: "; getline(input, a.ten);
    cout << "Nhap ngay thang nam sinh: "; getline(input, a.ngayThangNamSinh);
    cout << "Nhap noi sinh: "; getline(input, a.noiSinh);
    cout << "Nhap Ho ten cha: "; getline(input, a.hoTenCha);
    cout << "Nhap Ho ten me: "; getline(input, a.hoTenMe);
    cout << "Nhap Diem qua trinh: "; input >> a.diemQuaTrinh;
    cout << "Nhap diem giua ky: "; input >> a.diemGiuaKy;
    cout << "Nhap diem cuoi ky: " ; input >> a.diemCuoiKy;
    input.ignore();
    return input;
}

ostream& operator << (ostream& output, SinhVien a) {
    output << "Ma sinh vien: " << a.msv << endl;
    output << "Ten: " << a.ten << endl;
    output << "Ngay thang nam sinh: " << a.ngayThangNamSinh << endl;
    output << "Noi sinh: " << a.noiSinh << endl;
    output << "Ho ten cha: " << a.hoTenCha << endl;
    output << "Ho ten me: " << a.hoTenMe << endl;
    output << "Diem qua trinh: " << a.diemQuaTrinh  <<endl;
    output << "Diem giua ky: " << a.diemGiuaKy << endl;
    output << "Diem cuoi ky: " << a.diemCuoiKy << endl;
    output << "Diem trung binh: " << fixed << setprecision(2) << tinhDiemTrungBinh(a);
    return output;
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
        cin >> x[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << x[i];
    }
    
    system("Pause");
}