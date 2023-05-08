#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long count = 0;
    long long luong = 1000000;
    while (n--)
    {
        string str = to_string(n);
        char c = '1';
        size_t pos = str.find(c);
        if (pos != string::npos)
        {
            count++;
        }
    }
    cout << luong * count;
}