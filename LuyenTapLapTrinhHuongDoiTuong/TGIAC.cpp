#include <iostream>
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

float Diem::khoangCach() {

}

int main() {

}