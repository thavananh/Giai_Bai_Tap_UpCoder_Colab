#include <iostream>
#include <vector>
using namespace std;

// gap o true khong dem :D

void dfs(vector<vector<int>>&board, vector<vector<bool>>&flag, int i, int j, int &solananrau) 
{
    flag[i][j] = true;
    if (i > 0 && !flag[i-1][j] && board[i-1][j] == 0)
    {
        solananrau++;
        dfs(board, flag, i-1, j, solananrau);
    }
    if (j > 0 && !flag[i][j-1] && board[i][j-1] == 0)
    {
        solananrau++;
        dfs(board, flag, i, j-1, solananrau);
    }
    if (i < board.size() - 1 && !flag[i+1][j] && board[i+1][j] == 0)
    {
        solananrau++;
        dfs(board, flag, i+1, j, solananrau);
    }
    if (j < board[0].size() - 1 && !flag[i][j+1] && board[i][j+1] == 0)
    {
        solananrau++;
        dfs(board, flag, i, j+1, solananrau);
    }
}

int ketqua(vector<vector<int>>&board, vector<vector<bool>>&flag, int y, int x) 
{
    int solananrau = 1;
    dfs(board, flag, y, x, solananrau);
    return solananrau;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> y >> x;
    vector<vector<bool>>flag(n, vector<bool>(m, false));
    vector<vector<int>>board(n, vector<int>(m));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << ketqua(board, flag, y-1, x-1);
}