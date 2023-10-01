#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string>trunglap;
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        string tmp;
        vector<string>s_vec;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> tmp)
        {
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            s_vec.push_back(tmp);
        }
        trunglap.push_back(s_vec.back());
        int count = 0;
        for (auto it : trunglap)
        {
            if (s_vec.back() == it)
            {
                count++;
            }
        }
        string rs = "";
        rs += s_vec.back();
        for (int i = 0; i < s_vec.size() - 1; i++)
        {
            rs += s_vec[i][0];
        }
        if (count > 1)
        {
            rs += to_string(count);
        }
        rs += "@gmail.com";
        cout << rs;
        cout << '\n';
    }
}