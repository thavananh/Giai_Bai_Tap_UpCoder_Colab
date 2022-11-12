#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>a;
    int x = 0;
    int i = 1;
    while (cin >> x)
    {
        a.push_back(x);
        if (i == n)
        {
            break;
        }
        i++;
    }
    
    for (size_t i = 0; i < n - 1; ++i) {
        int temp = 0;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    int count = 1;
    int temp = -1;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == temp)
        {
            continue;
        }
        else
        {
            cout << a[i] << " - ";
        }
        for (size_t j = i+1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }
        cout << count << "; ";
        count = 1;
        temp = a[i];
    }
}