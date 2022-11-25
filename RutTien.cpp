//

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int sotien, a, b, c, d, e, f;
    cin >> sotien;
    a = sotien / 500000;
    sotien = sotien - (a*500000);
    b = sotien / 200000;
    sotien = sotien - (b*200000);
    c = sotien / 100000;
    sotien = sotien - (c*100000);
    d = sotien / 50000;
    sotien = sotien - (d*50000);
    e = sotien / 20000;
    sotien = sotien - (e*20000);
    f = sotien / 10000;
    sotien = sotien - (f*10000);
    cout <<  a + b + c + d + e + f << "\n";
    if (a > 0)
    {
        cout << a << " " << "500.000" << endl;
    }
    if (b > 0)
    {
        cout << b << " " << "200.000" << endl;
    }
    if (c > 0)
    {
        cout << c << " " << "100.000" << endl;
    }
    if (d > 0)
    {
        cout << d << " " << "50.000" << endl;
    }
    if (e > 0)
    {
        cout << e << " " << "20.000" << endl;
    }
    if (f > 0)
    {
        cout << f << " " << "10.000" << endl;
    }
    return 0;
}