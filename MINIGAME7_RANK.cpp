#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    int option;
    cin >> a >> b >> c >> d >> e >> f >> option;
    if (option == 1)
    {
        if (a + b + c > d + e + f)
        {
            cout << "VN";
        }
        else if (a + b + c < d + e + f) 
        {
            cout << "TL";
        }
        else
        {
            cout << "TIE";
        }
    }
    else
    {
        if (a > d)
        {
            cout << "VN";
        }
        else if (a == d)
        {
            if (b > e)
            {
                cout << "VN";
            }
            else if (b == e) 
            {
                if (c > f)
                {
                    cout << "VN";
                }
                else if (c == f)
                {
                    cout << "TIE";
                }
                else
                {
                    cout << "TL";
                }   
            }
            else
            {
                cout << "TL";
            }
        }
        else
        {
            cout << "TL";
        }
    } 
}