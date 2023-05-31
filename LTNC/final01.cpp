#include <iostream>

using namespace std;

long long giai_thua(int n){
    if (n == 1 || n == 0)
        return 1;
    else
        return n * giai_thua(n - 1);
}

float Sin(float x, int n = 5)
{
    if(n <= 0.0001) return x;
    
    return pow(-1, n) * pow(x, 2 * n + 1) / giai_thua(2 * n + 1) + Sin(x, n-1);
}

float Cos(float x, int n = 5)
{
    if(n <= 0.0001) return 1;
    
    return pow(-1, n) * pow(x, 2 * n) / giai_thua(2 * n) + Cos(x, n-1);
}

int main()
{
    float x;
    cin >> x;
    cout << roundf(Sin(x)*100)/100 << endl;
    cout << roundf(Cos(x)*100)/100 << endl;
}