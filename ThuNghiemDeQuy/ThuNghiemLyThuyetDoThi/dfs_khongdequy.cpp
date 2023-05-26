#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEgde(vector<vector<int>>&m_adj, int u, int v)
{
    m_adj[u].push_back(v);
}

void dfs(vector<vector<int>>m_adj, int s, vector<bool>flag)
{
    stack<int>stc;
    stc.push(s);
    flag[s] = true;
    cout << s << " ";
    while (!stc.empty())
    {
        int v = stc.top();
        bool found = false;
        for (int k : m_adj[v])
        {
            if (!flag[k])
            {
                flag[k] = true;
                cout << k << " ";
                stc.push(k);
                found = true;
                break;
            }
        }
        if (!found)
        {
            stc.pop();
        }
    }
}

int main()
{
    vector<vector<int>>m_adj(5);
    vector<bool>flag(5, false);
    addEgde(m_adj, 0, 3);
    addEgde(m_adj, 0, 1);
    addEgde(m_adj, 1, 2);
    addEgde(m_adj, 3, 2);
    addEgde(m_adj, 3, 4);
    dfs(m_adj, 0, flag);
    system("pause");
}