#include <iostream>
using namespace std;

string deQuy(long long n, string s = "")
{
    if (n == 0)
    {
        return s;
    }
    char c;
    long long k = n % 16;
    if (k >= 10)
    {
        switch (k)
        {
        case 10:
            s = "A" + s;
            break;
        case 11:
            s = "B" + s;
            break;
        case 12:
            s = "C" + s;
            break;
        case 13:
            s = "D" + s;
            break;
        case 14:
            s = "E" + s;
            break;
        case 15:
            s = "F" + s;
            break; 
        default:
            break;
        }
    }
    else
    {
        c = '0' + k;
        s = c + s;
    }
    return deQuy(n/16, s);
}
int main()
{
    long long n;
    cin >> n;
    cout << deQuy(n);
}