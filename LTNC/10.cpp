#include <iostream>
#include <set>
using namespace std;
int main()
{
    set <int> s;
    int x;
    while (1)
    {
        cin >> x;
        if (x)
        {
            if (x < 0 && s.find(x) == s.end())
            {
                cout << x << " ";
                s.insert(x);
            }
        }
        else
            break;
    }
    if (s.size() == 0)
        cout << "NOT FOUND";
    return 0;
}