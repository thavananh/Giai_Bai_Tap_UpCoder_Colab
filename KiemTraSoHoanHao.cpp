#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    int tempN;
    int temp = 0;
    cin >> n;
    tempN = n;
    for (size_t i = 1; i <= tempN; i++)
    {
        if (tempN % i == 0)
        {
            tempN = tempN / i;
            temp += i;
        }
    }
    if (temp == n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}