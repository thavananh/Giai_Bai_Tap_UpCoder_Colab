#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
    string ho_ten;
    int a, b, c;
};

istream &operator >> (istream &is, SinhVien &sv) {
    getline(is, sv.ho_ten);
    is >> sv.a >> sv.b >> sv.c;
    is.ignore();
    return is;
}

ostream &operator << (ostream &os, SinhVien sv) {
    os << sv.ho_ten;
    return os;
}

bool operator < (SinhVien sv1, SinhVien sv2) {
    return (sv1.a + sv1.b + sv1.c)/3 < (sv2.a + sv2.b + sv2.c)/3;
}

int main() {
    SinhVien sv[1000];
    int n = 0;
    while (cin >> sv[n])
    {
        n++;
    }
    SinhVien max = sv[0];
    for (int i = 1; i <= n; ++i) {
        if (max < sv[i]) {
            max = sv[i];
        }
    }
    cout << max;
}