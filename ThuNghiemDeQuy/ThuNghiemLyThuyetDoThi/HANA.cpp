#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool DFS(vector<vector<int>>board, vector<vector<bool>>&flag, int i, int j, int &socach, set<int>&s, int &quangduong)
{
    flag[i][j] = true;
    s.insert(board[i][j]);
    if (s.size() >= 2 && quangduong == board.size()+board[0].size()-1 && board[i][j] == 0)
    {
        socach++;
        return true;
    }
    if (i > 0 && !flag[i-1][j] && (board[i-1][j] == 1 || board[i-1][j] == 2 || board[i-1][j] == 3 || board[i-1][j] == 0) && DFS(board, flag, i-1, j, socach, s, quangduong))
    {
        quangduong++;
    }
    if (j > 0 && !flag[i][j-1] && (board[i][j-1] == 1 || board[i][j-1] == 2 || board[i][j-1] == 3 || board[i][j-1] == 0) && DFS(board, flag, i, j-1, socach, s, quangduong))
    {
        quangduong++;
    }
    if (i < board.size()-1 && (board[i+1][j] == 1 || board[i+1][j] == 2 || board[i+1][j] == 3 || board[i+1][j] == 0) && DFS(board, flag, i+1, j, socach, s, quangduong))   
    {
        quangduong++;
    }
    if (j < board[0].size()-1 && (board[i][j+1] == 1 || board[i][j+1] == 2 || board[i][j+1] == 3 || board[i][j+1] == 0) && DFS(board, flag, i, j+1, socach, s, quangduong))
    {
        quangduong++;
    }
    flag[i][j] = false;
    quangduong = 0;
    s.clear();
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>board(n, vector<int>(m, 0));
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int socach = 0, quangduong = 0;
    set<int>s;
    if (DFS(board, visited, 0, 0, socach, s, quangduong))
    {
        cout << socach;
    }
    else
    {
        cout << -1;
    }
}