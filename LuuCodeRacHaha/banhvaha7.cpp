#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long>v;
    long long n;
    cin >> n;
    while (n)
    {
        long long a, b;
        char c;
        cin >> a >> c >> b;
        switch (c)
        {
        case '+':
            v.push_back(a+b);
            break;
        case '-':
            v.push_back(a-b);
            break;
        case '*':
            v.push_back(a*b);
            break;
        case '/':
            v.push_back(a/b);
            break;
        default:
            break;
        }
        n--;
    }
    long long k = v.size();
    long long temp = 0;
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = i+1; j < k; j++)
        {
            if (v[i] > v[j])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    for (auto it : v)
    {
        cout << it << '\n';
    }
}