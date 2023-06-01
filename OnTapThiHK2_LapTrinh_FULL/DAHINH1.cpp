#include <iostream>
using namespace std;

class HinhHoc
{
    public:
        virtual int getCV() = 0;
};

class HCN : public HinhHoc
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
        friend istream &operator >> (istream &is, HCN &hcn)
        {
            is >> hcn.dai >> hcn.rong;
            return is;
        }
        int getCV()
        {
            return (dai+rong)*2;
        }
};

class HV : public HCN
{
    int canh;
    public:
        HV(int _canh = 1):HCN(_canh, _canh)
        {
            this->canh = _canh;
        }
        HV(const HV &hv):HCN(hv)
        {
            this->canh = hv.canh;
        }
        friend istream &operator >> (istream &is, HV &hv)
        {
            is >> hv.canh;
            hv.HCN::setAll(hv.canh, hv.canh);
            return is;
        }
};

int main()
{
    char c;
    int n = 0;
    HinhHoc *p[100];
    while (cin >> c)
    {
        if (c == 'a')
        {
            int canh; cin >> canh;
            p[n] = new HV(canh);
            n++;
        }
        else
        {
            int dai, rong;
            cin >> dai >> rong;
            p[n] = new HCN(dai, rong);
            n++;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << p[i]->getCV() << '\n';
    }
}