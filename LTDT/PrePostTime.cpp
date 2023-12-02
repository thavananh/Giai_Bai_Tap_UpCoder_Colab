#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct GRAPH
{
    int iN;
    int iArr[100][100];
    int visited[100];
};

struct CANH
{
    int u, v;
    int trongso;
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

// void dfs(int start, vector<bool>&visited, GRAPH g, vector<int>&pre, vector<int>&post, int &preVar, int &postVar)
// {
//     visited[start] = true;
//     pre[start] = ++preVar;
//     cout << start + 1 << " ";
//     for (size_t j = 0; j < g.iN; j++)
//     {
//         if (g.iArr[start][j] != 0 && !visited[j])
//         {
//             dfs(j, visited, g, pre, post, preVar, postVar);
//         }
//     }
//     post[start] = ++postVar;
// }

CANH T[100];

void Prim(GRAPH g)
{
    //
    int nT = 0;
    for (size_t i = 0; i < g.iN; i++)
    {
        g.visited[i] = 0;
    }
    g.visited[0] = 1;
    while (nT < g.iN - 1)
    {
        CANH canhnhonhat;
        int min = -1;
        for (size_t i = 0; i < g.iN; i++)
        {
            if (g.visited[i] == 0)
            {
                for (size_t j = 0; j < g.iN; j++)
                {
                    if (min == -1 || g.iArr[i][j] < min)
                    {
                        min = g.iArr[i][j];
                        canhnhonhat.u = i;
                        canhnhonhat.v = j;
                        canhnhonhat.trongso = g.iArr[i][j];
                    }

                }

            }
        }
        T[nT] = canhnhonhat;
        nT++;
        g.visited[canhnhonhat.u] = 1;
    }
    
}

int main()
{
    GRAPH g;
    readGraph(g);
    CANH T[100];
}