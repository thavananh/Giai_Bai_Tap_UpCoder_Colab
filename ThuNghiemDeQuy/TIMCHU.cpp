#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<char>>board, string word, vector<vector<bool>>&flag, long long idx, long long i, long long j)
{
    if (idx == word.length()-1)
    {
        return true;
    }
    flag[i][j] = true;
    if (i > 0 && !flag[i-1][j] && board[i-1][j] == word[idx])
    {
        
    }
    
}

bool exist(vector<vector<char>>board, string word, vector<vector<bool>>&flag, long long n, long long m, long long x, long long y)
{
    
    for (size_t i = x; i < m; i++)
    {
        for (size_t j = y; j < n; j++)
        {
            if (board[i][j] == word[0] && search(board, word, flag, 0, i, j))
            {
                return true;
            }
            
        }
    }
    return false;
    
}

int main()
{
    long long m, n, x, y;
    cin >> m >> n >> x >> y;
    string word;
    cin >> word;
    vector<vector<char>>board;
    vector<vector<bool>>flag(m, vector<bool>(n, false));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
        
    }
    
}