#include <iostream>
using namespace std;

int sodaonguoc(int n) {
    int sum = 0;
    while (n)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int main() {
    int a[1000];
    int n = 0;
    int max = -999999;
    while (cin >> a[n])
    {
        n++;
    }
    for (size_t i = 0; i < n; i++)
    {
        int temp = sodaonguoc(a[i]);
        if (n > max)
        {
            max = n;
        }
    }
    cout << max;
}