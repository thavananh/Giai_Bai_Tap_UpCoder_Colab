#include <iostream>
#include <vector>
using namespace std;

void deQuy(long long n, long long k, vector<vector<long long>>&rs, vector<long long>&num, vector<bool>&flag)
{
    if (num.size() == n)
    {
        rs.push_back(num);
        return;
    }
    for (size_t i = 1; i <= k; i++)
    {
        if (!flag[i])
        {
            flag[i] = true;
            num.push_back(i);
            deQuy(n, k, rs, num, flag);
            num.pop_back();
            flag[i] = false;
        }
    }
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>>rs;
    vector<long long>num;
    vector<bool>flag(n+1, false);
    deQuy(n, k , rs, num, flag);
    for (auto it : rs)
    {
        for (auto num : it)
        {
            cout << num;
        }
        cout << '\n';
    }
}