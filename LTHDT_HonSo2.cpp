#include <iostream>
using namespace std;

int ucln(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ucln(b, a % b);
}

class PhanSo
{
    int tu, mau;
    public:
        PhanSo(int _tu = 0, int _mau = 1)
        {
            this->tu = _tu;
            this->mau = _mau;
        }
        PhanSo(const PhanSo &ps)
        {
            this->tu = ps.tu;
            this->mau = ps.mau;
        }
        ~PhanSo()
        {}
        int getTu()
        {
            return this->tu;
        } 
        int getMau()
        {
            return this->mau;
        }
        void setTu(int _tu)
        {
            this->tu = _tu;
        }
        void setMau(int _mau)
        {
            this->mau = _mau;
        }
        void setAll(int _tu, int _mau)
        {
            this->tu = _tu;
            this->mau = _mau;
        }
        friend istream &operator >> (istream &is, PhanSo &ps)
        {
            is >> ps.tu >> ps.mau;
            return is;
        }
        friend ostream &operator << (ostream &os, PhanSo ps)
        {
            os << ps.tu << "/" << ps.mau;
            return os;
        }
        friend PhanSo operator + (PhanSo ps1, PhanSo ps2)
        {
            PhanSo rs;
            rs.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
            rs.mau = ps1.mau*ps2.mau;
            int k = ucln(rs.tu, rs.mau);
            rs.tu /= k;
            rs.mau /= k;
            return rs;
        }
};

class HonSo : public PhanSo
{
    int a;
    public:
        HonSo(int _a = 0, int _tu = 0, int _mau = 1):PhanSo(_tu, _mau)
        {
            this->a = _a; 
        }
        HonSo(const HonSo &hs):PhanSo(hs)
        {
            this->a = hs.a;
        }
        friend istream &operator >> (istream &is, HonSo &hs)
        {
            is >> hs.a;
            int _tu, _mau;
            is >> _tu >> _mau;
            hs.PhanSo::setAll(_tu, _mau);
            return is;
        }
        friend ostream &operator << (ostream &os, HonSo hs)
        {
            os << hs.a << " ";
            os << hs.getTu() << "/" << hs.getMau();
            return os;
        }
        friend HonSo operator + (HonSo hs1, HonSo hs2)
        {
            HonSo rs;
            rs.a = hs1.a + hs2.a;
            PhanSo ps1(hs1.getTu(), hs1.getMau());
            PhanSo ps2(hs2.getTu(), hs2.getMau());
            PhanSo psRs = ps1 + ps2;
            rs.setAll(psRs.getTu(), psRs.getMau());
            return rs;
        }
};

int main()
{
    HonSo hs1, hs2;
    cin >> hs1 >> hs2;
    cout << hs1 + hs2;
    return 0;
}