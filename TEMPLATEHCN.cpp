#include <iostream>
using namespace std;

struct HCN
{
    int chieudai, chieurong;
};

template<typename T>
struct Mang
{
    int n = 0;
    T array[100];
    T &operator[](int i) {
        return array[i];
    }
};

istream &operator >> (istream &is, HCN &a) {
    is >> a.chieudai >> a.chieurong;
    return is;
}

ostream &operator << (ostream &os, HCN a) {
    os << a.chieudai << a.chieurong;
}

int main() {

}