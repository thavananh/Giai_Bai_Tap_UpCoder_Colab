#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int n;
    int k = 0;
    int temp = 1;
    cin >> n;
    while (sum < n)
    {
        long i = temp;
        for (; i <= k; i++)
        {
            sum = sum + i;
        }
        temp = i;
        k++;
    }
    if (sum == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}