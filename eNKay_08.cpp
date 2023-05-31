#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int x;
    vector<int>s;
    int count = 0;
    while (cin >> x)
    {
        if (x == 0)
        {
            break;
        }
        else if (x < 0)
        {
            s.push_back(x);
            count++;
        }
    }
    vector<bool>test(s.size(), false);
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = i+1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                test[j] = true;
            }
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!test[i])
        {
            cout << s[i] << " ";
        }
    }
    if (count == 0)
    {
        cout << "NOT FOUND";
    }
}