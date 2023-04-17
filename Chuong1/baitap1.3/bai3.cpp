// Cách 1
// #include <iostream>
// using namespace std;

// int main() {
//     int a, b;
//     cin >> a >> b;
//     int tmp;
//     tmp = a;
//     a = b;
//     b = tmp;
//     cout << a << " " << b;
// }

// Cách 2
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    swap(a, b);
}