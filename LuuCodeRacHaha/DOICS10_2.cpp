#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int>stc;
    int n;
    cin >> n;
    if (n==0)
    {
        cout << 0;
        return 0;
    }
    while (n)
    {
        stc.push(n%2);
        n = n/2;
    }
    while (!stc.empty())
    {
        cout << stc.top();
        stc.pop();
    }
}