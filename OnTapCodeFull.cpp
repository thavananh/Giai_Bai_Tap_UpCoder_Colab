#include <iostream>
#include <cmath>
using namespace std;

void soLonNhatTrong3So() {
    int a, b, c;
    cin >> a >> b >> c;
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    cout << "Max = " << max << endl;
}

void soLonNhat_soLonNhi_Trong4So() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int max1 = a;
    int max2 = -1;
    if (b > max1)
    {
        max2 = max1;
        max1 = b;
    }
    if (c > max1)
    {
        max2 = max1;
        max1 = c;
    }
    if (d > max1)
    {
        max2 = max1;
        max1 = d;
    }
    if (b > max2 && b < max1)
    {
        max2 = b;
    }
    if (c > max2 && c < max1)
    {
        max1 = c;
    }
    if (d > max2 && d < max2)
    {
        max2 = d;
    }
    cout << "Max1 = " << max1 << endl;
    cout << "Max2 = " << max2 << endl;
}

void kiemTraCapSoCong_Trong4So() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int temp = b - a;
    if (c - b == temp)
    {
        if (d - c == temp)
        {
            cout << "Day la cap so cong" << endl;
        }
        else
        {
            cout << "Day khong la cap so cong" << endl;
        }
    }
}

void kiemTraCapSoNhan_Trong4So() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int temp = b / a;
    if (c / b == temp)
    {
        if (d / c == temp)
        {
            cout << "Day la cap so nhan" << endl;
        }
        else
        {
            cout << "Day khong la cap so nhan" << endl;
        }
    }
}

void tongCacSoChan_1denN() {
    int n;
    int sum = 0;
    cin >> n;
    for (size_t i = 2; i <= n; i+=2)
    {
        sum = sum + i;
    }
    cout << sum << endl;
}

void inRaCacUocSoCuaN() {
    int n;
    cin >> n;
    int m = sqrt(n);
    if (m*m == n)
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
        for (size_t i = 0; i <= m; i++)
        {
            if (n % i == 0)
            {
                cout << i << " " << n / i << " ";
            }
        }
    }
    cout << endl;
}

void demCacUocSoCuaN() {
    int n;
    cin >> n;
    int count = 0;
    int m = sqrt(n);
    if (m * m == n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0 && i != m)
            {
                count = count + 2;
            }
        }
        count = count + 1;
    }
    else
    {
        for (size_t i = 2; i <= m; i++)
        {
            if (n % i == 0)
            {
                count = count + 2;
            }   
        }
    }
    cout << count << endl;
}

void TinhTongCacUocSoChanNhoHonN() {
    int n;
    cin >> n;
    int sum = 0;
    for (size_t i = 2; i < n; i+=2)
    {
        sum = sum + i;
    }
}

void inRaCacUocSoChinhPhuongCuaN() {
    int n;
    int a = 2;
    cin >> n;
    cout << 1 << " ";
    for (size_t i = a*a; i <= n; a++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

void tongCacSoChinhPhuongNhoHonN() {
    int n;
    int sum = 1;
    int a = 2;
    cin >> n;
    for (size_t i = a*a; i <= n; a++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
}

void kiemTraSoNguyenTo() {
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << "Khong la so Nguyen To";
    }
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << "Khong la so nguyen to";
            break;
        }
    }
    cout << "La so nguyen to";
    cout << endl;
}

bool SoNguyenTo(int n) {
    int n;
    cin >> n;
    if (n < 2)
    {
        return false;
    }
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void inRaCacSoNguyenToNhoN() {
    int n;
    cin >> n;
    for (size_t i = 2; i < n; i++)
    {
        if (SoNguyenTo(i))
        {
            cout << i << " ";
        }
    }
}

int main() {

}