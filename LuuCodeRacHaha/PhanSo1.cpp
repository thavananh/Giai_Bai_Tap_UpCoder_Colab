#include <iostream>
using namespace std;

int ulcn(int a, int b) {
    while (a != 0 && b != 0)
    {
        if (a > b) {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a > 0)
    {
        return a;
    }
    return b;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b == 0 || d == 0)
    {
        cout << -1;
    }
    else
    {
        int rs_tu = a * d + c *b;
        int rs_mau = b*d;
        int k = ulcn(rs_tu, rs_mau);
        cout << rs_tu / k << "/" << rs_mau / k;
    }
}