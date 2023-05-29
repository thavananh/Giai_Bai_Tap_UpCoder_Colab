#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long convertSoNP(string s)
{
    int mu = 0;
    int sum = 0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            sum = sum + pow(2, mu);    
        }
        mu++;
    }
    return sum;
}

string search(vector<vector<int>>board, vector<vector<bool>>&flag, int i, int j, int n, string sonhiphan, int pos)
{
    if (j == n)
    {
        return sonhiphan;
    }
    flag[i][j] = true;
    char c = '0' + board[i][j]; 
    sonhiphan = sonhiphan + c;
    if (i < board[0].size() && !flag[i+1][j] && i < pos)
    {

        search(board, flag, i+1, j, n, sonhiphan, pos);

    }
    
}

long long dcm(vector<vector<int>>board, vector<vector<bool>>&flag, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            /* code */
        }
        
    }
    
    
}



int main()
{
    int n;
    cin >> n;
    vector<vector<int>>board(n);
    vector<vector<bool>>(n, vector<bool>(n, false));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    system("pause");
}