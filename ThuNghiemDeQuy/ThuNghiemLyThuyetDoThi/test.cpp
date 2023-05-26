#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v = 5;      // đỉnh: (0)A, (1)B, 2(C), 3(D), 4(E)
    vector<vector<int>>adj(v);
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(2);
    adj[3].push_back(2);
    adj[3].push_back(4);
    /*
        adj = {
            {1, 3},
            {2},
            {},
            {2, 4}
            {}
        }
    */
    // print neighbours of D 
    cout << "Neighbours of D are";
    for (int v : adj[3])
    {
        cout << v;
    }
    cout << '\n';
}