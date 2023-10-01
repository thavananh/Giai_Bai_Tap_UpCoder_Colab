#include <iostream>
using namespace std;

int main() {
    int h;
    cin >> h;
    int temp = 0;
    for (size_t i = 1; i <= h; i++)
    {
        for (size_t j = 1; j <= h * 2 - 1; j++)
        {
            if (i == 1 && j == h)
            {
                cout << "*";
            }
            else if ((i >= 2 && i < h) && (j == h + temp || j == h - temp))
            {
                cout << "*";
            }
            else if (i == h)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        if (i == h)
        {
            break;
        }
        else
        {
            cout << '\n';
        }
        temp++;
    } 
}