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

int Kiem_Tra_So_Doi_Xung(int n){
    int SoDoiXung = 0;
    int temp = n;
    while (temp)
    {
        SoDoiXung = SoDoiXung + temp%10;
        SoDoiXung = SoDoiXung * 10;
        temp = temp / 10;
    }
    if (SoDoiXung/10 == n)
        return 1;
    else
        return 0;
}

int Tim_Uoc_Chung_Lon_Nhat(int a, int b) {
        while (a != 0 && b!= 0)
    {
        if (a > b)
        {
            a = a%b;
        }
        else
        {
            b = b%a;
        }
    }
    if (a != 0)
    {
        return a;
    }
    else
    {
        return b;
    }
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

void bai1_13(int n) {
    int sum = 0;
    int m = sqrt(n);
    if (m * m == n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0 && i != m)
            {
               sum = sum+i + n/i;
            }
        }
        sum = sum + m;
    }
    else
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0)
            {
                sum = sum + i + n/i;
            }
        }
    }
    if (sum == 2*n)
    {
        cout << "So hanh phuc" << endl;
    }
    else
    {
        cout << "Khong la so hanh phuc" << endl;
    }
    cout << "\n";
}

void bai2(int n) {
    int SoDoiXung = 0;
    int temp = n;
    while (temp)
    {
        SoDoiXung = SoDoiXung + temp%10;
        SoDoiXung = SoDoiXung * 10;
        temp = temp / 10;
    }
    if (SoDoiXung/10 == n)
    {
        cout << "So Doi Xung" << endl;
    }
    
    else
        cout << "Ko la so doi xung" << endl;
}

void bai3(int n) {
    for (size_t i = 1; i < n; i++)
    {
        if (n%i == 0 && Kiem_Tra_So_Doi_Xung(i))
        {
            cout << i  << " ";
        }
        
    }
    cout << endl;
}

void bai4(int a, int b) {
    while (a != 0 && b!= 0)
    {
        if (a > b)
        {
            a = a%b;
        }
        else
        {
            b = b%a;
        }
    }
    if (a != 0)
    {
        cout << "Uoc Chung Lon Nhat: " << a << endl;
    }
    else
    {
        cout << "Uoc Chung Lon Nhat: " << b << endl;
    }
    
}
int bai5(int a,int b){
    return a*b/Tim_Uoc_Chung_Lon_Nhat(a, b);
}

void bai6(int n)
{
    if (n == 1)
    {
        cout << "Khong phan tich duoc" << endl;
    }
    
    int i = 2;
    while (n != 1)
    {
        
        if (n % i == 0 && check_so_nguyen_to(i))
        {
           while (n % i == 0)
           {
             cout << i << " ";
             n = n/i;
           }
        }
        i++;
    }
    cout << endl;
}

void bai7(int n) {
    while (n)
    {
        cout << n % 2;
        n = n /2;
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
    bai1_13(n);
    bai2(n);
    bai3(n);
    int a;
    int b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    bai4(a, b);
    cout << "Boi Chung Nho Nhat: " << bai5(a, b) << endl;
    bai6(n);
    bai7(n);
    system("Pause");
}