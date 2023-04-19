#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0;
    while (n != 0)
    {
        if ((n % 10) % 2 == 0)
        {
            sum1 = sum1 + n%10;
        }
        else
        {
            sum2 = sum2 + n%10;
        }
        n /= 10;
    }
    cout << sum1 * sum2;
}