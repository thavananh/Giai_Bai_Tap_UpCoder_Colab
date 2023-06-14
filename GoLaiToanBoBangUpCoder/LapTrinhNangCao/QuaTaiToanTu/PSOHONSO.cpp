#include <iostream>
#include <string>
using namespace std;

struct PhanSo
{
    int tu, mau;
};

istream &operator >> (istream &is, PhanSo &ps)
{
    is >> ps.tu >> ps.mau;
    return is;
}
ostream &operator << (ostream &os, PhanSo ps)
{
    os << ps.tu << "/" << ps.mau;
    return os;
}
bool operator != (PhanSo ps1, PhanSo ps2)
{
    return ps1.tu != ps2.tu || ps1.mau != ps2.mau;
}
struct HonSo
{
    int a;
    PhanSo ps;
};
istream &operator >> (istream &is, HonSo &hs)
{
    is >> hs.a >> hs.ps.tu >> hs.ps.mau;
    return is;
}
ostream &operator << (ostream &os, HonSo hs)
{
    os << hs.a << " " << hs.ps;
    return os;
}

int ucln(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ucln(b, a % b);
}
PhanSo rutGonPhanSo(PhanSo ps)
{
    PhanSo rs = ps;
    int k = ucln(rs.tu, rs.mau);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}
HonSo rutGonHonSo(HonSo hs) // rút gọn hỗn sỗ nghĩa là cho số a lớn nhất và ps gọn nhất
{
    HonSo rs = hs;
    rs.ps = rutGonPhanSo(rs.ps);
    rs.a += rs.ps.tu / rs.ps.mau;
    rs.ps.tu %= rs.ps.mau;
    return rs;
}
PhanSo chuyenHsThanhPs(HonSo hs)
{
    PhanSo rs;
    rs.tu = hs.a * hs.ps.mau + hs.ps.tu;
    rs.mau = hs.ps.mau;
    return rutGonPhanSo(rs);
}
int tongThanhPhan(HonSo hs)
{
    return hs.a+hs.ps.tu+hs.ps.mau;
}
bool operator != (HonSo hs1, HonSo hs2)
{
    return hs1.a != hs2.a || hs1.ps != hs2.ps;
}
bool operator > (HonSo hs1, HonSo hs2)
{
    return tongThanhPhan(hs1) > tongThanhPhan(hs2);
}
int main()
{
    HonSo hs1, hs2;
    string choice;
    cin >> hs1 >> hs2 >> choice;
    if (hs1 != hs2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (hs1 > hs2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE";
    }
    if (choice == "true")
    {
        cout << rutGonHonSo(hs1) << '\n' << rutGonHonSo(hs2);
    }
    else
    {
        cout << chuyenHsThanhPs(hs1) << '\n' << chuyenHsThanhPs(hs2);
    }
}