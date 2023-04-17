#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double chuvi, dientich;
    double cao_1, cao_2, cao_3;
    chuvi = a + b + c;
    dientich = pow((chuvi*(chuvi - a)*(chuvi-b)*(chuvi-c)), 1/2);
    cao_1 = 2*dientich/a;
    cao_2 = 2*dientich/b;
    cao_3 = 2*dientich/c;
    cout << chuvi << '\n';
    cout << dientich << '\n';
    cout << cao_1 << '\n';
    cout << cao_2 << '\n';
    cout << cao_3 << '\n';
    return 0;
}