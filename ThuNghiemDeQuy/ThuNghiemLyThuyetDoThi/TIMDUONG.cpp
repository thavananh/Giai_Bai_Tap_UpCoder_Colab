#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEgde(vector<vector<int>>&m_adj, int u, int v)
{
    m_adj[u-1].push_back(v-1);
    m_adj[v-1].push_back(u-1);
}

int BFS(vector<vector<int>>m_adj, int s, int canh, int t)
{
    queue<int>q;
    vector<bool>visited(canh, false);
    vector<int>sum(canh, 0);
    q.push(s-1);
    visited[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (v == t-1)
        {
            return sum[t-1];
        }
        
        for (int k : m_adj[v])
        {
            if (!visited[k])
            {
                sum[k] = sum[v] + 1;
                q.push(k);
                visited[k] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int dinh, canh, s, t;
    cin >> dinh >> canh >> s >> t;
    vector<vector<int>>m_adj(10000);
    for (size_t i = 0; i < canh; i++)
    {
        int a, b;
        cin >> a >> b;
        addEgde(m_adj, a, b);
    }
    cout << BFS(m_adj, s, canh, t);
    return 0;
}