#include <iostream>
using namespace std;

template<typename T>
struct M1C {
    int n;
    T array[100];
    public:
        int tong();
        void xuat();
        void nhap();
};

template<typename T>
T tong(M1C<T>m) {
    T sum = 0;
   for (size_t i = 0; i < m.n; i++)
   {
        sum = sum + m.array[i];
   }
    return sum;    
}

template<typename T>
void xuat(M1C<T>m) {
    cout << tong(m);
}

template<typename T>
void nhap(M1C<T>m) {
    T x;
    m.n = 0;
    while (cin >> x)
    {
        m.array[m.n] = x;
        m.n++;
    }
    tong(m);
}

int main() {
    M1C<int> m;
    nhap<int>(m);
}