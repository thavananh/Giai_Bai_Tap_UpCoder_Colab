#include <iostream>
using namespace std;

struct BacNhat {
    int a, b;   
    public:
        friend int tinhgiatri(int a, int b);
};

istream& operator >> (istream &inp, BacNhat &bn) {
    inp >> bn.a >> bn.b;
    return inp;
}

ostream& operator << (ostream &output, BacNhat bn) {
    output << bn.a << "x + " << bn.b;
    return output;
}

int tinhgiatri(BacNhat bn, int x) {
    return bn.a * x + bn.b;
} 

BacNhat operator + (BacNhat bn1, BacNhat bn2) {
    BacNhat rs;
    rs.a = bn1.a + bn2.a;
    rs.b = bn1.b + bn2.b;
    return rs; 
}

int main() {

}