#include <iostream>
using namespace std;

struct HCN
{
    int a, b;
    public:
        int chuVi(HCN hc);
};

istream &operator >> (istream &is, HCN &hc) {
    is >> hc.a >> hc.b;
    return is;
}

ostream &operator << (ostream &os, HCN hc) {
    os << "[HCN]" << " " << hc.a << "," << hc.b;
    return os;
}

int chuVi(HCN hc) {
    return (hc.a + hc.b)*2;
}

bool operator < (HCN hc_1, HCN hc_2) {
    return chuVi(hc_1) < chuVi(hc_2);
}

int main() {
    HCN hc_1, hc_2;
    cin >> hc_1 >> hc_2;
    cout << hc_1 << '\n';
    cout << hc_2 << '\n';
    if (hc_1 < hc_2)
    {
        cout << "true" << '\n';
    }
    else
    {
        cout << "false" << '\n';
    }
    system("Pause");
}