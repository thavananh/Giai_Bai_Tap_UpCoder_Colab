#include <iostream>
using namespace std;

class Phanso {
    private:
        int a;
        int b;
    public:
        Phanso();
        Phanso(int, int);
        // void nhap();
        // void xuat();
        // void phansonghichdao();
        // void rutgonphanso();
        // void quydongmauso(int&, int&);
        // void tinhtong();
        int getTuSo();
        int getMauSo();
        void setTuSo(int);
        void setMauSo(int);
        friend int ucln(int, int);
        Phanso rutgon();
        Phanso nghichdao();
        Phanso operator + (Phanso);
        Phanso operator * (Phanso);
        Phanso operator / (Phanso);
        friend istream& operator >> (istream &, Phanso &);
        friend ostream& operator << (ostream &, Phanso );

};

Phanso::Phanso() {
    this->a = this->b = 0;
}

Phanso::Phanso(int a, int b) {
    this->a = a;
    this->b = b;
}

istream& operator >> (istream &is, Phanso &p) {
    is >> p.a >> p.b;
    return is;
}

ostream& operator << (ostream &os, Phanso p) {
    os << p.a << "/" << p.b;
    return os; 
}

int ucln(int a, int b) {
    while (a != 0 && b!= 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a > 0)
    {
        return a; 
    }
    return b;
     
}

int Phanso::getTuSo() {
    return this->a;
}

int Phanso::getMauSo() {
    return this->b;
}

void Phanso::setTuSo(int a) {
   this->a = a; 
}

void Phanso::setMauSo(int b) {
    this->b = b;
}

Phanso Phanso::nghichdao() {
    Phanso rs;
    rs.a = this->b;
    rs.b = this->a;
    return rs;
}

Phanso Phanso::rutgon() {
    Phanso rs;
    int k = ucln(this->a, this->b);
    rs.a = this->a / k;
    rs.b = this->b / k;
    return rs;
}

Phanso Phanso::operator + (Phanso p) {
    Phanso rs;
    rs.a = this->a * p.b + p.a * this->b;
    rs.b = p.b * this->b;
    int k = ucln(rs.a, rs.b);
    rs.a = rs.a / k;
    rs.b = rs.b / k;
    return rs;
}

Phanso Phanso::operator * (Phanso p) {
    Phanso rs;
    rs.a = this->a * p.a;
    rs.b = this->b * p.b;
    int k = ucln(rs.a, rs.b);
    rs.a = rs.a / k;
    rs.b = rs.b / k;
    return rs;
}

// void Phanso::phansonghichdao(){
//     cout << this->b << "/" << this->a << '\n';
// }
// void Phanso::rutgonphanso() {
//     int a = this->a;
//     int b = this->b;
//     int k = ucln(a, b);
//     cout << a/k << "/" << b/k << '\n';
    
// }

// void Phanso::tinhtong() {
//     int a = this->a;
//     int b = this->b;
//     int c = this->b;
//     int d = this->a;
//     int temp1 = a*d + c*b;
//     int temp2 = b * d;
//     int k = ucln(temp1, temp2);
//     cout << temp1/k << "/" << temp2/k << '\n';
// }

int main(){
    Phanso p;
    // p.nhap();
    // p.xuat();
    cin >> p;
    cout << p << '\n';
    cout << p.getTuSo() << '\n';
    cout << p.getMauSo() << '\n';
    cout << p.nghichdao() << '\n';
    cout << p.rutgon() << '\n';
    cout << p + p.nghichdao() << '\n';
    // p.phansonghichdao();
    // p.rutgonphanso();
    // p.tinhtong();
    system("Pause");

}