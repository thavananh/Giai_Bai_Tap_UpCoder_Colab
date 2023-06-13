#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maDiTuan(int n, vector<vector<bool>>&flag, int startRow, int startCol)
{
    if (n*n == 1)
    {
        return 1;
    }
    queue<vector<int>>q;
    q.push({startRow, startCol, 0});
    flag[startRow][startCol] == true;
    vector<int>dr = {-1, 1, 1, -1, -2, 2, 2, -2};
    vector<int>dc = {-2, -2, 2, 2, 1, 1, -1 , -1};
    int sobuocdi = 0;
    while (!q.empty())
    {
        vector<int>cur = q.front();
        int currRow = cur[0];
        int currCol = cur[1];
        int curDis = cur[2];
        sobuocdi = curDis;
        for (size_t i = 0; i < 8; i++)
        {
            int newRow = currRow + dr[i];
            int newCol = currCol + dc[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !flag[newRow][newCol]) 
            {
                q.push({newRow, newCol , curDis+1});
                flag[newRow][newCol] = true;
                
            }
        }
    }
    return sobuocdi;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>>flag(n, vector<bool>(n, false));
    cout << maDiTuan(n, flag, n-1, n-1);
}