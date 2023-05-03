#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

struct Date {
    string ngay, thang, nam;
    public:
        bool namNhuan();
        int ngayTrongNam();
        string thuTrongNam();
        Date ngayKeTiep();
        friend bool trungThu(Date d1, Date d2);
};

istream &operator >> (istream &is, Date &d) {
    is >> d.ngay >> d.thang >> d.nam;
    return is;
}

ostream &operator << (ostream &os, Date d) {
    os << d.ngay << "/" << d.thang << "/" << d.nam;
    return os;
}

bool Date::namNhuan() {
    int nam_int = stoi(nam);
    if ((nam_int % 4 == 0 || nam_int % 400 == 0) && nam_int % 100 != 0)
    {
        return true;
    }
    return false;
}

int travesongaytrongthang(int thang, bool nhuan) {
    if (nhuan == true)
    {
        switch (thang)
        {
        case 1:
            return 31;
            break;
        case 2:
            return 29;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (thang)
        {
        case 1:
            return 31;
            break;
        case 2:
            return 28;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
        default:
            break;
        }
    }
    return 0;
}

int Date::ngayTrongNam() {
    int nam_int = stoi(nam);
    int thang_int = stoi(thang);
    int ngay_int = stoi(ngay);
    int sum = 0;
    bool namnhuan = namNhuan();
    sum = sum + ngay_int;
    thang_int--;
    while (thang_int)
    {
        if (namnhuan)
        {
            sum = sum + travesongaytrongthang(thang_int, namnhuan);
            thang_int--;
        }
        else
        {
            sum = sum + travesongaytrongthang(thang_int, namnhuan);
            thang_int--;
        }
    }
    return sum;
}

string Date::thuTrongNam() {
    int nam_int = stoi(nam);
    int thang_int = stoi(thang);
    int ngay_int = stoi(ngay);
    double n;
    string rs;
    if (thang_int > 2)
    {
        n = (ngay_int + 2*thang_int+(3*(thang_int+1)) / 5 + nam_int + (nam_int / 4));
        n = round(n);
        n = (int)n%7;
    }
    switch ((int)n)
    {
    case 0:
        rs = "Sunday";
        break;
    case 1:
        rs = "Monday";
        break;
    case 2:
        rs = "Tuesday";
        break;
    case 3:
        rs = "Wednesday";
        break;
    case 4: 
        rs = "Thursday";
        break;
    case 5:
        rs = "Friday";
        break;
    case 6:
        rs = "Saturday";
        break;
    default:
        break;
    }
    return rs;
}

Date Date::ngayKeTiep() {
    int nam_int = stoi(nam);
    int thang_int = stoi(thang);
    int ngay_int = stoi(ngay);
    ngay_int++;
    Date rs;
    int ngayCuaThang = travesongaytrongthang(thang_int, namNhuan());
    if (ngay_int > ngayCuaThang)
    {
        thang_int++;
        if (thang_int > 12)
        {
            nam_int++;
        }
        ngay_int = 1;
    }
    ostringstream oss_1;
    ostringstream oss_2;
    oss_1 << setw(2) << setfill('0') << ngay_int;
    rs.ngay = oss_1.str();
    oss_2 << setw(2) << setfill('0') << thang_int;
    rs.thang = oss_2.str();
    rs.nam = to_string(nam_int);
    return rs;
}

bool operator == (Date d1, Date d2) {
    return d1.ngayTrongNam() == d2.ngayTrongNam();
}

bool operator < (Date d1, Date d2) {
    return d1.ngayTrongNam() < d2.ngayTrongNam();
}

bool trungThu(Date d1, Date d2) {
    return d1.thuTrongNam() == d2.thuTrongNam();
}

int operator - (Date d1, Date d2) {
    return abs(d1.ngayTrongNam() - d2.ngayTrongNam());
}

int main() {
    Date d1, d2;
    cin >> d1 >> d2;
    cout << d1 << " " << d1.thuTrongNam() << " " << d1.ngayTrongNam() << " " << d1.ngayKeTiep() << " ";
    if (d1.namNhuan())
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    cout << d2 << " " << d2.thuTrongNam() << " " << d2.ngayTrongNam() << " " << d2.ngayKeTiep() << " ";
    if (d2.namNhuan())
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (trungThu(d1, d2)) 
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (d1 == d2)
    {
        cout << "1 = 2" << '\n';
    }
    else if (d1 < d2)
    {
        cout << "1 < 2" << '\n';
    }   
    else
    {
        cout << "1 > 2" << '\n';
    }
    cout << d1 - d2;
}