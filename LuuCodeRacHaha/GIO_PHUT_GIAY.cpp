#include <iostream>
using namespace std;

int main() {
    int gio, phut, giay;
    cin >> gio >> phut >> giay;
    if (gio > 24 || phut > 59 || giay > 59)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        giay = giay + 1;
        if (giay == 60)
        {
            giay = 0;
            phut = phut + 1;
            if (phut == 60)
            {
                phut = 0;
                gio = gio + 1;
                if (gio == 24)
                {
                    gio = 0;
                }
            }
        }
    }
    cout << "YES" << '\n';
    cout << gio << ":" << phut << ":" << giay;
}