#include <iostream>
using namespace std;


// tìm kiếm nhị phân chỉ hoạt động với mảng đã được sắp xếp
long long timKiemNhiPhan(long long a[], long long left, long long right, long long x)
{
    if (left > right)
    {
        return -1;
    }
    long long mid = (left + right)/2;
    if (x == a[mid])
    {
        return mid;
    }
    if (x < a[mid])
    {
        return timKiemNhiPhan(a, left, mid - 1, x);
    }
    return timKiemNhiPhan(a, mid + 1, right, x);

}
int main()
{
    long long a[10000];
    long long n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << timKiemNhiPhan(a, 0, n, 10);
    system("Pause");
}