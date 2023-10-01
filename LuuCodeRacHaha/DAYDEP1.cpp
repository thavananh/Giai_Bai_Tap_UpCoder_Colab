#include <iostream>
using namespace std;

int main() {
    int a[1000];
    int i = 0;
    int x;
    int sum = 0;
    while (cin >> x)
    {
        if (x == 0)
        {
            break;
        }
        a[i] = x;
        sum = sum + a[i];
        i++;
    }
    if (sum % 10 == 0 && )
    {
        cout << "DEP";
    }
    else if (sum % 10 == 5)
    {
        cout << "TRUNGBINH";
    }
    else
    {
        cout << "XAU";
    }
}