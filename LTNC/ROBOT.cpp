#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int n;
int a[100][100];
int so_o_di_qua = 0;

void _thu(int i, int j, int k) 
{
    if (i == n - 1 && j == n - 1) 
    {
        so_o_di_qua = max(so_o_di_qua, k);
        return;
    }
    if (i + 1 < n && a[i + 1][j] != -1) _thu(i + 1, j, k * 2 + a[i + 1][j]);
    if (j + 1 < n && a[i][j + 1] != -1) _thu(i, j + 1, k * 2 + a[i][j + 1]);
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }    
    
    _thu(0, 0, a[0][0]);
    
    cout << so_o_di_qua << endl;
    
    return 0;
}
