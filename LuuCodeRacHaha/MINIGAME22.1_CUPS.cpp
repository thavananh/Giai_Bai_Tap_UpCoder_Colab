#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[3] = {1, 2, 3};
    int b, c, d, e, f, g;
    cin >> b >> c >> d >> e >> f >> g;
    swap(a[b-1], a[c-1]);
    swap(a[d-1], a[e-1]);
    swap(a[f-1], a[g-1]);
    for (size_t i = 0; i < 3; i++)
    {
        if (a[i] == n)
        {
            cout << i + 1;
            break;
        }
    }
    system("Pause");
}