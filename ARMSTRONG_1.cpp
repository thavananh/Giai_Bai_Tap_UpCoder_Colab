#include <iostream>
#include <cmath>
using namespace std;

bool amstrong(int n) {
    long long temp = n;
    long long count = 0;
    long long sum = 0;
    while (temp)
    {
        count++;
        temp = temp / 10;
    }
    temp = n;
    while (temp)
    {
        sum = sum + pow(temp%10, count);
        temp = temp / 10;
    }
    if (sum == n) {
        return true;
    } 
    return false;
}

int main() {
    long long n;
    while (cin >> n)
    {
        if (amstrong(n))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}