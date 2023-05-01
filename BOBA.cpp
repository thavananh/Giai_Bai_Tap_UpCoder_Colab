#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int sum = 0;
    while (n)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    while (m > 9)
    {
        m = m / 10;
    }
    sum = sum + m;
    if (sum == k)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}