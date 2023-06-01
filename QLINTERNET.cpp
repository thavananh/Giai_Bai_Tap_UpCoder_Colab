#include <iostream>
#include <string>
using namespace std;

// class Internet
// {
// public:
//     virtual int donGia() = 0;
// };

class Khach
{
    string tenKhachHang;
    int thoiGianSuDungMay, soMayDaSuDung, donGia;
public:
    Khach(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMayDaSuDung = 0, int  _donGia = 0)
    {
        this->tenKhachHang = _tenKhachHang;
        this->thoiGianSuDungMay = _thoiGianSuDungMay;
        this->soMayDaSuDung = _soMayDaSuDung;
        this->donGia = _donGia;
    }

    Khach(const Khach &k)
    {
        this->tenKhachHang = k.tenKhachHang;
        this->thoiGianSuDungMay = k.thoiGianSuDungMay;
        this->soMayDaSuDung = k.soMayDaSuDung;
        this->donGia  = k.donGia;
    }

    ~Khach()
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

    int getSoMayDaSuDung()
    {
        return this->soMayDaSuDung;
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

    void setSoMayDaSuDung(int _soMayDaSuDung)
    {
        this->soMayDaSuDung = _soMayDaSuDung;
    }

    void setDonGia(int _donGia)
    {
        this->donGia = _donGia;
    }

    void setAll(string _tenKhachHang, int _thoiGianSuDungMay, int _soMayDaSuDung, int _donGia)
    {
        this->tenKhachHang = _tenKhachHang;
        this->thoiGianSuDungMay = _thoiGianSuDungMay;
        this->soMayDaSuDung = _soMayDaSuDung;
        this->donGia = _donGia;
    }


    // friend istream &operator>>(istream &is, Khach &k)
    // {
    //     getline(is, k.tenKhachHang);
    //     is >> k.thoiGianSuDungMay >> k.soMayDaSuDung >> k.donGia;
    //     is.ignore();
    //     return is;
    // }

    // friend ostream &operator<<(ostream &os, Khach k)
    // {
    //     os << "Ho Ten: " << k.tenKhachHang << endl;
    //     os << "Thoi gian su dung: " << k.thoiGianSuDungMay << endl;
    //     os << "So may: " << k.soMayDaSuDung << endl;
    //     return os;
    // }
    virtual string getLoai() = 0;
    virtual double getTinhTien() = 0;
    void output()
    {
        cout << ". Loai khach: " << getLoai() << '\n';
        cout << "Ho Ten: " << this->tenKhachHang << '\n';
        cout << "Thoi gian su dung: " << this->thoiGianSuDungMay << '\n';
        cout << "So may: " << this->soMayDaSuDung << '\n';
        cout << "So tien phai tra: " << getTinhTien() << '\n';
    }
};

class VIP : public Khach
{
    int donGiaVip;
    public:
        VIP(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMayDaSuDung = 0, int  _donGia = 0, int _donGiaVip = 0)
            : Khach(_tenKhachHang, _thoiGianSuDungMay, _soMayDaSuDung, _donGia)
        {
            this->donGiaVip = _donGiaVip;
        }
        VIP(const VIP &v) : Khach(v)
        {
            this->donGiaVip = v.donGiaVip;
        }
        string getLoai()
        {
            return "VIP";
        }
        double getTinhTien()
        {
            if (getThoiGianSuDungMay() >= 4)
            {
                return this->donGiaVip * 4;
            }
            else
            {
                return getDonGia() * getThoiGianSuDungMay();
            }
            
        }
};

class KHTX : public Khach
{
    int heSoKhuyenMai;
    public:
        KHTX(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMayDaSuDung = 0, int  _donGia = 0, int _heSoKhuyenMai = 0)
            : Khach(_tenKhachHang, _thoiGianSuDungMay, _soMayDaSuDung, _donGia)
        {
            this->heSoKhuyenMai = _heSoKhuyenMai;
        }
        KHTX(const KHTX &tx) : Khach(tx)
        {
            this->heSoKhuyenMai = tx.heSoKhuyenMai;
        }
        ~KHTX()
        {}
        string getLoai()
        {
            return "TX";
        }
        double getTinhTien()
        {
            return getThoiGianSuDungMay() * getDonGia() - getThoiGianSuDungMay()*this->heSoKhuyenMai;
        }
        
};

class KTX : public Khach
{
    int dungLuongDownload, donGiaDownload;
    public:
        KTX(string _tenKhachHang = "", int _thoiGianSuDungMay = 0, int _soMayDaSuDung = 0, int  _donGia = 0, int _dungLuongDownload = 0, int _donGiaDownload = 0)
            : Khach(_tenKhachHang, _thoiGianSuDungMay, _soMayDaSuDung, _donGia)
        {
            this->donGiaDownload = _donGiaDownload;
            this->dungLuongDownload = _dungLuongDownload;
        }       
        KTX(const KTX &ktx) : Khach(ktx)
        {
            this->donGiaDownload = ktx.donGiaDownload;
            this->donGiaDownload = ktx.donGiaDownload;
        }
        string getLoai()
        {
            return "KTX";
        }
        double getTinhTien()
        {
            return getThoiGianSuDungMay()*getDonGia() + this->dungLuongDownload*donGiaDownload;
        }
};

int main()
{
    Khach *p[100];
    int n, donGia, donGiaVip, donGiaDownload;
    cin >> n >> donGia >> donGiaVip >> donGiaDownload;
    string choice;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cin.ignore();
        string tenKhachHang;
        int thoiGianSuDungMay, soMaySuDung;
        getline(cin, tenKhachHang);
        cin >> thoiGianSuDungMay >> soMaySuDung;
        cin.ignore();
        cout << i+1;
        if (s == "VIP")
        {
            VIP khachVip = VIP(tenKhachHang, thoiGianSuDungMay, soMaySuDung, donGia, donGiaVip);
            p[i] = &khachVip;
            p[i]->output();
        }
        else if (s == "TX")
        {
            int heSoKhuyenMai; cin >> heSoKhuyenMai;
            KHTX tx_1 = KHTX(tenKhachHang, thoiGianSuDungMay, soMaySuDung, donGia, heSoKhuyenMai);
            p[i] = &tx_1;
            p[i]->output();
        }
        else
        {
            int dungLuongDownload; cin >> dungLuongDownload;
            KTX ktx_1 = KTX(tenKhachHang, thoiGianSuDungMay, soMaySuDung, donGia, dungLuongDownload, donGiaDownload);
            p[i] = &ktx_1;
            p[i]->output();
        }
    }
    return 0;
}