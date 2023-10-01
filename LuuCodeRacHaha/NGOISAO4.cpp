#include <iostream>
using namespace std;

int main() {
    int h;
    cin >> h;
    int temp = 0;
    for (size_t i = 1; i <= h; i++)
    {
        for (size_t j = 1; j <= h*2 - 1; j++)
        {
            if (j >= h - temp && j <= h + temp)
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