#include <iostream>
using namespace std;

class HCN
{
    double dai, rong;
    public:
        HCN(double dai = 2, double rong = 1);
        HCN(const HCN &hcn);
        ~HCN();
        double getDai();
        double getRong();
        void setDai(double dai);
        void setRong(double rong);
        friend istream &operator >> (istream &is, HCN &hcn);
        friend ostream &operator << (ostream &os, HCN hcn);
        friend bool operator < (HCN hcn1, HCN hcn2);
        void setDaiRong(double dai = 2, double rong = 1);
        double chuVi();
};

HCN::HCN(double dai, double rong)
{
    this->dai = dai;
    this->rong = rong;
}

HCN::HCN(const HCN &hcn)
{
    this->dai = hcn.dai;
    this->rong = hcn.rong;
}

HCN::~HCN()
{}

double HCN::getDai()
{
    return this->dai;
}

double HCN::getRong()
{
    return this->rong;
}

void HCN::setDai(double dai)
{
    this->dai = dai;
}

void HCN::setRong(double rong)
{
    this->rong = rong;
}

void HCN::setDaiRong(double dai, double rong)
{
    this->dai = dai;
    this->rong = rong;
}

istream &operator >> (istream &is, HCN &hcn)
{
    is >> hcn.dai >> hcn.rong;
    return is;
}

ostream &operator << (ostream &os, HCN hcn)
{
    os << "HCN: " << hcn.dai << " " << hcn.rong;
    return os;
}

double HCN::chuVi()
{
    return (this->dai + this->rong)*2;
}

bool operator < (HCN hcn1, HCN hcn2)
{
    return hcn1.chuVi() < hcn2.chuVi();
}

class HV:public HCN
{
    double canh;
    public:
        HV(double canh = 1);
        HV(const HV &hv);
        ~HV();
        friend istream &operator >> (istream &is, HV &hv);
        friend ostream &operator << (ostream &os, HV hv);
        void setCanh(double canh = 1);
};

HV::HV(double canh)
{
    this->canh = canh;
    HCN::setDaiRong(canh, canh);
}

HV::HV(const HV &hv)
{
    this->canh = hv.canh;
    HCN::setDaiRong(canh, canh);
}

HV::~HV()
{}

void HV::setCanh(double canh)
{
    this->canh = canh;
    HCN::setDaiRong(canh, canh);
}

istream &operator >> (istream &is, HV &hv)
{
    is >> hv.canh;
    hv.HCN::setDaiRong(hv.canh, hv.canh);
    return is;
}

ostream &operator << (ostream &os, HV hv)
{
    os << "HV: " << hv.canh;
    return os;
}

int main()
{
    string choice;
    cin >> choice;
    double _max = 0;
    if (choice == "HCN")
    {
        HCN hcn;

        while (cin >> hcn)
        {
            double dientich = hcn.chuVi();
            if (_max < dientich)
            {
                _max = dientich;
            }
        }
    }
    else
    {
        HV hv;
        while (cin >> hv)
        {
            double dientich = hv.chuVi();
            if (_max < dientich)
            {
                _max = dientich;
            }
            
        }
        
    }
    cout << _max;
}