#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int BFS(vector<vector<char>>board, vector<vector<bool>>flag, int hangbatdau, int cotbatdau, int hang, int cot)
{
    queue<vector<int>>q;
    q.push({hangbatdau, cotbatdau, 0});
    vector<int>dr = {-1, 1, 0, 0};
    vector<int>dc = {0, 0, -1, 1};
    flag[hangbatdau][cotbatdau] = true;
    while (!q.empty())
    {
        vector<int>hientai = q.front();
        q.pop();
        int hanghientai = hientai[0];
        int cothientai = hientai[1];
        int buocdihientai = hientai[2];
        if (board[hanghientai][cothientai] == 'B')
        {
            return buocdihientai;
        }
        for (int i = 0; i < 4; i++)
        {
            int hangmoi = hanghientai + dr[i];
            int cotmoi = cothientai + dc[i];
            if (hangmoi >= 0 && hangmoi < hang && cotmoi >= 0 && cotmoi < cot && (board[hangmoi][cotmoi] == '.' || board[hangmoi][cotmoi] == 'B') && !flag[hangmoi][cotmoi])
            {
                q.push({hangmoi, cotmoi, buocdihientai+1});
                flag[hangmoi][cotmoi] = true;
            }
        }
    }
    return -1;   
}

int timKiem(vector<vector<char>>board, vector<vector<bool>>&flag, int hang, int cot)
{
    for (size_t i = 0; i < hang; i++)
    {
        for (size_t j = 0; j < cot; j++)
        {
            if (board[i][j] == 'C')
            {
                return BFS(board, flag, i, j, hang, cot);
            }
        }
    }
    return -1;
}

int main()
{
    int hang, cot;
    cin >> hang >> cot;
    vector<vector<char>>board(hang, vector<char>(cot, ' '));
    vector<vector<bool>>flag(hang, vector<bool>(cot, false));
    for (size_t i = 0; i < hang; i++)
    {
        for (size_t j = 0; j < cot; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << timKiem(board, flag, hang, cot);
}