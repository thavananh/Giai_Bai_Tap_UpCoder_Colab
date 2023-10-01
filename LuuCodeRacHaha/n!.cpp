#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int rs = 1;
    for (size_t i = 2; i <= n; i++)
    {
        rs = rs * i;
    }
    cout << rs;
}