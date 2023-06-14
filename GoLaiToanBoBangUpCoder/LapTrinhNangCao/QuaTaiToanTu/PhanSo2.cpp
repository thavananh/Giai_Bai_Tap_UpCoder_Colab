/*
+Xây dựng cấu trúc PhanSo:
Viết quá tải toán tử: >>, <<, ==,!=,+

+ xây dựng cấu trúc mảng Phân số
viết quá tải toán tử: >>,<<,[].

viết ct nhập vào dãy phân số, yêu cầu xuất tổng phân số sau khi rút gọn
ví dụ:
1 2
2 3
3 4

output:
23/12
*/

#include <iostream>
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

bool operator == (PhanSo ps1, PhanSo ps2)
{
    return (double)ps1.tu/ps1.mau == (double)ps2.tu/ps2.mau;
}

bool operator != (PhanSo ps1, PhanSo ps2)
{
    return !(ps1 == ps2);
}

int ucln(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ucln(b, a % b);
}

PhanSo operator + (PhanSo ps1, PhanSo ps2)
{
    PhanSo rs;
    rs.tu = ps1.tu*ps2.mau+ps2.tu*ps1.mau;
    rs.mau = ps1.mau*ps2.mau;
    int k = ucln(rs.tu, rs.mau);
    rs.tu /= k;
    rs.mau /= k;
    return rs;
}

struct Mang
{
    int n;
    PhanSo ps[1000];
    public:
        PhanSo &operator[](int i)
        {
            return ps[i];
        }
};

istream &operator >> (istream &is, Mang &m)
{
    m.n = 0;
    while (is >> m.ps[m.n])
    {
        m.n++;
    }
}

ostream &operator << (ostream &os, Mang m)
{
    PhanSo rs = m.ps[0];
    for (int i = 1; i < m.n; ++i)
    {
        rs = rs + m.ps[i];
    }
    os << rs;
    return os;
}
int main()
{
    Mang m1;
    cin >> m1;
    cout << m1;
}