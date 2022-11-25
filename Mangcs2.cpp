#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int>v;
    int x;
    while (cin >> x)
    {
        v.push_back(x);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
