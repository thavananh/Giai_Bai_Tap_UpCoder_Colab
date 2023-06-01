#include <iostream>
using namespace std;

int ucln(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ucln(b, a%b);
}

class PHANSO
{
    int tu, mau;
    public: 
        PHANSO(int _tu = 0, int _mau = 1)
        {
            this->tu = _tu;
            this->mau = _mau;
        }
        PHANSO(const PHANSO &ps)
        {
            this->tu = ps.tu;
            this->mau = ps.mau;
        }
        ~PHANSO()
        {
            
        }
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
        friend istream &operator >> (istream &is, PHANSO &ps)
        {
            is >> ps.tu >> ps.mau;
            return is;
        }
        friend ostream &operator << (ostream &os, PHANSO ps)
        {
            os << ps.tu << "/" << ps.mau;
            return os;
        }
        friend PHANSO operator + (PHANSO ps1, PHANSO ps2)
        {
            PHANSO rs;
            rs.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
            rs.mau = ps1.mau*ps2.mau;
            return rs;
        }
};

class HONSO : public PHANSO
{
    int a;
    public:
        HONSO(int _tu = 0, int _mau = 1, int a = 0):PHANSO(_tu, _mau)
        {
            this->a = a;
        }
        HONSO(const HONSO &hs):PHANSO(hs)
        {
            this->a = hs.a;
        }
        ~HONSO()
        {
        
        }
        int getA()
        {
            return this->a; 
        }
        void setA(int _a)
        {
            this->a = _a;
        }
        friend istream &operator >> (istream &is, HONSO &hs)
        {
            is >> hs.a;
            int _tu, _mau;
            is >> _tu >> _mau;
            hs.setAll(_tu, _mau);
            return is;
        }
        friend ostream &operator << (ostream &os, HONSO hs)
        {
            os << hs.a << " " << hs.getTu() << "/" << hs.getMau();
            return os;
        }
        friend HONSO operator + (HONSO hs1, HONSO hs2)
        {
            HONSO rs;
            rs.a = hs1.a + hs2.a;
            PHANSO ps1(hs1.getTu(), hs1.getMau());
            PHANSO ps2(hs2.getTu(), hs2.getMau());
            PHANSO ps3 = ps1 + ps2;
            rs.setAll(ps3.getTu(), ps3.getMau());
            return rs;
        }
};

int main()
{
    HONSO hs1, hs2;
    cin >> hs1 >> hs2;
    cout << hs1 + hs2;
}