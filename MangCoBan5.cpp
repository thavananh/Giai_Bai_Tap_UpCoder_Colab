#include <iostream>
#include <vector>
#include <cstring>
using namespace std;



int main()
{
    
    vector<string>a;
    string x;
    int i = 1;
    while (cin >> x)
    {
        a.push_back(x);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a.size() > 3)
        {
            if (i == 2 || i == a.size() - 2)
            {
                cout << a[i] << " ";
            }
        }
        else
        {
            cout << a[2] << " " << a[a.size() - 2];
            break;
        }
    }
    
}