#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    queue<char>q;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            q.push(s[i]);
        }
        else
        {
            q.front();
        }
        
    }
}