#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
    string Hoten;
    float diem1, diem2, diem3;
};
float tinhDiemTrungBinh(SinhVien sv) 
{
    return (sv.diem1 + sv.diem2 + sv.diem3) / 3;
}
bool operator<(SinhVien sv1, SinhVien sv2) 
{
    return (tinhDiemTrungBinh(sv1) < tinhDiemTrungBinh(sv2));
}
istream& operator>>(istream& is, SinhVien& sv) 
{
    
   
    getline(is, sv.Hoten);
    
    is >> sv.diem1>>sv.diem2>> sv.diem3;
    is.ignore();
    return is;
}
ostream& operator<<(ostream& os, SinhVien sv) 
{
    os << sv.Hoten;
    return os;
}
int main() {
SinhVien sv[1000];
    int n = 0;
    while (cin >> sv[n])
    {
        n++;
    }
SinhVien svMaxDiemTB = sv[0];
    for (int i = 1; i <= n; i++) 
    {
        if (svMaxDiemTB < sv[i]) 
        {
            svMaxDiemTB = sv[i];
        }
    }
cout << svMaxDiemTB ;

    
    return 0;
}