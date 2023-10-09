#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct GRAPH
{
    int iN;
    int iArr[100][100];
};

void readGraph(GRAPH &g)
{
    ifstream ifAdjMatrix;
    ifAdjMatrix.open("DOTHI.txt");
    if (ifAdjMatrix.is_open())
    {
        ifAdjMatrix >> g.iN;
        for (size_t i = 0; i < g.iN; i++)
        {
            for (size_t j = 0; j < g.iN; j++)
            {
                ifAdjMatrix >> g.iArr[i][j];
            }
        }
        ifAdjMatrix.close();
    }   
}

void dfs(int start, vector<bool>&visited, GRAPH g, vector<int>&pre, vector<int>&post, int &preVar, int &postVar)
{
    visited[start] = true;
    pre[start] = ++preVar;
    cout << start + 1 << " ";
    for (size_t j = 0; j < g.iN; j++)
    {
        if (g.iArr[start][j] != 0 && !visited[j])
        {
            dfs(j, visited, g, pre, post, preVar, postVar);
        }
    }
    post[start] = ++postVar;
}

int main()
{
    GRAPH g;
    readGraph(g);
    vector<bool>visited(g.iN, false); 
    vector<int>pre(g.iN, 0);
    vector<int>post(g.iN, 0);
    int preVar = 0;
    int postVar = 0;
    dfs(0, visited, g, pre, post, preVar, postVar);
    cout << endl;
    for (auto it : pre)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : post)
    {
        cout << it << " ";
    }
    system("pause>0");
}