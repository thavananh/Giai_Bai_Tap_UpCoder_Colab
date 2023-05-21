#include <iostream>
#include <vector>
using namespace std;

void deQuy(vector<vector<int>>& rs, int k, int n, vector<int>&num)
{
    if (num.size() == n)
    {
        rs.push_back(num);
        return;
    }
    for (size_t i = 1; i <= k; i++)
    {
        num.push_back(i);
        deQuy(rs, k, n, num);
        num.pop_back();
    }
    
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<vector<int>> rs;
    vector<int>num;
    deQuy(rs, k, n, num);
    cout << rs.size() << '\n';
    for (const auto& combination : rs)
    {
        for (const auto& num : combination)
        {
            cout << num;
        }
        cout << endl;
    }
    system("Pause");
}