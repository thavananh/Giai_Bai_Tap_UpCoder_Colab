#include <iostream>
#define row 100
#define col 100
using namespace std;
void nhapmang(int a[row][col], int n, int m);
void xuatmang(int a[row][col], int n, int m);

void nhapmang(int a[row][col], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }   
    }
}

void xuatmang(int a[row][col], int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }   
        cout << endl;
    }
}

int main() {
    int a[row][col];
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    nhapmang(a, n, m);
    
    
}