#include <iostream>
using namespace std;

int main() { 
    int a;
    char dau;
    int b;
    int c;
    cin >> a >> dau >> b >> c;
    if (dau == '+')
    {
        if (a + b == c)
        {
            cout << "True";
        }
        else
        {
            cout << "False";
        }
    }
    else if (dau == '-')
    {
        if (a - b == c)
        {
            cout << "True";
        }
        else
        {
            cout << "False";
        }
    }
    else if (dau == '*')
    {
        if (a * b == c)
        {
            cout << "True";
        }
        else
        {
            cout << "False";
        }
    }
    
}