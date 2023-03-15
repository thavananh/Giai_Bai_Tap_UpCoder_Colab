#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
        
};

int ucln(PhanSo p) {
    int a = p.tu;
    int b = p.mau;
    while (a != 0 && b != 0) {
        if (a > b)
        {
           a = a % b; 
        }
        else
        {
            b = b % a;
        }
         
    }
    if (a > 0) {
        return a;
    }
    else
    {
        return b;
    }
    
}

istream& operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream& operator << (ostream &os, PhanSo p) {
    os << p.tu << p.mau;
    return os;
}

PhanSo operator+(PhanSo p1, PhanSo p2) {
   PhanSo rs;
   rs.tu = p1.tu * p2.mau + p2.tu * p1.mau;
   rs.mau = p1.mau * p2.mau; 
   return rs;
}

PhanSo rutgon(PhanSo p) {

}

template<typename T>
T nhap() {
    int sum = 0;
    int n = 0;
    T a;
    cin >> a;
    return a;
}

int main() {
    char c;
    int a[100];
    PhanSo p[100];
    int sum = 0;
    int i = 0;
    int j = 0;
    while (cin >> c)
    {
        switch (c)
        {
        case 'a':
            a[i] = nhap<int>();
            i++;
            break;
        case 'b':
            p[j] = nhap<PhanSo>();
            j++; 
        default:
            break;
        }
    }
    
    {
       sum = sum + a[k]; 
    }
    
}