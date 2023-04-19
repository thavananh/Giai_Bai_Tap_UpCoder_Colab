#include <iostream>
#include <cmath>
using namespace std;

class ARRINT2 {
    int len;
    int arr[100000];
    public:
        ARRINT2(int len = 0, int arr[] = new int{1});
        ARRINT2(const ARRINT2 &ar);
        ~ARRINT2();
        int getLen();
        void setLen(int len);
        friend istream& operator >> (istream &is, ARRINT2 &ar);
        friend ostream& operator << (ostream &os, ARRINT2 ar);
        ARRINT2 operator - (ARRINT2 ar2);
};

ARRINT2::ARRINT2(int len, int arr[]) {
    this->len = len;
    for (size_t i = 0; i < len; i++)
    {
        this->arr[i] = arr[i];
    }
}

ARRINT2::ARRINT2(const ARRINT2 &ar) {
    this->len = ar.len;
    for (size_t i = 0; i < len; i++)
    {
        this->arr[i] = ar.arr[i];
    }
}

ARRINT2::~ARRINT2() {}

int ARRINT2::getLen() {
    return this->len;
}

void ARRINT2::setLen(int len) {
    this->len = len;
}

istream& operator >> (istream &is, ARRINT2 &ar) {
    for (int i = ar.len - 1; i >= 0; i--)
    {
        is >> ar.arr[i];
    }
    return is;
}

ostream& operator << (ostream &os, ARRINT2 ar) {
    for (size_t i = 0; i < ar.len; i++)
    {
        os << ar.arr[i];
    }
    return os;
}

ARRINT2 ARRINT2::operator- (ARRINT2 ar2) {
    ARRINT2 rs;
    if (this->len > ar2.len)
    {
        rs.len = this->len;
        for (size_t i = 0; i < ar2.len; i++)
        {
            rs.arr[i] = abs(this->arr[i] - ar2.arr[i]);
        }
    }
    else if (this->len < ar2.len)
    {
        rs.len = ar2.len;
        for (size_t i = 0; i < this->len; i++)
        {
            rs.arr[i] = abs(this->arr[i] - ar2.arr[i]);
        }
        rs.arr[rs.len - 1] = this->arr[rs.len - 1];
    }
    else
    {
        rs.len = this->len;
        for (size_t i = 0; i < rs.len; i++)
        {
            rs.arr[i] = abs(this->arr[i] - ar2.arr[i]);
        }
    }
    return rs;
}

int main() {
    ARRINT2 ar1, ar2;
    int ar1_Len, ar2_len;
    cin >> ar1_Len >> ar2_len;
    ar1.setLen(ar1_Len);
    ar2.setLen(ar2_len);
    cin >> ar1 >> ar2;
    cout << ar1 - ar2;
    system("Pause");
}