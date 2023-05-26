#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEgde(vector<vector<int>>&m_adj, int u, int v)
{
    m_adj[u].push_back(v);
}

void BFS(vector<vector<int>>m_adj, int s)
{
    queue<int>q;
    vector<bool>visited(5, false);
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int k : m_adj[v])
        {
            if (!visited[k])
            {
                q.push(k);
                visited[k] = true;
            }
        }
    }
}

int main()
{
    vector<vector<int>>m_adj(5, vector<int>());
    addEgde(m_adj, 0, 1);
    addEgde(m_adj, 0, 3);
    addEgde(m_adj, 1, 2);
    addEgde(m_adj, 3, 2);
    addEgde(m_adj, 3, 4);
    BFS(m_adj, 0);
    system("pause");
    return 0;
}