#include <iostream>
using namespace std;

class Phanso {
    private:
        int a;
        int b;
    public:
        void nhap();
        void xuat();
        void phansonghichdao();
        void rutgonphanso();
        void quydongmauso(int&, int&);
        void tinhtong();
        int getTuSo();
        int getMauSo();
        friend int ucln(int, int);


};

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

void Phanso::nhap() {
    cin >> this->a;
    cin >> this->b;
}
void Phanso::xuat(){
    cout << this->a << "/" << this->b << '\n';
}

void Phanso::phansonghichdao(){
    cout << this->b << "/" << this->a << '\n';
}
void Phanso::rutgonphanso() {
    int a = this->a;
    int b = this->b;
    int k = ucln(a, b);
    cout << a/k << "/" << b/k << '\n';
    
}

void Phanso::tinhtong() {
    int a = this->a;
    int b = this->b;
    int c = this->b;
    int d = this->a;
    int temp1 = a*d + c*b;
    int temp2 = b * d;
    int k = ucln(temp1, temp2);
    cout << temp1/k << "/" << temp2/k << '\n';

}

int main(){
    Phanso p;
    p.nhap();
    p.xuat();
    cout << p.getTuSo() << '\n';
    cout << p.getMauSo() << '\n';
    p.phansonghichdao();
    p.rutgonphanso();
    p.tinhtong();
    system("Pause");
}