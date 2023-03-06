#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo{
    int tu, mau;
    void operator = (int x){
        tu = x;
        mau = 1;
    }
};
template <typename T>
struct Mang {
	int n;
	T a[100];
	T& operator [] (int i){
		return a[i];
	}
};
istream& operator >> (istream &in, PhanSo &p);
ostream& operator << (ostream &out, PhanSo p);
PhanSo operator + (PhanSo p1, PhanSo p2);
bool operator == (PhanSo p1, PhanSo p2);
bool operator != (PhanSo p1, PhanSo p2);
PhanSo RutGon(PhanSo p);

template <typename T>
istream& operator >> (istream &in, Mang<T> &m);
template <typename T>
ostream& operator << (ostream &out, Mang<T> m);
template <typename T>
T tongPhanTu(Mang<T> m);

int main(){
    Mang<PhanSo> mb;
	cin >> mb;
	cout << tongPhanTu<PhanSo>(mb) << endl;
    return 0;
}
istream& operator >> (istream &in, PhanSo &p){
   in >> p.tu >> p.mau;
   return in;
}
ostream& operator << (ostream &out, PhanSo p){
    out << p.tu << "/" << p.mau << endl;
    return out;
}
PhanSo operator + (PhanSo p1, PhanSo p2){
    PhanSo T;
    T.tu = p1.tu*p2.mau + p2.tu*p1.mau;
    T.mau = p1.mau*p2.mau;
    return RutGon(T);
}
bool operator == (PhanSo p1, PhanSo p2){
    return (p1.tu*p2.mau == p2.tu*p1.mau);
}
bool operator != (PhanSo p1, PhanSo p2){
    return !(p1 == p2);
}
PhanSo RutGon(PhanSo p){
    int a = __gcd(p.tu, p.mau);
    p.tu /= a;
    p.mau /= a;
    return p;
}
template <typename T>
istream& operator >> (istream &in, Mang<T> &m){
	m.n = 0;
	while (in >> m[m.n]) m.n++;
	return in;
}
template <typename T>
ostream& operator << (ostream &out, Mang<T> m){
	for (int i = 0; i < m.n; i++){
		out << m[i] << " ";
	}
	return out;
}
template <typename T>
T tongPhanTu(Mang<T> m){
	T kq;
	kq = 0;
	for (int i = 0; i < m.n; i++){
		kq = kq + m[i];
	}
	return kq;
}