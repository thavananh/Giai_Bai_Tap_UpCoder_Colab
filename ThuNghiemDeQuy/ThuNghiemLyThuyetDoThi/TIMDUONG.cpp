#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEgde(vector<vector<int>>&m_adj, int u, int v)
{
    m_adj[u].push_back(v);
    m_adj[v].push_back(u);
}

void BFS(vector<vector<int>>m_adj, int s, vector<int>&count, int end)
{
    queue<int>q;
    vector<bool>visited(5, false);
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
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
    int dinh, canh, s, e;
    cin >> dinh >> canh >> s >> e;
    vector<vector<int>>m_adj(1000);
    vector<bool>flag(100, false);
    int count = 0;
    for (size_t i = 0; i < canh; i++)
    {
        int a, b;
        cin >> a >> b;
        addEgde(m_adj, a, b);
    }
    
    return 0;
}