#include <iostream>
#include <vector>
using namespace std;

void addEgde(vector<vector<int>>&board, int u, int v)
{
    board[u].push_back(v);
}

void DFS(vector<vector<int>>board, vector<bool>&flag, int s, vector<int>&pretime, vector<int>&posttime, int &time)
{
    flag[s] = true;
    pretime[s] = time++;
    cout << s << " ";
    for (int k : board[s]) 
    {
        if (!flag[k])
        {
            DFS(board, flag, k, pretime, posttime, time);
        }
    }
    posttime[s] = time++;
}


int main()
{
    vector<vector<int>>board(5);
    vector<bool>flag(5, false);
    vector<int>pretime(5);
    vector<int>posttime(5);
    int time = 0;
    addEgde(board, 0, 1);
    addEgde(board, 0, 3);
    addEgde(board, 1, 2);
    addEgde(board, 3, 2);
    addEgde(board, 3, 4);
    DFS(board, flag, 0, pretime, posttime, time);
    cout << '\n';
    for (size_t i = 0; i < 5; i++)
    {
        cout << i << ": " << pretime[i] << "," << posttime[i] << '\n';
    }
    system("pause");
}