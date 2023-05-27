#include <iostream>
#include <vector>
using namespace std;

void addEgde(vector<vector<int>>&m_adj, int u, int v)
{
    m_adj[u].push_back(v);
}

void dfs(vector<vector<int>>m_adj, int s, vector<bool>&flag)
{
    flag[s] = true;
    cout << s << " ";
    for (int k : m_adj[s])
    {
        if (!flag[k])
        {
            dfs(m_adj, k, flag);
        }
    }
}

int main()
{
    vector<vector<int>>m_adj(5);
    addEgde(m_adj, 0, 1);
    addEgde(m_adj, 0, 3);
    addEgde(m_adj, 1, 2);
    addEgde(m_adj, 3, 2);
    addEgde(m_adj, 3, 4);
    vector<bool>flag(5, false);
    dfs(m_adj, 0, flag);
    system("pause");
}
