#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = ((n/1000)%10)*10 + n % 10;
    int b = ((n/100)%10)*10 + (n/10)%10;
    cout << a << "+" << b << "=" << a+b;
}