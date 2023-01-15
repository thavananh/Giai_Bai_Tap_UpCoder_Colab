#include <iostream>
using namespace std;

int TimSo0TanCungGiaiThua(int n) { // solution phân tích thừa số nguyên tố xong đếm số 5 là xong =))
    int count = 0;
    for (size_t i = 5; n/i >= 1; i*=5)
    {
        count = count + n / i;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << TimSo0TanCungGiaiThua(n);
    system("Pause");
    
}