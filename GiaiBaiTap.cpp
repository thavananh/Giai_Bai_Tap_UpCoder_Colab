#include <iostream>
using namespace std;

int Tinh_Tong(int n) {
    int tong = 0;
    while (n) 
    {
        tong = tong + n%10;
        n = n/10;
    }   
    return tong;
}

int main(){
    int n;
    cin >> n;
    cout << Tinh_Tong(n);
    system("Pause");
}

