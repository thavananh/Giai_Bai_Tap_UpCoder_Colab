#include <iostream>
#include <vector>
using namespace std;

void deQuy(long long n, vector<vector<long long>>&rs, vector<long long>&num, vector<bool>&flag)
{
    if (num.size() == n)
    {
        rs.push_back(num);
        return;
    }
    for (size_t i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            flag[i] = true;
            num.push_back(i);
            deQuy(n, rs, num, flag);
            flag[i] = false;
            num.pop_back();
        }
        
    }
    
}

int main()
{
    long long n;
    cin >> n;
    vector<vector<long long>>rs;
    vector<long long>num;
    vector<bool>flag(n+1, false);
    deQuy(n, rs, num, flag);
    for (const auto& combination : rs)
    {
        for (const auto& num : combination)
        {
            cout << num;
        }
        cout << endl;
    }
    system("pause");
}