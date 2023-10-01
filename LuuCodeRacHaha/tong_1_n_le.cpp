#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            sum = sum + i;
        }
    }
    cout << sum;
}