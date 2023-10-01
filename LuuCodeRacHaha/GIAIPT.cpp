#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    float delta = pow(b, 2) - 4*a*c;
    if (a == 0)
    {
        if (b == 0 && c == 0)
        {
            cout << "VSN" << '\n';
        }
        else if (b == 0 && c != 0) {
            cout << "VN" << '\n';
        }
        else
        {
            cout << fixed << setprecision(4) << (-c) / b << '\n';
        }
    }
    else
    {
        if (delta < 0)
        {
            cout << "VN" << '\n';
        }
        else if (delta == 0) 
        {
            cout << fixed << setprecision(4) << -b / (2*a) << '\n';
            cout << fixed << setprecision(4) << -b / (2*a) << '\n';
        }
        else
        {
            cout << fixed << setprecision(4) << (-b + sqrt(delta))/(2*a) << '\n';
            cout << fixed << setprecision(4) << (-b - sqrt(delta))/(2*a) << '\n';
        }
    }
}