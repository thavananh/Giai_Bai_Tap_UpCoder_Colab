#include <iostream>
using namespace std;

class Phanso {
    private:
        int a;
        int b;
    public:
        void nhap();
        void xuat();
        void nhapmauso();
        void nhaptuso();
        void phansonghichdao();
        void rutgonphanso();
        void quydongmauso(int&, int&);
        void tinhtong();
        int ucln(int&, int&);


};
void Phanso::nhap() {
    cin >> this->a;
    cin >> this->b;
}
void Phanso::xuat(){
    cout << this->a << "/" << this->b << '\n';
}
void Phanso::nhaptuso(){
    int a = 0;
    cin >> a;
    cout << a << '\n';
}
void Phanso::nhapmauso(){
    int b = 0;
    cin >> b;
    cout << b << '\n';
}
void Phanso::phansonghichdao(){
    cout << this->b << "/" << this->a << '\n';
}
void Phanso::rutgonphanso() {
    
}
int main(){

}