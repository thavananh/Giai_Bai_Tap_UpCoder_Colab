#include <iostream>
#include <string>
using namespace std;

class KHACHHANG
{
    string tenKhachHang;
    int thoiGianSuDungMay, soMaySuDung, donGia;
    public:
        KHACHHANG(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMaySuDung = 0, int _donGia = 0)
        {
            this->tenKhachHang = _tenKhachHang;
            this->thoiGianSuDungMay = _thoiGianSuDungMay;
            this->soMaySuDung = _soMaySuDung;
            this->donGia = _donGia;
        }
        KHACHHANG(const KHACHHANG &kh)
        {
            this->tenKhachHang = kh.tenKhachHang;
            this->thoiGianSuDungMay = kh.thoiGianSuDungMay;
            this->soMaySuDung = kh.soMaySuDung;
            this->donGia = kh.donGia;
        }
        ~KHACHHANG()
        {

        }
        string getTenKhachHang()
        {
            return this->tenKhachHang;
        }
        int getThoiGianSuDungMay()
        {
            return this->thoiGianSuDungMay;
        }
        int getSoMaySuDung()
        {
            return this->soMaySuDung;
        }
        int getDonGia()
        {
            return this->donGia;
        }
        void setTenKhachHang(string _tenKhachHang)
        {
            this->tenKhachHang = _tenKhachHang;
        }
        void setThoiGianSuDungMay(int _thoiGianSuDungMay)
        {
            this->thoiGianSuDungMay = _thoiGianSuDungMay;
        }
        void setSoMaySuDung(int _soMaySuDung)
        {
            this->soMaySuDung = _soMaySuDung;
        }
        void setDonGia(int _donGia)
        {
            this->donGia = _donGia;
        }
        void setAll(string _tenKhachHang, int _thoiGianSuDungMay, int _soMayDaSuDung, int _donGia)
        {
        this->tenKhachHang = _tenKhachHang;
        this->thoiGianSuDungMay = _thoiGianSuDungMay;
        this->soMaySuDung = _soMayDaSuDung;
        this->donGia = _donGia;
        }
        virtual string getLoaiKhachHang() = 0;
        virtual double getTinhTien() = 0;
        void print()
        {
            cout << ". Loai khach: " << getLoaiKhachHang() << '\n';
            cout << "Ho Ten: " << this->tenKhachHang << '\n';
            cout << "Thoi gian su dung: " << this->thoiGianSuDungMay << '\n';
            cout << "So may: " << this->soMaySuDung << '\n';
            cout << "So tien phai tra: " << getTinhTien() << '\n';
        }
};

class VIP : public KHACHHANG
{
    int donGiaVip;
    public:
        VIP(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMaySuDung = 0, int _donGia = 0, int _donGiaVip = 0):KHACHHANG(_tenKhachHang, _thoiGianSuDungMay, _soMaySuDung, _donGia)
        {
            this->donGiaVip = _donGiaVip;
        }
        VIP(const VIP &v):KHACHHANG(v)
        {
            this->donGiaVip = v.donGiaVip;
        }
        ~VIP()
        {

        }
        int getDonGiaVip()
        {
            return this->donGiaVip;
        }
        void setDonGiaVip(int _donGiaVip)
        {
            this->donGiaVip = _donGiaVip;
        }

        string getLoaiKhachHang()
        {
            return "VIP";
        }
        
        double getTinhTien()
        {
            int k = getThoiGianSuDungMay();
            if (k >= 4)
            {
                return this->donGiaVip*4;
            }
            else
            {
                return this->getDonGia()*k;
            }
        }      
};

class KHTX:public KHACHHANG
{
    int heSoKhuyenMai;
    public:
        KHTX(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMaySuDung = 0, int _donGia = 0, int _heSoKhuyenMai = 0)
        :KHACHHANG(_tenKhachHang, _thoiGianSuDungMay, _soMaySuDung, _donGia)
        {
            this->heSoKhuyenMai = _heSoKhuyenMai;
        }
        KHTX(const KHTX &khtx):KHACHHANG(khtx)
        {
            this->heSoKhuyenMai = khtx.heSoKhuyenMai;
        }
        ~KHTX()
        {

        }
        int getHeSoKhuyenMai()
        {
            return this->heSoKhuyenMai;
        }
        void setHeSoKhuyenMai(int _heSoKhuyenMai)
        {
            this->heSoKhuyenMai = _heSoKhuyenMai;
        }
        string getLoaiKhachHang()
        {
            return "TX";
        }
        double getTinhTien()
        {
            return getThoiGianSuDungMay()*getDonGia() - getThoiGianSuDungMay()*this->heSoKhuyenMai;
        }
};

class KHKTX:public KHACHHANG
{
    int dungLuongDownload, donGiaDownload;
    public:
        KHKTX(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMaySuDung = 0, int _donGia = 0, int _dungLuongDownload = 0, int _donGiaDownload = 0):KHACHHANG(_tenKhachHang, _thoiGianSuDungMay, _soMaySuDung, _donGia)
        {
            this->dungLuongDownload =  _dungLuongDownload;
            this->donGiaDownload = _donGiaDownload;
        }
        KHKTX(const KHKTX &khtx)
        {
            this->dungLuongDownload = khtx.dungLuongDownload;
            this->donGiaDownload =   khtx.donGiaDownload;
        }
        ~KHKTX()
        {

        }
        int getDungLuongDownload()
        {
            return this->dungLuongDownload;
        }
        void setDungLuongDownload(int _dungLuongDownload)
        {
            this->dungLuongDownload = _dungLuongDownload;
        }
        string getLoaiKhachHang()
        {
            return "KTX";
        }
        double getTinhTien()
        {
            return getThoiGianSuDungMay()*getDonGia() + dungLuongDownload*donGiaDownload;
        }
};

int main()
{
    KHACHHANG *p[1000];
    int n, donGia, donGiaVip, donGiaDownload;
    cin >> n >> donGia >> donGiaVip >> donGiaDownload;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cin.ignore();
        int thoiGianSuDungMay;
        int soMaySuDung;
        string hoten;
        getline(cin, hoten);
        cin >> thoiGianSuDungMay >> soMaySuDung;
        if (s == "VIP")
        {
            p[i] = new VIP(hoten, thoiGianSuDungMay, soMaySuDung, donGia, donGiaVip);
        }
        else if (s == "TX")
        {
            int heSoKhuyenMai; cin >> heSoKhuyenMai;
            cin.ignore();
            p[i] = new KHTX(hoten, thoiGianSuDungMay, soMaySuDung, donGia, heSoKhuyenMai);
        }
        else
        {
            int dungLuongDownload; cin >> dungLuongDownload;
            cin.ignore();
            p[i] = new KHKTX(hoten, thoiGianSuDungMay, soMaySuDung, donGia, dungLuongDownload, donGiaDownload);
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << i+1;
        p[i]->print();
        cout << '\n';
    }
}
