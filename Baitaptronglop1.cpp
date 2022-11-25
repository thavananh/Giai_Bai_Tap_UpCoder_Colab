#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int check_so_nguyen_to(int n) {
    if (n < 2)
    {
        return 0;
    }
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int bai1_1(int n)
{
    int sum = 0;
    for (size_t i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

void bai1_2(int n)
{
    int m = sqrt(n);
    if (m * m == n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0 && i != m)
            {
                cout << i << " " << n / i << " ";
            }
        }
        cout << m;
    }
    else
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0)
            {
                cout << i << " " << n / i << " ";
            }
        }
    }
    cout << endl;
}

int bai1_3(int n)
{
    int Dem_Uoc_So = 0;
    int m = sqrt(n);
    if (m * m == n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0 && i != m)
            {
                Dem_Uoc_So = Dem_Uoc_So + 2;
            }
        }
        Dem_Uoc_So =  Dem_Uoc_So + 1;
    }
    else
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0)
            {
                Dem_Uoc_So = Dem_Uoc_So + 2;
            }
        }
    }
    return Dem_Uoc_So;
}

int bai1_4(int n) {
    int sum = 0;
    for (size_t i = 2; i <= n; i = i + 2)
    {
        sum = sum + i;
        
    }
    return sum;
}

void bai1_5(int n) {
    cout << 1 << " ";
    for (size_t i = 4; i <= n; i = i*i)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int bai1_6(int n) {
    int sum = 1;
    for (size_t i = 4; i < n; i = i*i)
    {
        sum = sum + i;
    }
    return sum;
}

void bai1_7(int n) {
    if (n < 2)
    {
        cout << "False";
    }
    
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            cout << "False" << endl;
            return;
        }
    }
    cout << "True";
    cout << endl;
}

void bai1_8(int n) {
    if (n < 2)
    {
        cout << "Không có số nguyên tố nhỏ hơn n";
    }
    
    for (size_t i = 2; i <= n; i++)
    {
        if (check_so_nguyen_to(i))
        {
            cout << i << " ";
        
        }
    }
    cout << endl;
}

int bai1_10(int n) {
    int sum = 0;
    while (n)
    {
        sum = sum + n%10;
        n = n / 10;
    }
    return sum;
}

int bai1_11(int n) {
    int max = 0;
    while (n)
    {
        if (max < n%10)
        {
            max = n%10;
        }
        n = n/10;
    }
    return max;
}
void bai1_12(int n) {
    if (n<2)
    {
        cout << "Không có ước số nguyên tố" << endl;
        return;
    }
    
    for (size_t i = 1; i <= n; i++)
    {
        if (n%i == 0 && check_so_nguyen_to(i))
        {
            cout << i << " ";
        }
        
    }
    cout << endl;
}

int main()
{

    int n;
    cin >> n;
    cout << bai1_1(n) << endl;
    bai1_2(n);
    cout << bai1_3(n) << endl;
    cout << bai1_4(n) << endl;
    bai1_5(n);
    cout << bai1_6(n) << endl;
    bai1_7(n);
    bai1_8(n);
    cout << bai1_10(n) << endl;
    cout << bai1_11(n) << endl;
    bai1_12(n);
    system("Pause");
}