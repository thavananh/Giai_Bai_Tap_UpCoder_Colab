#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<char>>board, int i, int j, int idx, vector<vector<bool>>&flag, string word, int &pos1, int &pos2)
{
    if (idx == word.size()-1)
    {
        pos1 = i;
        pos2 = j;
        return true;
    }
    flag[i][j] = true;
    if (i > 0 && !flag[i-1][j] && board[i-1][j] == word[idx + 1] && search(board, i-1, j, idx+1, flag, word, pos1, pos2))
    {
        return true;
    }
    if (j > 0 && !flag[i][j-1] && board[i][j-1] == word[idx+1] && search(board, i, j+1, idx+1, flag, word, pos1, pos2))
    {
        return true;
    }
    if (i < board.size() - 1 && !flag[i+1][j] && board[i+1][j] == word[idx+1] && search(board, i+1, j, idx+1, flag, word, pos1, pos2))
    {
        return true;
    }
    if (j < board[0].size()- 1 && !flag[i][j+1] && board[i][j+1] == word[idx+1] && search(board, i, j+1, idx+1, flag, word, pos1, pos2))
    {
        return true;
    }
    flag[i][j] = false;
    return false;
}

bool exist(vector<vector<char>>board, int m, int n, int x, int y, vector<vector<bool>>&flag, string word, int &pos1, int &pos2)
{
    for (size_t i = x; i < m; i++)
    {
        for (size_t j = y; j < n; j++)
        {
            if (board[i][j] == word[0] && search(board, i, j, 0, flag, word, pos1, pos2))
            {
                return true;
            }
            
        }
    }
    return false;
}

int main()
{
    int m, n, x, y, pos1, pos2;
    cin >> m >> n >> x >> y;
    string word;
    cin >> word;
    vector<vector<char>>board(m, vector<char>(n));
    vector<vector<bool>>flag(m, vector<bool>(n, false));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (exist(board, m, n, x, y, flag, word, pos1, pos2))
    {
        cout << "YES" << '\n';
        cout << "(" << pos1 << "," << pos2 << ")";
        return 0;
    }
    cout << "NO";
    return 0;
}