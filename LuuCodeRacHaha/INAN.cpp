#include <iostream>
using namespace std;

int main() {
    long long t, p, c;
    cin >> t >> p >> c;
    if (t == 1)
    {
        cout << p * c;
    }
    else
    {
        if (p % 2 == 0)
        {
            cout << p/2 * c;
        }
        else
        {
            cout << (p/2 + 1) * c;
        }
    }
}