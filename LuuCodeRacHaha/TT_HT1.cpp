#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<char>stc;
    queue<char>q;
    char input[1000];
    scanf("%s", input);
    for (int i = 0; input[i] != '\0'; i++) {
        switch(input[i]) {
            case '(':
                stc.push(input[i]);
                break;
            case ')':
                while (!stc.empty() && stc.top() != '(') {
                    q.push(stc.top());
                    stc.pop();
                }
                if (!stc.empty() && stc.top() == '(') {
                    stc.pop();
                }
                break;
            case '-':
            case '+':
                while (!stc.empty() && stc.top() != '(') {
                    q.push(stc.top());
                    stc.pop();
                }
                stc.push(input[i]);
                break;
            case '*':
            case '/': 
                while (!stc.empty() && (stc.top() != '(' && stc.top() != '+' && stc.top() != '-')) {
                    q.push(stc.top());
                    stc.pop();
                }
                stc.push(input[i]);
                break;
            default:
            stc.push(input[i]);
            break;
        }
    }
    while (!stc.empty()) {
        q.push(stc.top());
        stc.pop();
    }
    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }
}