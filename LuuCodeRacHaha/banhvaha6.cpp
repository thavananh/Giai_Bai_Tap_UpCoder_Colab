#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long sum = 0;
    long long count = 0;
    while (n)
    {
        long long sovan;
        long long sodiem;
        cin >> sovan >> sodiem;
        sum = sum + sovan * sodiem;
        count = count + sovan;
        n--;
    }
    long long sodiemtru;
    cin >> sodiemtru;
    cout << sum - sodiemtru << '\n';
    cout << count << '\n';
}