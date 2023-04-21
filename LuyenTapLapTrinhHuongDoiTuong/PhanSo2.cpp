#include <iostream>
using namespace std;

class PhanSo {
    int tu, mau;
    public:
        PhanSo(int tu = 0, int mau = 1);
        friend istream& operator >> (istream &is, PhanSo &ps);
        friend ostream& operator << (ostream &os, PhanSo ps);

};

int main() {
    
}