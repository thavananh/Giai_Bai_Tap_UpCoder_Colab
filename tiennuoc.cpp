#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int giatien = 0;
    if (n < 51)
    {
        if (n > 16)
        {
            n = n - 17 + 1;
            giatien = giatien + n*8500 + 16*7000; 
        }
        else
        {
            giatien = giatien + n*7000;
        }
        
    }
    else
    {
        int a = n;
        n = n - 51 + 1;
        a = a - n;
        giatien = n*10000;
        if (a > 16 && a < 51)
        { 
            a = a - 17 + 1;
            giatien = giatien + a*8500 + 16*7000;
        }
          
    }
    cout << giatien;
}