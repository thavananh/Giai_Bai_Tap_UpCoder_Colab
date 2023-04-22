#include <iostream>
using namespace std;

class BacNhat {
    int a, b;
    public:
        BacNhat(int a = 0, int b = 0);
        BacNhat(const BacNhat &bn);
        ~BacNhat();
        int getA();
        int getB();
        void setA(int a);
        void setB(int b);
        friend istream &operator >> (istream &is, BacNhat &bn);
        friend ostream &operator << (ostream &os, BacNhat bn);
        BacNhat operator + (BacNhat bn2);
        bool operator == (BacNhat bn2);
        int giaTriBacNhat(int x);
};

BacNhat::BacNhat(int a, int b) {
    this->a = a;
    this->b = b;
}

BacNhat::BacNhat(const BacNhat &bn) {
    this->a = bn.a;
    this->b = bn.b;
}

BacNhat::~BacNhat() {}

istream &operator >> (istream &is, BacNhat &bn) {
    is >> bn.a >> bn.b;
    return is;
}

ostream &operator << (ostream &os, BacNhat bn) {
    os << bn.a << "x+" << bn.b;
    return os;
}

BacNhat BacNhat::operator + (BacNhat bn2) {
    BacNhat rs;
    rs.a = this->a + bn2.a;
    rs.b = this->b + bn2.b;
    return rs;
}

bool BacNhat::operator == (BacNhat bn2) {
    return this->a + this->b == bn2.a + bn2.b;
}

int BacNhat::giaTriBacNhat(int x) {
    return this->a * x + this->b;
}

int BacNhat::getA() {
    return this->a;
}

int BacNhat::getB() {
    return this->b;
}

void BacNhat::setA(int a) {
    this->a = a;
}

void BacNhat::setB(int b) {
    this->b = b;
}

int main() {
    BacNhat bn1, bn2;
    int x;
    cin >> bn1 >> bn2 >> x;
    cout << bn1 << '\n';
    cout << bn2 << '\n';
    cout << bn1 << "+" << bn2 << "=" << bn1+bn2 << '\n';
    cout << bn1.giaTriBacNhat(x) << '\n';
    cout << bn2.giaTriBacNhat(x) << '\n';
    if (bn1 == bn2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    system("Pause");
    
}