#include <iostream>
#include <vector>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>v1;
    for (size_t i = 0; i < n; i++)
    {
        int x; cin >> x;
        v1.push_back(x);
    }
    cin.ignore();
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