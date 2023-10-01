#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sum = a*10 + b*20 + c*30 + d*40;
    if (sum == 0)
    {   
        cout << sum << '\n';
        cout << "Coder So Sinh" << '\n';
    }
    else if (sum >= 1 && sum <= 49) {
        cout << sum << '\n';
        cout << "Coder Lop Mam" << '\n';
    }
    else if (sum >= 50 && sum <= 99) {
        cout << sum << '\n';
        cout << "Coder Lop Choi" << '\n';
    }
    else if (sum >= 100 && sum <= 499) {
        cout << sum << '\n';
        cout << "Coder Lop La" << '\n';
    }
    else if (sum >= 500 && sum <= 999) {
        cout << sum << '\n';
        cout << "Coder Tieu Hoc" << '\n';
    }
    else if (sum >= 1000 && sum <= 1499) {
        cout << sum << '\n';
        cout << "Coder THCS" << '\n';
    }
    else if (sum >= 1500 && sum <= 1999) {
        cout << sum << '\n';
        cout << "Coder THPT" << '\n';
    } 
    else if (sum >= 2000 && sum <= 2499) {
        cout << sum << '\n';
        cout << "Coder Trung Cap" << '\n';
    }
    else if (sum >= 2500 && sum <= 3499) {
        cout << sum << '\n';
        cout  << "Coder Cao Dang" << '\n';
    }
    else if (sum >= 3500 && sum <= 4199) {
        cout << sum << '\n';
        cout << "Coder Dai Hoc" << '\n';
    }
    else if (sum >= 4200 && sum <= 5499) {
        cout << sum << '\n';
        cout << "Coder Thac Si" << '\n';
    }
    else if (sum >= 5500 && sum <= 6999) {
        cout << sum << '\n';
        cout << "Coder Tien Si" << '\n';
    }
    else
    {
        cout << sum << '\n';
        cout << "Coder Giao Su" << '\n';
    }
}