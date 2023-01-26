#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cin >> str;
    for (size_t e = 0; e < strlen(str); e++)
    {
        for (size_t s = 0; s <= e; s++)
        {
            cout << str[s];
        }
        cout << endl;
    }
    system("Pause");
}