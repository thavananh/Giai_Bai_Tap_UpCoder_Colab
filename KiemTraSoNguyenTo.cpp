#include <iostream>
#include <cmath>
using namespace std;

long long songuyento(long long int n);

int main()
{
    long long int n;
    cin >> n;
    if (songuyento(n) == 0)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }
    return 0;
}

long long int songuyento(long long int n)
{
    if (n < 2)
    {
        return 0;
    }
    
    for (long long int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}