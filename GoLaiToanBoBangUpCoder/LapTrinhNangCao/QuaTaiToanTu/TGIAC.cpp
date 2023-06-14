/*
Yêu cầu 1:  Xây dựng cấu trúc ĐIỂM gồm tung độ và hoành độ (số nguyên)

-      Viết quá tải hàm nhập,xuất điểm

-      Viết hàm tính khoảng cách giữa 2 điểm

-      Viết quá tải so sánh bằng giữa 2 điểm: kiểm tra 2 điểm có trùng nhau không?

Yêu cầu 2: Xây dựng cấu trúc TAMGIAC gồm 3 điểm (PHẢI dựa vào cấu trúc ĐIỂM ở trên)

-      Viết quá tải hàm nhập,xuất (không cần kiểm tra điều kiện của tam giác, giả sư với 3 điểm bất kỳ đều là tam giác)

-      Viết hàm tính chu vi tam giác

-      Quá tải toán tử + hai tam giác (HD: cộng chu vi tam giác)

-      Quá tải toán tử <  dùng để so sánh 2 tam giác (HD: so sánh dựa vào chu vi)

-      Quá tải toán tử so sánh bằng dùng kiểm tra 2 TAM GIÁC có trùng nhau hay không?

Yêu cầu 3: nhập dữ liệu tọa độ của 2 tam giác theo cấu trúc

-      Dòng 1: 3 điểm của tam giác 1

-      Dòng 2: 3 điểm của tam giác 2
Xuất kết quả theo cấu trúc sau:

-      Dòng 1: xuất các tọa độ của tam giác 1

-      Dòng 2: xuất các tọa độ của tam giác 2

-      Dòng 1: ghi TRUE, nếu tam giác 1 < tam giác 2, ngược lại ghi FALSE

-      Dòng 2: ghi TRUE, nếu 2 tam giác trùng nhau, ngược lại ghi FALSE
Input:
1 2 3 4 5 6
7 8 9 0 1 2

 

Output:
(1,2)(3,4)(5,6)
(7,8)(9,0)(1,2)
TRUE
FALSE.
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Diem
{
  int x, y;
};

istream &operator >> (istream &is, Diem &d)
{
    is >> d.x >> d.y;
    return is;
}
ostream &operator << (ostream &os, Diem d)
{
    os << "(" << d.x << "," << d.y << ")";
    return os;
}
double khoangCach(Diem d1, Diem d2)
{
    return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
}
bool operator == (Diem d1, Diem d2)
{
    return d1.x == d2.x && d1.y == d2.y;
}

struct TamGiac
{
    Diem d[3];
};

istream &operator >> (istream &is, TamGiac &tg)
{
    for (int i = 0; i < 3; ++i)
    {
        is >> tg.d[i];
    }
    return is;
}
ostream &operator << (ostream &os, TamGiac tg)
{
    for (int i = 0; i < 3; i++)
    {
        os << tg.d[i];
    }
    return os;
}

double tinhChuVi(TamGiac tg)
{
    return khoangCach(tg.d[0], tg.d[1]) + khoangCach(tg.d[0], tg.d[2]) + khoangCach(tg.d[1], tg.d[2]);
}

bool operator < (TamGiac tg1, TamGiac tg2)
{
    return tinhChuVi(tg1) < tinhChuVi(tg2);
}

bool operator == (TamGiac tg1, TamGiac tg2)
{
    return (tg1.d[0] == tg2.d[0] && tg1.d[1] == tg2.d[1] && tg1.d[2] == tg1.d[2]) || tinhChuVi(tg1) == tinhChuVi(tg2);
}

int main()
{
    TamGiac tg1, tg2;
    cin >> tg1 >> tg2;
    cout << tg1 << '\n' << tg2 << '\n';
    if (tg1 < tg2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (tg1 == tg2)
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
}