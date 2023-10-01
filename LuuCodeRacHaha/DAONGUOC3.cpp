#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string tmp[1000];
    int i =  0;
    while (ss >> tmp[i])
    {
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << tmp[j] << " ";
    }
    system("Pause");
}