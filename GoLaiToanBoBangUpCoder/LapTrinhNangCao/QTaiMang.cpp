/*
Cho cấu trúc mảng 1 chiều.
yêu cầu xây dựng các hàm quá tải sau:
Nhập
Xuất.
Gán
Cộng
So sánh bằng
So sánh khác
Toán tử []
Viết một chương trình nhập vào 2 mảng 1 chiều, xuất "yes" nếu 2 mảng giống nhau, ngược lại xuất "no" nếu 2 mảng khác nhau.

Hướng dẫn nhập:

Dòng 1: nhập số lượng phần tử mảng thứ 1 (<=10)
Dòng 2: Nhập các phần tử của mảng thứ 1 (mỗi phần tử có giá trị <=100)
Dòng 3: nhập số lượng phần tử mảng thứ 2 (<=10)
Dòng 4: Nhập các phần tử của mảng thứ 2 (mỗi phần tử có giá trị <=100)
ví dụ:

input:

3

1 2 3

4

1 2 5 7

output:

no
*/

#include <iostream>
using namespace std;

struct Mang 
{
    int n;
    int a[1000];
    public: 
        void operator = (const Mang &m)
        {
            n = m.n;
            for (int i = 0; i < m.n; ++i)
            {
                a[i] = m.a[i];
            }
        }
        int &operator [] (int i)
        {
            return a[i];
        }
};

istream &operator >> (istream &is, Mang &m)
{
    is >> m.n;
    for (int i = 0; i < m.n; ++i)
    {
        is >> m.a[i];
    }
    return is;
}

ostream &operator << (ostream &os, Mang m)
{
    for (int i = 0; i < m.n; ++i)
    {
        os << m.a[i] << " ";
    }
    return os;
}

bool operator == (Mang m1, Mang m2)
{
    if (m1.n == m2.n)
    {
        for (int i = 0; i < m1.n; ++i)
        {
            if (m1.a[i] != m2.a[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator != (Mang m1, Mang m2)
{
    return !(m1 == m2);
}

Mang operator + (Mang m1, Mang m2)
{
    Mang rs;
    if (m1.n > m2.n)
    {
        rs.n = m1.n;
        for (int i = 0; i < m2.n; ++i)
        {
            rs.a[i] = m1.a[i] + m2.a[i];
        }
        for (int i = m2.n; i < m1.n; ++i)
        {
            rs.a[i] = m1.a[i];
        }
    }
    else
    {
        rs.n = m2.n;
        for (int i = 0; i < m1.n; ++i)
        {
            rs.a[i] = m1.a[i] + m2.a[i];
        }
        for (int i = m1.n; i < m2.n; ++i)
        {
            rs.a[i] = m2.a[i];
        }
    }
}


int main()
{
    Mang m1, m2;
    cin >> m1 >> m2;
    if (m1 == m2)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}