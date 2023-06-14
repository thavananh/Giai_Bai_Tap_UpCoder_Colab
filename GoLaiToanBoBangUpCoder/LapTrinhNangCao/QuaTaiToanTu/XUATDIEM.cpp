#include <iostream>
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
bool operator == (Diem d1, Diem d2)
{
    return d1.x == d2.x && d1.y == d2.y;
}
bool operator < (Diem d1, Diem d2)
{
    if (d1.x < d2.x)
    {
        return true;
    }
    if (d1.x == d2.x)
    {
        if (d1.y < d2.y)
        {
            return true;
        }
    }
    return false;
}
Diem operator + (Diem d1, Diem d2)
{
    Diem rs;
    rs.x = d1.x + d2.x;
    rs.y = d1.y + d2.y;
    return rs;
}

int main()
{
    Diem d[1000];
    int n = 0;
    while (cin >> d[n])
    {
        n++;
    }
    Diem _max = d[0];
    Diem tong = d[0];
    for (int i = 1; i < n; i++)
    {
        if (_max < d[i])
        {
            _max = d[i];
        }
        tong = tong + d[i];
    }
    cout << _max << '\n' << tong;
}