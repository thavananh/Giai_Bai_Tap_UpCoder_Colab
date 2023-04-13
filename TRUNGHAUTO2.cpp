#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<string>stc;
    char input;
    queue<string>q;
    while (scanf("%s", input) != EOF)
    {
        switch (input[0])
        {
        case "(":
            stc.push(input);
            break;
        case ")":
            while (!stc.empty() && stc.top() != '(')
            {
                q.push(input);
            }
        default:
            break;
        }
    }
    
}