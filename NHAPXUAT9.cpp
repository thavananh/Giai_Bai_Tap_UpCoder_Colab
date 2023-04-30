#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n / 1000 == 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout << (n / 1000)%10;
    }
}