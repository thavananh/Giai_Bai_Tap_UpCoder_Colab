#include <iostream>
#include <cmath>
using namespace std;

bool snt(int n) {
    int m = sqrt(n);
    if (n < 2)
    {
        return false;
    }
    for (size_t i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n)
    {
        int sum = 0;
        while (n)
        {
            if (snt(n%10))
            {
                sum = sum + n % 10;
            }
            n = n / 10;
        }
        cout << sum;
    }
}