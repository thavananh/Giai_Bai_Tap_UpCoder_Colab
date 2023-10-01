#include <iostream>
#include <vector>
#include <map>
using namespace std;

int ucln(int a, int b) {
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a > 0)
    {
        return a;
    }
    else
    {
        return b;
    }
    
    
}

int main() {
    // vector<char>v;
    // map<int, int>mp;
    // char x;
    // while (cin >> x)
    // {
    //     v.push_back(x);
    //     mp[x]++;
    //     if (cin.get() == '\n')
    //     {
    //         break;
    //     }
    // }

    // for (auto it : mp) {
    //     cout << char(it.first) << ":" << it.second << '\n';
    // }

    // system("Pause");
    // int n;
    // cin >> n;
    // int tu[1000];
    // int mau[1000];
    // for (size_t i = 0; i < n; i++)
    // {
    //     cin >> tu[i];
    //     cin >> mau[i];
    // }
    // for (size_t i = 0; i < n; i++)
    // {
    //     int x = ucln(tu[i], mau[i]);
    //     if (tu[i] != 0)
    //     {
    //         if (tu[i] % x == 0 && mau[i] % x == 0)
    //         {
    //             tu[i] = tu[i] / x;
    //             mau[i] = mau[i] / x;
    //         }
    //     }
    // }
    // if (tu[0] / mau[0] > tu[1] / mau[1])
    // {
    //     cout << tu[1] << "/" << mau[1];
    // }
    // else
    // {
    //     cout << tu[0] << "/" << mau[0];
    // }
    int a, b, c, d;
    int temp1, temp2, temp3, temp4;
    cin >> a >> b >> c >> d;
    if (b == 0 || d == 0)
    {
        cout << -1 << endl;
    }
    
    if (b != d)
    {
        a = a * d;
        c = c * b;
        b = b * d;
        d = b;
        a = a + c;
        if (a != 0) {
            int x = ucln(a, b);
            if (a % x == 0 && b % x == 0)
            {
                a = a / x;
                b = b / x;
            }
        }
    }
    else
    {
        a = a + c;
        if (a != 0) {
            int x = ucln(a, b);
            if (a % x == 0 && b % x == 0)
            {
                a = a / x;
                b = b / x;
            }
        }
        
    }
    cout << a << "/" << b << endl;
    

    system("pause");
}