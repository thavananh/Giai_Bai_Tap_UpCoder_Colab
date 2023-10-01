#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
    int m = sqrt(n);
    for (size_t i = 3; i <= m; i = i + 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
        
    }
    if (n > 2)
    {
        cout << n << " ";
    }
    system("Pause");
    
}