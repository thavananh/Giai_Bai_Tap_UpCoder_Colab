#include <iostream>
#include <tuple>
using namespace std;

class TapSoMoi {
    int x, y, z, t;
    public:
        //Hàm khởi tạo - hàm huỷ
        TapSoMoi(int x = 0, int y = 0, int z = 0, int t = 0);
        TapSoMoi(const TapSoMoi &ts);
        ~TapSoMoi();
        //Hàm get - set
        int getX();
        int getY();
        int getZ();
        int getT();
        void setX(int);
        void setY(int);
        void setZ(int);
        void setT(int);
        //Quá tải toán tử nhập - xuất, quá tải toán tử cộng, quá tải toán tử so sánh bé, quá tải toán tử =, quá tải toán tử ++i và i++
        friend istream& operator >> (istream &is, TapSoMoi &ts);
        friend ostream& operator << (ostream &os, TapSoMoi ts);
        TapSoMoi operator + (TapSoMoi ts);
        friend bool operator < (TapSoMoi ts1, TapSoMoi ts2);
        TapSoMoi& operator = (const TapSoMoi &ts) {
            if (this == &ts)
            {
                return *this;
            }
            this->x = ts.x;
            this->y = ts.y;
            this->z = ts.z;
            this->t = ts.t;
            return *this;
        }
        TapSoMoi& operator++();
        TapSoMoi operator++(int);
};

//Bắt đầu xây dựng hàm của lớp TapSoMoi
TapSoMoi::TapSoMoi(int x, int y, int t, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->t = t;
}

TapSoMoi::TapSoMoi(const TapSoMoi &ts) {
    this->x = ts.x;
    this->y = ts.y;
    this->z = ts.z;
    this->t = ts.t; 
}

TapSoMoi::~TapSoMoi(){}

int TapSoMoi::getX() {
    return this->x;
}

int TapSoMoi::getY() {
    return this->y;
}

int TapSoMoi::getZ() {
    return this->z;
}

int TapSoMoi::getT() {
    return this->t;
}

void TapSoMoi::setX(int x) {
    this->x = x;
}

void TapSoMoi::setY(int y) {
    this->y = y;
}

void TapSoMoi::setZ(int z) {
    this->z = z;
}

void TapSoMoi::setT(int t) {
    this->t = t;
}

istream& operator >> (istream &is, TapSoMoi &ts) {
    is >> ts.x >> ts.y >> ts.z >> ts.t;
    return is;
}

ostream& operator << (ostream &os, TapSoMoi ts) {
    os << "[TapSoMoi] "<< ts.x << ";" << ts.y << ";" << ts.z << ";" << ts.t;
    return os;
}

TapSoMoi& TapSoMoi::operator++() {
    ++this->x;
    ++this->t;
    return *this;
}

TapSoMoi TapSoMoi::operator++(int) {
    TapSoMoi temp = *this;
    this->x++;
    this->t++;
    return temp;
}

TapSoMoi TapSoMoi::operator+ (TapSoMoi ts) {
    TapSoMoi rs;
    rs.x = this->x + ts.x;
    rs.y = this->y + ts.y;
    rs.z = this->z + ts.z;
    rs.t = this->t + ts.t;
    return rs;
}

bool operator < (TapSoMoi ts1, TapSoMoi ts2) {
    return (ts1.x + ts1.y + ts1.z + ts1.t) < (ts2.x + ts2.y + ts2.t +ts2.z);
}

int main() {
    TapSoMoi ts1, ts2, ts3;
    cin >> ts1;
    cin >> ts2;
    cout << ts1 << '\n';
    cout << ts2 << '\n';
    if (ts1 < ts2) {
        cout << "true" << '\n';
    }
    else {
        cout << "false" << '\n';
    }
    ts3 = ts1 + ts2;
    cout << ts3 << '\n';
    ts1++;
    cout << ts1 << '\n';
    system("Pause");
}