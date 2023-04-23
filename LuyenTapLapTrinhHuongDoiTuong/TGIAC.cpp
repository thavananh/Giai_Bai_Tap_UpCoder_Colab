#include <iostream>
#include <cmath>
using namespace std;

class Diem {
    int tungDo;
    int hoanhDo;
    public:
        Diem(int hoanhDo = 0, int tungDo = 0);
        Diem(const Diem &d);
        ~Diem();
        friend istream &operator >> (istream &is, Diem &d);
        friend ostream &operator << (ostream &os, Diem d);
        float khoangCach(Diem d2);
        bool operator == (Diem d2);
};

class TamGiac {
    Diem d1, d2, d3;
    public:
    TamGiac(Diem d1 = Diem(), Diem d2 = Diem(), Diem d3 = Diem());
    TamGiac(const TamGiac &d);
    ~TamGiac();
    friend istream &operator >> (istream &is, TamGiac &tg);
    friend ostream &operator << (ostream &os, TamGiac tg);
    int chuVi();
    int operator + (TamGiac tg2);
    bool operator < (TamGiac tg2);
    bool operator == (TamGiac tg2);
};

Diem::Diem(int tungDo, int hoanhDo) {
    this->hoanhDo = hoanhDo;
    this->tungDo = tungDo;
}

Diem::Diem(const Diem &d) {
    this->hoanhDo = d.hoanhDo;
    this->tungDo = d.tungDo;
}

Diem::~Diem() {}

istream &operator >> (istream &is, Diem &d) {
    is >> d.hoanhDo >> d.tungDo;
    return is;
}

ostream &operator << (ostream &os, Diem d) {
    os << "(" << d.hoanhDo << "," << d.tungDo << ")";
    return os;
}

float Diem::khoangCach(Diem d2) {
    return sqrt(pow(d2.hoanhDo - this->hoanhDo, 2) + pow(d2.tungDo - this->tungDo, 2));
}

bool Diem::operator== (Diem d2) {
    if (this->hoanhDo == d2.hoanhDo && this->tungDo == d2.tungDo)
    {
        return true;
    }
    return false;
}

TamGiac::TamGiac(Diem d1, Diem d2, Diem d3) {
    this->d1 = d1;
    this->d2 = d2;
    this->d3 = d3;
}

TamGiac::TamGiac(const TamGiac &tg) {
    this->d1 = tg.d1;
    this->d2 = tg.d2;
    this->d3 = tg.d3;
}

TamGiac::~TamGiac() {}

istream &operator >> (istream &is, TamGiac &tg) {
    is >> tg.d1 >> tg.d2 >> tg.d3;
    return is;
}

ostream &operator << (ostream &os, TamGiac tg) {
    os << tg.d1 << tg.d2 << tg.d3;
    return os;
}

int TamGiac::operator + (TamGiac tg2) {
    return *this->chuVi() + tg2.chuVi();
}

bool TamGiac::operator < (TamGiac tg2) {

}

bool TamGiac::operator == (TamGiac tg2) {

}

int main() {
    TamGiac tg1, tg2;
    cin >> tg1 >> tg2;
    cout << tg1 << '\n';
    cout << tg2 << '\n';
    system("Pause");
}