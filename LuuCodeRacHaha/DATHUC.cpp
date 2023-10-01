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
    output << bn.a << "x+" << bn.b;
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

bool operator == (BacNhat bn1, BacNhat bn2) {
    if (bn1.a + bn1.b != bn2.a + bn2.b)
    {
       return false; 
    }
    return true;
    
}

int main() {
    int x;
    BacNhat bn1, bn2, bn3;
    cin >> bn1 >> bn2 >> x; 
    cout << bn1 << '\n';
    cout << bn2 << '\n';
    bn3 = bn1 + bn2;
    cout << bn1 << "+" << bn2 << "=" << bn3 << '\n';
    cout << tinhgiatri(bn1, x) << '\n';
    cout << tinhgiatri(bn2, x) << '\n';
    if (bn1 == bn2)
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
    
    
    system("Pause");
}