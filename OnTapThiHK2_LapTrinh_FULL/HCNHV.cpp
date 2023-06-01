#include <iostream>
#include <string>
using namespace std;

class HCN
{
    int dai, rong;
    public:
        HCN(int _dai = 2, int _rong = 1)
        {
            this->dai = _dai;
            this->rong = _rong;
        }
        HCN(const HCN &hcn)
        {
            this->dai = hcn.dai;
            this->rong = hcn.rong;
        }
        ~HCN()
        {}
        friend istream &operator >> (istream &is, HCN &hcn)
        {
            is >> hcn.dai >> hcn.rong;
            return is;
        }
        int getDai()
        {
            return this->dai;
        }
        int getRong()
        {
            return this->rong;
        }
        void setDai(int _dai)
        {
            this->dai = _dai;
        }
        void setRong(int _rong)
        {
            this->rong = _rong;
        }
        void setAll(int _dai, int _rong)
        {
            this->dai = _dai;
            this->rong = _rong;
        }
        int getChuVi()
        {
            return (this->dai + this->rong)*2;
        }
};

class HV : public HCN
{
    int canh;
    public:
        HV(int _canh = 1) : HCN(_canh, _canh)
        {
            this->canh = _canh;
        }
        HV(const HV &hv) : HCN(hv)
        {
            this->canh = hv.canh;
        }
        ~HV()
        {}
        int getCanh()
        {
            return this->canh;
        }
        void setCanh(int _canh)
        {
            this->canh = _canh;
        }
        friend istream &operator >> (istream &is, HV &hv)
        {
            is >> hv.canh;
            hv.setAll(hv.canh, hv.canh);
            return is;
        }
};

int main()
{
    string s;
    cin >> s;
    int max = -9999;
    if (s == "HCN")
    {
        HCN hcn;
        while (cin >> hcn)
        {
            int k = hcn.getChuVi();
            if (max < k)
            {
                max = k;
            }
        }
    }
    else
    {
        HV hv;
        while (cin >> hv)
        {
            int k = hv.getChuVi();
            if(max < k)
            {
                max = k;
            }
        }
    }
    cout << max;
}