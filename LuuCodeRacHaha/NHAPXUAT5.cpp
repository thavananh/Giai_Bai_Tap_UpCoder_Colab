#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int i;
    int n;
    cin >> i >> n;
    int count = 0;
    int temp = n;
    while (temp)
    {
        count++;
        temp = temp / 10;
    }
    if (i >= count || i < 0)
    {
        cout << -1;
    }
    else
    {
        n = n / pow(10, -i + count -1);
        n = n % 10;
        cout << n;
    }
}