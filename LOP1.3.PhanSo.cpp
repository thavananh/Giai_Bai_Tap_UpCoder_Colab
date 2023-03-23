#include <iostream>
using namespace std;

class SinhVien {
    float d[10];
    string ten, msv;
    int n = 0;
    public:
        friend istream &operator >> (istream &is, SinhVien &sv);
        friend ostream &operator << (ostream &os, SinhVien sv);
        int dTB(SinhVien sv);
};

class MangSinhVien {
    int n = 0;
    SinhVien sv[100]; 
    SinhVien &operator[](int i) {
        return sv[i];
    }
    
    public:
        MangSinhVien(int n, SinhVien sv[] = new SinhVien{});
        MangSinhVien(const MangSinhVien &m);
        ~MangSinhVien();
        friend istream &operator >> (istream &is, MangSinhVien &m);
        friend ostream &operator << (ostream &os, MangSinhVien m);
};

istream &operator >> (istream &is, SinhVien &sv) {
    cin.ignore();
    getline(is, sv.ten);
    is >> sv.msv;
    while (is >> sv.d[sv.n])
    {
        sv.n++;
    }
    return is;
}

istream &operator >> (istream &is, MangSinhVien &m) {
    is >> m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        is >> m.sv[i];
    }
    return is;
}

int SinhVien::dTB(SinhVien sv) {
    int rs = 0;
    for (size_t i = 0; i < sv.n; i++)
    {
        rs = rs + d[i];
    }
    return rs / sv.n;
}

ostream &operator << (ostream &os, SinhVien sv) {
    os << sv.ten << '\n';
    os << sv.msv << '\n';
    os << sv.dTB(sv);
    return os;
}

ostream &operator << (ostream &os, MangSinhVien msv) {
    for (size_t i = 0; i < msv.n; i++)
    {
        os << msv.sv[i];
    }
    return os; 
}



int main() {

}