#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<char> stc;
    queue<char> hauto;
    char input[1000];
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i])
        {
        case '(':
            stc.push(input[i]);
            break;
        case ')':
            while (!stc.empty() && stc.top() != '(') {
                hauto.push(stc.top());
                stc.pop();
            }
            if (!stc.empty() && stc.top() == '(') {
                stc.pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!stc.empty() && stc.top() != '(') {
                hauto.push(stc.top());
                stc.pop();
            }
            stc.push(input[i]);
            break;
        default:
            hauto.push(input[i]);
            break;
        }
    }

    while (!stc.empty()) {
        hauto.push(stc.top());
        stc.pop();
    }

    while (!hauto.empty()) {
        cout << hauto.front();
        hauto.pop();
    }

    return 0;
}