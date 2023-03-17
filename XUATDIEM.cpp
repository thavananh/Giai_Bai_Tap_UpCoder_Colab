#include <iostream>
#include <map>
using namespace std;

struct XuatDiem {
    int x, y;
};

struct M1C_Diem {
    int n;
    struct XuatDiem d[100];
    public:
        XuatDiem timmax(M1C_Diem md);
        XuatDiem tong(M1C_Diem md);
};

istream& operator >> (istream &is, XuatDiem &d) {
    is >> d.x >> d.y;
    return is;
}

ostream& operator << (ostream &os, XuatDiem d) {
    os << "(" << d.x << "," << d.y << ")";
    return os;
}

bool operator == (XuatDiem d1, XuatDiem d2) {
    if (d1.x == d2.x && d1.y == d2.y)
    {
        return true;
    }
    return false;
    
}

bool operator < (XuatDiem d1, XuatDiem d2) {
    if (d1.x < d1.y)
    {
        return true;
    }
    else if (d1.x == d2.x)
    {
        if (d1.y < d2.y)
        {
            return true;
        }
        
    }
    return false;
}

XuatDiem operator + (XuatDiem d1, XuatDiem d2) {
    XuatDiem rs;
    rs.x = d1.x + d2.x;
    rs.y = d1.y + d2.y;
    return rs;
}

istream& operator >> (istream &is, M1C_Diem &md) {
    md.n = 0;
    while (cin >> md.d[md.n])
    {
        md.n++;
    }
    return is;
}

ostream& operator << (ostream &os, M1C_Diem md) {
    for (size_t i = 0; i < md.n; i++)
    {
        cout << md.d[i] << '\n';
    }
    return os;
}

XuatDiem tong (M1C_Diem md) {
    XuatDiem rs;
    rs.x = 0;
    rs.y = 0;
    for (size_t i = 0; i < md.n; i++)
    {
        rs.x = rs.x + md.d[i].x;
        rs.y = rs.y + md.d[i].y;
    }
    return rs;
}

XuatDiem timmax(M1C_Diem md) {
    XuatDiem rs;
    map<int, int> mp1;
    for (int i = 0; i < md.n; ++i)
    {
        int x = md.d[i].x;
        mp1[x]++;
    }
    auto it = mp1.rbegin();
    rs.x = it->first;
    int temp = 0;
    int count = 0;
    for (int i = 0; i < md.n; i++) {
        if (count > 0) {
            if (md.d[i].x == rs.x) {
                if(md.d[i].y > md.d[temp].y) {
                    temp = i;
                    rs.y = md.d[i].y;
                }
            }
        }
        else {
            if (md.d[i].x == rs.x) {
                count++;
                temp = i;
                rs.y = md.d[i].y;
            }
        }
    } 
    return rs;
}

int main() {
   M1C_Diem md;
   cin >> md;
   cout << timmax(md) << '\n';
   cout << tong(md);
}