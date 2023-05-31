#include <iostream>
#include <algorithm>

using namespace std;
struct PhanSo{
    int a,b;
    char c;
    void operator = (int x) {
        a = x;
        b = 1;
    }
};
int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

template <typename T>
struct M1C{
    int n;
    T a[100];
    T& operator [] (int i) 
    {
        return a[i];
    }
    void operator = (M1C<T> p) 
    {
        n = p.n;
        for (int i = 0; i < n; i++) 
        {
            a[i] = p[i];
        }
    }
};

istream& operator >> (istream& is, PhanSo &p);
ostream& operator << (ostream& os, PhanSo p);
bool operator == (PhanSo p1, PhanSo p2);
bool operator < (PhanSo p1, PhanSo p2);
bool operator > (PhanSo p1, PhanSo p2);
PhanSo operator + (PhanSo p1, PhanSo p2);
PhanSo rutGon(PhanSo p);

template <typename T>
istream& operator >> (istream& is, M1C<T> &m);
template <typename T>
ostream& operator << (ostream& os, M1C<T> m);
template <typename T>
T Sum(M1C<T> m);
template <typename T>
T Max(M1C<T> m);
template <typename T>
void SapXep (M1C<T> &m, char type = '<');
template <typename T>
M1C<T> operator + (M1C<T> a, M1C<T> b);

int main() {
    char c;
    cin >> c;
    if (c == 'I') 
    {
        M1C<int> a,b;
        cin >> a >> b;
        M1C<int> c = a + b;
        cout << a << endl;
        cout << "MAX 1 = " << Max(a) << endl;
        cout << "SUM 1 = " << Sum(a) << endl;
        SapXep(a);
        for (int i = 0; i < a.n; i++) 
        {
            if (a[i] % 2 == 0) 
            {
                cout << a[i] << " ";
            }
        }
        for (int i = 0; i < a.n; i++) 
        {
            if (a[i] % 2 != 0) 
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
        cout << b << endl;
        cout << "MAX 2 = " << Max(b) << endl;
        cout << "SUM 2 = " << Sum(b) << endl;
        SapXep(b, '>');
        for (int i = 0; i < b.n; i++) 
        {
            if (b[i] % 2 != 0) 
            {
                cout << b[i] << " ";
            }
        }
        for (int i = 0; i < b.n; i++) 
        {
            if (b[i] % 2 == 0) 
            {
                cout << b[i] << " ";
            }
        }
        cout << endl;
        cout << c;
    }
    else if (c == 'F') 
    {
        M1C<PhanSo> a,b;
        cin >> a >> b;
        M1C<PhanSo> c = a + b;
        for (int i = 0; i<a.n;i++) 
        {
            cout << rutGon(a[i]) << " ";
        }
        cout << endl;
        cout << "MAX 1 = " << rutGon(Max(a)) << endl;
        cout << "SUM 1 = " << Sum(a) << endl;
        SapXep(a);
        for (int i = 0; i < a.n; i++) 
        {
            cout << rutGon(a[i]) << " ";
        }
        cout << endl;
        for (int i = 0; i<b.n;i++) 
        {
            cout << rutGon(b[i]) << " ";
        }
        cout << endl;
        cout << "MAX 2 = " << rutGon(Max(b)) << endl;
        cout << "SUM 2 = " << Sum(b) << endl;
        SapXep(b, '>');
        for (int i = 0; i < b.n; i++) 
        {
            cout << rutGon(b[i]) << " ";

        }
        cout << endl;
        cout << c;
    }
    return 0;
}

istream& operator >> (istream& is, PhanSo &p) 
{
    is >> p.a >> p.c >> p.b;
    return is;
}
ostream& operator << (ostream& os, PhanSo p) 
{
    if (p.a == 0) 
    {
        os << 0;
    }
    else if (p.b == 1) 
    {
        os << p.a;
    }
    else {
    os << p.a << "/" << p.b;
    }
    return os;
}
bool operator == (PhanSo p1, PhanSo p2) 
{
    return (p1.a*p2.b == p2.a*p1.b);
}
bool operator > (PhanSo p1, PhanSo p2)
{
    return (p1.a*p2.b > p2.a*p1.b);
}
bool operator < (PhanSo p1, PhanSo p2) 
{
    return (p1.a*p2.b < p2.a*p1.b);
}
PhanSo operator + (PhanSo p1, PhanSo p2) 
{
    PhanSo total;
    total.a = p1.a*p2.b + p2.a*p1.b;
    total.b = p1.b*p2.b;
    return rutGon(total);
}
PhanSo rutGon(PhanSo p) 
{
    int x = gcd(p.a,p.b);
    p.a /= x;
    p.b /= x;
    return p;
}
template <typename T>
T Max(M1C<T> m) 
{
    T max = m[0];
    for (int i = 0; i < m.n; i++) 
    {
        if (m[i] > max) 
        {
            max = m[i];
        }
    }
    return max;
}
template <typename T>
void SapXep (M1C<T> &m, char type) 
{
    if (type == '<') 
    {
       sort(m.a, m.a + m.n);
    }
    else if (type == '>') {
        sort(m.a, m.a + m.n, greater<T>());
    }
}
template <typename T>
istream& operator >> (istream& is, M1C<T> &m) 
{
    is >> m.n;
    for (int i = 0; i < m.n; i++) 
    {
        is >> m[i];
    }
    return is;
}
template <typename T>
ostream& operator << (ostream& os, M1C<T> m) 
{
    for (int i = 0; i < m.n; i++) 
    {
        os << m[i] << " ";
    }
    return os;
}
template <typename T>
M1C<T> operator + (M1C<T> a, M1C<T> b) 
{
    M1C<T> total;
    total.n = a.n;
    if (a.n > b.n) 
    {
        for (int i = b.n; i <= a.n; i++) 
        {
            b.n++;
            b[i] = 0;
        }
    }
    else if (b.n > a.n) 
    {
        total.n = b.n;
        for (int i = a.n; i <= b.n; i++) 
        {
            a.n++;
            a[i] = 0;
        }
    }
    for (int i = 0; i < total.n; i++) 
    {
        total[i] = a[i] + b[i];
    }

    return total;
}
template <typename T>
T Sum(M1C<T> m) 
{
    T kq;
    kq = 0;
    for (int i = 0; i < m.n; i++) 
    {
        kq = kq + m[i];
    }
    return kq;
}
