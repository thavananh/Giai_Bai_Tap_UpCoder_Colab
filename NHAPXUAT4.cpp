#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 2;
    while (count)
    {
        n = n / 10;
        count--;
    }
    if (n == 0)
    {
        cout << -1;
    }
    else
    {
        cout << n % 10;
    }
}