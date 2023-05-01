#include <iostream>
using namespace std;

int tong(int n){
    int m = n / 2;
    int sum = 0;
    for (size_t i = 1; i <= m; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;
    if (tong(a) == tong(b))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}