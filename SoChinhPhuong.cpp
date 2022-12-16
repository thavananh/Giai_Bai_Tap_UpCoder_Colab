#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    int flag = 0;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        if (pow(i,2) == n)
        {
            flag++;
            break;
        }
        i++;
    }
    if (flag == 0)
    {
        cout << "no";
    }
    else
    {
        cout << "yes";
    }

}