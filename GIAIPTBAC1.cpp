#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a== 0 && b == 0)
    {
        cout << "VSN";
    }
    else if (a == 0 && b != 0)
    {
        cout << "VN";
    }
    else
    {
        cout << fixed << setprecision(2) << (float)-b / a;
    }
    
}