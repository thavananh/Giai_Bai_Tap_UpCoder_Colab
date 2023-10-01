#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max = -9999999;
    int min = 9999999;
    while (n)
    {
        if (n % 10 > max)
        {
            max = n % 10;
        }
        if (n % 10 < min)
        {
            min = n % 10;
        }
        n = n / 10;
    }
    cout << max + min;
}