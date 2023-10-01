#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    float sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        sum = sum + 1 / pow(i, 3);
    }
    cout << setiosflags(ios::fixed) << setprecision(3) << sum;
}