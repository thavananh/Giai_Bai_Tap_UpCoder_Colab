#include <iostream>
using namespace std;

class PhanSo {
    int tu, mau;
    public:
        istream &operator >> (istream &is, PhanSo &ps);
        ostream &operator << (ostream &os, PhanSo ps);
        
};

int main() {
    
}