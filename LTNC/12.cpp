#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int n;
int a[100][100];
int maxVal = 0;

void Try(int i, int j, int val) 
{
    if (i == n - 1 && j == n - 1) 
    {
        maxVal = max(maxVal, val);
        return;
    }
    if (i + 1 < n && a[i + 1][j] != -1) Try(i + 1, j, val * 2 + a[i + 1][j]);
    if (j + 1 < n && a[i][j + 1] != -1) Try(i, j + 1, val * 2 + a[i][j + 1]);
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
    
    Try(0, 0, a[0][0]);
    
    cout << maxVal << endl;
    
    return 0;
}
