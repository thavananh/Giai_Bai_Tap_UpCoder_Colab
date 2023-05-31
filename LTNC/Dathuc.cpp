#include <iostream>

using namespace std;

struct BacNhat{
    int a, b;
    
    friend istream &operator >> (istream &is, BacNhat &bn){
        is >> bn.a >> bn.b;
        return is;
    }
    friend ostream &operator << (ostream &os, BacNhat bn){
        os << bn.a << "x";
        if(bn.b>0) os << "+" << bn.b;
        else if(bn.b<0) os << bn.b;
        return os;
    }
    
    int tinh_gia_tri(int x){
        return a*x+b;
    }
};

BacNhat operator + (BacNhat bn1, BacNhat bn2){
    BacNhat tong;
    tong.a = bn1.a + bn2.a;
    tong.b = bn1.b + bn2.b;
    return tong;
}

bool operator == (BacNhat bn1, BacNhat bn2){
    return (bn1.a+bn1.b)==(bn2.a+bn2.b);
}

int main(){
    BacNhat bn1,bn2;
    cin >> bn1 >> bn2;
    int x;
    cin >> x;
    BacNhat tong = bn1 + bn2;
    cout << bn1 << endl;
    cout << bn2 << endl;
    cout << bn1;
    if(bn2.a>0) cout << "+";
    cout << bn2 << "=";
    cout << tong << endl;
    cout << bn1.tinh_gia_tri(x) << endl << bn2.tinh_gia_tri(x) << endl;
    if(bn1==bn2) cout << "TRUE";
    else cout << "FALSE";
}
