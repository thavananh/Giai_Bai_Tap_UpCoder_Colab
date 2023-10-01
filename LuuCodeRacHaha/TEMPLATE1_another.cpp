#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<typeinfo>
using namespace std;

struct oxy
{
    int x, y;
};

struct oxyz
{
    int x, y, z;
};

template<typename T>
struct Mang
{
    int n = 0;
    T array[100];
    T &operator[](int i) {
        return array[i];
    }
    public:
        float tinhKhoangCach(Mang<T>m);
};

bool operator < (oxyz a, oxyz b);
bool operator < (oxyz a, oxyz b);

istream& operator >> (istream &is, oxy &a) {
    is >> a.x >> a.y;
    return is;
}

ostream& operator << (ostream &os, oxy a) {
    os << "(" << a.x << "," << a.y << ")";
    return os;
}

istream& operator >> (istream &is, oxyz &a) {
    is >> a.x >> a.y >> a.z;
    return is;
}

ostream& operator << (ostream &os, oxyz a) {
    os << "(" << a.x << "," << a.y << "," << a.z << ")";
    return os;
}



template<typename T>
ostream &operator << (ostream &os, Mang<T>m) {
    if
    sort(m.array, m.array + m.n);
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.array[i] << " ";
    }
    return os;
}

bool operator < (oxy a, oxy b) {
    if (a.x < b.x)
    {
        return true;
    }
    else if (a.x == b.x)
    {
        if (a.y < b.y)
        {
            return true;
        }
    }
    return false;
}

float operator - (oxy a, oxy b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool operator < (oxyz a, oxyz b) {
    if (a.x < b.x)
    {
        return true;
    }
    else if (a.x == b.x)
    {
        if (a.y < b.y)
        {
            return true;
        }
        else if (a.y == b.y)
        {
            if (a.z < b.z)
            {
                return true;
            }
        }
    }
    return false;
}

float operator - (oxyz a, oxyz b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

template<typename T>
float tinhKhoangCach(Mang<T>m) {
    float temp[100][100];
    for (size_t i = 0; i < m.n; i++)
    {
        for (size_t j = i + 1; j < m.n; j++)
        {
            temp[i][j] = m.array[i] - m.array[j];
        }
    }
    float rs = -99999;
    for (size_t i = 0; i < m.n; i++)
    {
        for (size_t j = i + 1; j < m.n; j++)
        {
            if (temp[i][j] > rs)
            {
                rs = temp[i][j];
            }
        }
    }
    return rs;
}

int main() {
    Mang<oxy>m1;
    Mang<oxyz>m2;
    string s1;
    while (cin >> s1)
    {
        if (s1 == "Oxy")
        {
            cin >> m1.array[m1.n];
            m1.n++;
        }
        else
        {
            cin >> m2.array[m2.n];
            m2.n++;
        }
    }
    cout << m1 << '\n';
    cout << m2 << '\n';
    decltype(m1) what_is_this;
    cout << typeid(what_is_this).name() << '\n';
    cout << fixed <<setprecision(3)<< tinhKhoangCach<oxy>(m1) << '\n';
    cout << fixed <<setprecision(3)<< tinhKhoangCach<oxyz>(m2) << '\n';
}