#include <iostream>
using namespace std;

int main() {
    int diem[1000];
    int i = 0;
    float dtb = 0;
    float x = 0;
    while (cin >> x)
    {
        if (x == 0)
        {
            break;
        }
        diem[i] = x;
        dtb = dtb + diem[i];
        i++;
    }
    dtb = dtb / i;
    if (dtb < 4)
    {
        cout << "F";
    }
    else if (dtb >= 4 && dtb < 5)
    {
        cout << "D";
    }
    else if (dtb >= 5.5 && dtb < 7)
    {
        cout << "C";
    }
    else if (dtb >= 7 && dtb < 8.5)
    {
        cout << "B";
    }
    else
    {
        cout << "A";
    }
}