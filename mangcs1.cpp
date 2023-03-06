#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int>v;
    int x;
    int pos = 0;
    cin >> pos;
    int element;
    cin >> element;
    while (cin >> x)
    {
        v.push_back(x);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    if (pos == 0)
    {
        cout << element << " ";
    }
    
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
        if (i == pos-1)
        {
            cout << element << " ";
        }
    }
}
