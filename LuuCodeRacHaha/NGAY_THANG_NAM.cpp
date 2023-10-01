#include <iostream>
using namespace std;

int main() {
    int ngay, thang, nam;
    cin >> ngay >> thang >> nam;
    if (nam <= 1990)
    {
        cout << "NO";
        return 0;
    }
    if ((nam % 400 == 0 || nam % 4 == 0) && nam % 100 != 0)
    {
        if (thang == 1 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 2 && ngay <= 29)
        {
            cout << "YES";
        }
        else if (thang == 3 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 4 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 5 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 6 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 7 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 8 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 9 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 10 && ngay <= 31) 
        {
            cout << "YES";
        }
        else if (thang == 11 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 12 && ngay <= 31)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        if (thang == 1 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 2 && ngay <= 28)
        {
            cout << "YES";
        }
        else if (thang == 3 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 4 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 5 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 6 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 7 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 8 && ngay <= 31)
        {
            cout << "YES";
        }
        else if (thang == 9 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 10 && ngay <= 31) 
        {
            cout << "YES";
        }
        else if (thang == 11 && ngay <= 30)
        {
            cout << "YES";
        }
        else if (thang == 12 && ngay <= 31)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}