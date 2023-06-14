#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

struct SC
{
    int a;
};

istream& operator >> (istream& is, SC& sc)
{
    is >> sc.a;
    return is;
}
ostream& operator << (ostream& os, SC& sc)
{
    string s = to_string(sc.a);
    for (int i = 0; i < s.size(); i += 2)
    {
        os << s[i];
    }
    return os;
}
bool operator < (SC sc1, SC sc2)
{
    string s1 = to_string(sc1.a);
    string s2 = to_string(sc2.a);
    if (s1.size() < s2.size() && abs((int)s1.size() - (int)s2.size()) > 1)
    {
        return true;
    }
    if (s1.size() > s2.size() && abs((int)s1.size() - (int)s2.size()) > 1)
    {
        return false;
    }
    int a = 0, b = 0;
    for (int i = 0; i < s1.size(); i += 2)
    {
        string temp = "";
        temp += s1[i];
        a += stoi(temp);
        a *= 10;
    }
    for (int i = 0; i < s2.size(); i += 2)
    {
        string temp = "";
        temp+= s2[i];
        b += stoi(temp);
        b *= 10;
    }
    return a/10 < b/10;
}

int tongThanhPhan(SC sc, int k = 0)
{
    string s1 = to_string(sc.a);
    int rs = 0;
    if (k == 0)
    {
        for (int i = 0; i < s1.size(); i += 2)
        {
            string temp = "";
            temp += s1[i];
            rs += stoi(temp);
        }
    }
    else
    {
        for (int i = 1; i < s1.size(); i += 2)
        {
            string temp = "";
            temp += s1[i];
            rs += stoi(temp);
        }
    }
    return rs;
}

int main()
{
    SC sc1, sc2;
    int k;
    cin >> sc1 >> sc2;
    cin >> k;
    cout << sc1 << '\n' << sc2 << '\n';
    if (sc1 < sc2)
    {
        cout << "true" << '\n';
    }
    else
    {
        cout << "false" << '\n';
    }
    cout << tongThanhPhan(sc1, k) << '\n';
    cout << tongThanhPhan(sc2, k) << '\n';
}