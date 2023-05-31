#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>>board, string word, long long i, long long j, long long s, vector<vector<bool>>&flag, long long &pos1, long long &pos2)
{
    if (s == word.size() - 1)
    {
        return true;
    }
    flag[i][j] = true;
    
    if (i > 0 && !flag[i-1][j] && board[i-1][j] == word[s+1] && dfs(board, word, i-1, j, s+1, flag, pos1, pos2))
    {
        return true;
    }
    if (j > 0 && !flag[i][j-1] && board[i][j-1] == word[s+1] && dfs(board, word, i, j-1, s+1, flag, pos1, pos2))
    {
        return true;
    }
    if (i < board.size()-1 && !flag[i+1][j] && board[i+1][j] == word[s+1] && dfs(board, word, i+1, j, s+1, flag, pos1, pos2))
    {
        return true;
    }
    if (j < board[0].size() - 1 && !flag[i][j+1] && board[i][j+1] == word[s+1] && dfs(board, word, i, j+1, s+1, flag, pos1, pos2))
    {
        return true;
    }
    pos1 = i;
    pos2 = j;
    flag[i][j] = false;
    return false;
}

bool exist(vector<vector<char>>board, string word, long long m, long n, long x, long y, vector<vector<bool>>&flag, long long &pos1, long long &pos2)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0, flag, pos1, pos2))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    long m, n, x, y;
    cin >> m >> n >> x >> y;
    string z;
    cin >> z;
    vector<vector<char>>board;
    board.resize(m, vector<char>(n));
    long long pos1, pos2;
    vector<vector<bool>>flag(m, vector<bool>(n, false));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (exist(board, z, m, n, x, y, flag, pos1, pos2))
    {
        cout << "YES" << '\n';
        cout << "(" << pos1 << "," << pos2 << ")";
    }
    else
    {
        cout << "NO";
    }
}