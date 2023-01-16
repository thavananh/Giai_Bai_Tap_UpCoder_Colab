#include <iostream>
#define ArraySize 100
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;
    int a[ArraySize];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    system("Pause");
}