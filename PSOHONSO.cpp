#include <iostream>
using namespace std;

struct PhanSo {
    int a, b;
};

istream& operator >> (istream &inp, PhanSo &p) {
    inp >> p.a >> p.b;
}

ostream& operator << (ostream &output, PhanSo p) {
    output << p.a << p.b;
}

bool operator != (PhanSo p1, PhanSo p2) {
    if (p1.b != p2.b |)
    {
        /* code */
    }
    
}

int main() {

}