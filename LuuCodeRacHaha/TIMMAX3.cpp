#include <iostream>
using namespace std;

int main() {
    int a[5];
    int max = -999999;
    for (size_t i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < 5; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    cout << max << '\n';
}