#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<long int>a;
    long int x = 0;
    long int n = 0;
    long int temp = 0;
    long int insert = 0;
    long int pos = 0;
    cin >> n;
    if (n == 0)
    {
        return 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    cin >> insert;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] >= insert && a[i + 1] <= insert)
        {
            pos = i + 1;
            break;
        }
    }
    if (pos == 0)
    {
        if (insert > a[0])
        {
            pos = 0;
        }
        else if (insert < a[a.size()])
        {
            pos = a.size() + 1;
        }
        
    }
    a.insert(a.begin() + pos, insert);
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}