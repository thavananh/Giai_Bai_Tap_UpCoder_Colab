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
    int count = 0;
    cin >> n;
    for (size_t i = 2; i <= n; i++)
    {
        if (snt(i))
        {
            cout << i << " ";
            count++;
        }
    }
    if (count == 0)
    {
        cout << -1;
    }
}