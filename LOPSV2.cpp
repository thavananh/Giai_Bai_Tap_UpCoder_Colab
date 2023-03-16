#include<iostream>
using namespace std;

class Diem {
    int n;
    int array[100];
    public:
    Diem();
    Diem(int, int);
    friend istream& operator >> (istream&, Diem&);
    friend ostream& operator << (ostream&, Diem);
    friend int tBC(Diem);
    int& operator[] (int i) {
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

int tBC(Diem d) {
    int sum = 0;
    for (size_t i = 0; i < d.n; i++)
    {
        sum = sum + d.array[i];
    }
    return sum / d.n;
}

int main() {

}