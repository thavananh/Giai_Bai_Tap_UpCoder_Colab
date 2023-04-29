#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[1000];
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] >= a[k-1] && a[i] != 0)
        {
            count++;
        }
    }
    cout << count;
}