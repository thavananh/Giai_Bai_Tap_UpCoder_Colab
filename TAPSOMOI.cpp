#include <iostream>
using namespace std;

class TapSoMoi {
    int x, y, z, t;
    public:
        TapSoMoi(int x = 0, int y = 0, int z = 0, int t = 0);
        TapSoMoi(const TapSoMoi &ts);
        friend istream& operator >> (istream &is, TapSoMoi &ts);
        friend ostream& operator << (ostream &os, TapSoMoi ts);
        

};

int main() {

}