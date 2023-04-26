#include <iostream>
using namespace std;

int main() {
    int AB, BC, CA, t;
    int count_1 = 0, count_2 = 0, count_3 = 0;
    cin >> AB >> BC >> CA >> t;
    while (t > 0)
    {
        if (t > 0)
        {
            t = t - AB;
            count_1++;
        }
        if (t > 0) 
        {
            t = t - BC;
            count_2++;
        }
        if (t > 0) 
        {
            t = t - CA;
            count_3++;
        }
    }
    if (t == 0)
    {
        if (count_1 > count_2)
        {
            cout << "B" << '\n';
        }
        else if (count_2 > count_3 && count_2 == count_1)
        {
            cout << "C" << '\n';
        }
        else
        {
            cout << "A" << '\n';
        }
    }
    else
    {
        if (count_1 > count_2 && count_1 > count_3)
        {
            cout << "AB" << '\n';
        }
        else if (count_2 > count_3 && count_2 == count_1)
        {
            cout << "BC" << '\n';
        }
        else
        {
            cout << "CA" << '\n';
        }
    }
}