#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
};

template<typename T>
struct M1C
{
    int n;
    T array[100];
    T &operator[](int i){
        return array[i];
    }
};


istream& operator >> (istream &is, PhanSo &p) {
    is >> p.tu >> p.mau;
    return is;
}

ostream& operator << (ostream &os, PhanSo p) {
    os << p.tu << "/" << p.mau;
    return os;
}






int main(){
    char c;
    cin >> c;
}