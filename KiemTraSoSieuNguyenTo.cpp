#include <iostream>
#include <cmath>
using namespace std;

int checksonguyento(int n)
{
   if (n < 2)
   {
       return 0;
   }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


int main() {
    int n;
    int temp = 0;
    int flag = 0;
    cin >> n;
    while (n)
    {
        temp = n;
        if (checksonguyento(temp) == 0)
        {
            flag++;
            break;
        }
        n /= 10;
    }
    if (flag == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}