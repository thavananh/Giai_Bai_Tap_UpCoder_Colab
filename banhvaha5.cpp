#include <iostream>
using namespace std;

int main()
{
    int sogiotre;
    cin >> sogiotre;
    int n;
    cin >> n;
    int a[10000];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        int k = a[i] + sogiotre;
        if (k >= 24)
        {
            k = k - 24;
        }
        cout << k << '\n';
    }
}