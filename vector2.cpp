#include <iostream>
#include <vector>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string tmp;
    int array[100];
    int i = 0;
    while (ss >> tmp)
    {
        array[i] = stoi(tmp);
        i++;
    }
    vector<int>v1;
    int k = 0;
    while (cin >> k)
    {
        v1.push_back(k);
    }
    if (i > 1)
    {
        v1.erase(v1.begin() + array[0], v1.begin() + array[1]);
    }
    else
    {
        if (array[0] == -1) {
            v1.clear();
        }
        else {
            v1.erase(v1.begin() + array[0]);
        }
    }
    if (v1.size() == 0) {
        cout << "empty" << '\n';
    }
    else {
        for (auto it : v1) {
            cout << it << " ";
        }
    }
}