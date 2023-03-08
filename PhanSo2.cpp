#include <iostream>
using namespace std;

struct MangPhanSo {
    int numberOfElement;
    int a[100];
    int b[100];
};

struct PhanSo {
    int a, b;
};

int gcd(int a, int b) {
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b; 
        }
        else
        {
            b = b % a;
        }
    }
    
    if (a > 0)
    {
        return a;
    }
    return b; 
     
}


istream& operator >> (istream &input, PhanSo &p) {
    input >> p.a >> p.b;
    return input;
}

ostream& operator << (ostream &output, PhanSo p) {
    output << p.a << "/" << p.b;
    return output;
}

bool operator == (PhanSo p1, PhanSo p2) { // có bug ở đây =))
    if (p1.b == p2.b && p1.a == p2.a)
    {
        return true; 
    }
    return false; 
}

bool operator != (PhanSo p1, PhanSo p2) { 
    return !(p1 == p2);
}

PhanSo operator + (PhanSo p1, PhanSo p2) {
    PhanSo rs;
    rs.a = p1.a * p2.b + p1.b * p2.a;
    rs.b = p1.b * p2.b;
    int val_gcd = gcd(rs.a, rs.b);
    rs.a = rs.a / val_gcd;
    rs.b = rs.b / val_gcd;
    return rs;
}

istream& operator >> (istream &input, MangPhanSo &mps) {
    input >> mps.numberOfElement;
    for (size_t i = 0; i < mps.numberOfElement; i++)
    {
        input >> mps.a[i];
        input >> mps.b[i];
    }
    return input; 
}

ostream& operator << (ostream &output, MangPhanSo mps) {
    for (size_t i = 0; i < mps.numberOfElement; i++)
    {
        output << mps.a[i] << "/" << mps.b; 
    }
    return output; 
}

int main() {
    PhanSo p1, p2, p3, p4;
    cin >> p1 >> p2 >> p3;
    p4 = p1 + p2 + p3;
    cout << p4 << endl;
    system("Pause");

    return 0;
}