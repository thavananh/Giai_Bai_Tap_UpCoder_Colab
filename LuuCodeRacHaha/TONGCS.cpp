#include <iostream>
using namespace std;

int TONGCS(int n) {
    if (n == 0)
    {
        return 0;
    }
    return TONGCS(n / 10) + n%10;
    
}

int main() {
    int n;
    cin >> n;
    cout << TONGCS(n);
    system("Pause");
}