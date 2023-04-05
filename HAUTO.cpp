#include <iostream>
#include <stack>
using namespace std;


int main() {
    stack<int>stc;
    char c[1000];
    int temp = 0;
    while (scanf("%s", c))
    {
        switch (c[0])
        {
        case '+':
            temp = stc.top();
            stc.pop();
            temp = temp + stc.top();
            stc.pop();
            stc.push(temp);
            break;
        case '-':
            temp = stc.top();
            stc.pop();
            temp = temp - stc.top();
            stc.pop();
            stc.push(temp);
            break;
        case '*':
            temp = stc.top();
            stc.pop();
            temp = temp * stc.top();
            stc.pop();
            stc.push(temp);
            break;
        default:
            int k = atoi(c);
            stc.push(k);
            break;
        }
    }
    cout << stc.top();
    stc.pop();

}