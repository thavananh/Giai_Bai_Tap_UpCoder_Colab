#include<iostream>
using namespace std;

class Diem {
    int n;
    float array[100];
    public:
    Diem(int n = 1, float array[] = new float{1});
    Diem(const Diem &dm);
    ~Diem();
    friend istream& operator >> (istream&, Diem&);
    friend ostream& operator << (ostream&, Diem);
    friend int tBC(Diem);
     int get();
    void set(int);
    float& operator[] (int i) {
        return array[i];
    }
    void operator = (const Diem &d) {
        n = d.n;
        for (size_t i = 0; i < n; i++)
        {
            array[i] = d.array[i];
        }
    }

};

class SinhVien {
    string ten,  msv;
    Diem d;
    public:
        SinhVien(s);
        SinhVien(const SinhVien &sv);
        ~SinhVien();
        friend istream operator >> (istream& , SinhVien&);
        friend ostream operator << (ostream&, SinhVien );
};

SinhVien::SinhVien() {
    this->ten = this->msv = "";
}

SinhVien::SinhVien(const SinhVien &sv) {
    this->ten = sv.ten;
    this->msv = sv.msv;
}

Diem::Diem(int n, float array[]){
        this->n = n;
        for (size_t i = 0; i < n; i++)
        {
            this->array[i] = array[i];
        }
        
}

Diem::Diem(const Diem &dm){
    this->n = dm.n;
    for (size_t i = 0; i < dm.n; i++)
    {
        this->array[i] = array[i];
    }
}
Diem::~Diem() {

}

int Diem::get() {
    return this->n;
}

void Diem::set(int n) {
    this->n = n;
}

istream& operator >> (istream &is, Diem &d) {
    int x;
    d.n = 0;
    while (is >> x)
    {
        d.array[d.n] = x;
        d.n++;
    }
    return is;
}

ostream& operator << (ostream &os, Diem d) {
    for (size_t i = 0; i < d.n; i++)
    {
        os << d.array[i] << " ";
    }
    return os;
}
istream operator >> (istream &is, SinhVien &sv) {
    getline(is, sv.ten);
    getline(is, sv.msv);
    is >> sv.d;
    return is;
}

ostream operator << (ostream &os, SinhVien sv) {
    os << sv.ten << '\n';
    os << sv.msv << '\n';
    os << sv.d;
    return os;
}


int tBC(Diem d) {
    int sum = 0;
    for (size_t i = 0; i < d.n; i++)
    {
        sum = sum + d.array[i];
    }
    return sum / d.n;
}

int main() {
    float a[] = {1, 2};
    Diem d1(2, a);
    cout << d1;
    system("Pause");
}