#include <iostream>
using namespace std;

class M1C {
    int n;
    int a[10000];
    public:
        friend istream& operator >> (istream &is, M1C &m);
        friend ostream& operator << (ostream &os, M1C m);
        void operator = (const M1C &m);
        M1C operator + (M1C m2);
        bool operator == (M1C m2);
        bool operator != (M1C m2);
        int &operator[](int i);
};

istream& operator >> (istream &is, M1C &m) {
    is >> m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        is >> m.a[i];
    }
    return is;
}

ostream& operator << (ostream &os, M1C m) {
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.a[i] << " ";
    }
    return os;
}

void M1C::operator=(const M1C &m) {
    this->n = m.n;
    for (size_t i = 0; i < this->n; i++)
    {
        this->a[i] = m.a[i];
    }
}

M1C M1C::operator + (M1C m2) {
    if (this->n > m2.n)
    {
        for (size_t i = 0; i < m2.n; i++)
        {
            this->a[i] = this->a[i] + m2.a[i];
        }
        return *this;
    }
    else
    {
        for (size_t i = 0; i < this->n; i++)
        {
            m2.a[i] = m2.a[i] + this->a[i];
        }   
        return m2;
    }
}

bool M1C::operator == (M1C m2) {
    if (this->n != m2.n)
    {
        return false;
    }
    else
    {
        for (size_t i = 0; i < this->n; i++)
        {
            if (this->a[i] != m2.a[i])
            {
                return false;
            }
        }
    }
    return true;   
}

bool M1C::operator != (M1C m2) {
    return !M1C::operator==(m2);
}

int &M1C::operator[](int i) {
    return this->a[i];
}

int main() {
    M1C m1, m2, m3;
    cin >> m1 >> m2;
    cout << m1 + m2;
    system("Pause");
}