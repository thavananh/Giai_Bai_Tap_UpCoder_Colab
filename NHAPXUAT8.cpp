#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << fixed << setprecision(1) << (float)(a+b+c) / (d+e+f);
}