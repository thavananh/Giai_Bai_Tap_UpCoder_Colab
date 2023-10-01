#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    float sum = 1;
    float temp = 1;
    for (size_t i = 0; i <= n; i++)
    {
        temp = temp * (2*i + 2)/(2*i + 3);
        sum = sum + temp; 
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << sum;
}