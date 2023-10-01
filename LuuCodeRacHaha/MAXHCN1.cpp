#include <iostream>
using namespace std;

int main() {
    int n, m;
    int a[10000][10000];
    cin >> n >> m;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << a[i][j];
        }
    }
    
}