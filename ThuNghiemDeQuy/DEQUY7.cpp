#include <iostream>
using namespace std;

long long fibonaci(long long n) {
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibonaci(n-1) + fibonaci(n-2);
}

int main() {
    int n;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        cout << fibonaci(i) << '\n';
    }
}