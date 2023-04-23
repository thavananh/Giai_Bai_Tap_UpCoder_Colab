#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    int max = -999999;
    int min = 999999;
    cin >> a >> b >> c;
    if (max < a)
    {
        max = a;
    }
    if (max < b)
    {
        max = b;
    }
    if (max < c)
    {
        max = c;
    }
    if (min > a)
    {
        min = a;
    }
    if (min > b)
    {
        min = b;
    }
    if (min > c)
    {
        min = c;
    }
    cout << max << " " << min;
}