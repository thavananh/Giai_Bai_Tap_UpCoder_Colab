#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a > 0)
    {
        cout << a;
    }
    else
    {
        cout << b;
    }
}