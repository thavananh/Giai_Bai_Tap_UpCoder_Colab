#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x < 0) {
        cout << "AM";
    }
    else if (x > 0) {
        cout << "DUONG";
    }
    else
    {
        cout << "KHONG";
    }
}