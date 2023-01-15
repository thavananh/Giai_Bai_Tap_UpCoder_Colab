#include <iostream>
using namespace std;

size_t giaithua(int n) {
    size_t value = 1;
    for (size_t i = 2; i <= n; i++)
    {
        value = value * i;
    }
    return value;
}

int main() {
    size_t  n;
    cin >> n;
    size_t  m = giaithua(n);
    size_t  count = 0;
    while (m)
    {
        if (m % 10 == 0)
        {
            count++;
        }
        
        m = m / 10;
    }
    cout << count;
    system("Pause");
    
}