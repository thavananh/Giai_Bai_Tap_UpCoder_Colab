#include <iostream>
using namespace std;

class ARRINT1 {
    int len;
    int a[1000];
    public:
        ARRINT1(int len = 0, int a[] = new int{0});
        ARRINT1(const ARRINT1 &ar);
        void setLen(int);
        friend istream &operator >> (istream &is, ARRINT1 &ar);
        friend ostream &operator << (ostream &os, ARRINT1 ar);
        ARRINT1 operator + (ARRINT1 ar2);
};

ARRINT1::ARRINT1(int len, int a[]) {
    this->len = len;
    for (size_t i = 0; i < len; i++)
    {
        this->a[i] = a[i];
    }
}

ARRINT1::ARRINT1(const ARRINT1 &ar) {
    this->len = ar.len;
    for (size_t i = 0; i < ar.len; i++)
    {
        this->a[i] = ar.a[i];
    }
    
}

istream &operator >> (istream &is, ARRINT1 &ar) {
    int arrayTemp[1000];
    for (size_t i = 0; i < ar.len; i++)
    {
        is >> arrayTemp[i];
    }
    int j = 0;
    for (int i = ar.len - 1; i >= 0; i--)
    {
        ar.a[j] = arrayTemp[i];
        j++;
    }
    
    return is;
}

ostream &operator << (ostream &os, ARRINT1 ar) {
    for (size_t i = 0; i < ar.len; i++)
    {
        os << ar.a[i];
    }
    return os;
}

void ARRINT1::setLen(int len) {
    this->len = len;
}

ARRINT1 ARRINT1::operator+(ARRINT1 ar2) {
    ARRINT1 rs;
    if (this->len > ar2.len)
    {
        rs.len = this->len;
        for (size_t i = 0; i < ar2.len; i++)
        {
            if (this->a[i] + ar2.a[i] > 10)
            {
                rs.a[i] = this->a[i] + ar2.a[i] - 10;
            }
            else
            {
                rs.a[i] = this->a[i] + ar2.a[i];
            }
        }
        rs.a[rs.len - 1] = this->a[rs.len - 1];
    }
    else
    {
        rs.len = ar2.len;
        for (size_t i = 0; i < this->len; i++)
        {
            if (this->a[i] + ar2.a[i] > 10)
            {
                rs.a[i] = this->a[i] + ar2.a[i] - 10;
            }
            else
            {
                rs.a[i] = this->a[i] + ar2.a[i];
            }
            rs.a[rs.len - 1] = ar2.a[rs.len - 1];
            
        }
    }
    return rs;
    
    
}

int main() {
    int len1, len2;
    ARRINT1 a1, a2;
    cin >> len1 >> len2;
    a1.setLen(len1);
    a2.setLen(len2);
    cin >> a1;
    cin >> a2;
    cout << a1 + a2;
    
    system("Pause");
}