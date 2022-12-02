#include <iostream>
#include<cmath>
#define row 100
#define col 100
using namespace std;

void nhapmang(int a[row][col], int n, int m);
void xuatmang(int a[row][col], int n, int m);
void In_So_Tren_Duong_Cheo_Chinh(int a[row][col], int n, int m);
void In_Cac_So_Nam_Tren_Bien(int a[row][col], int n, int m);
void In_Tong_Moi_Hang(int a[row][col], int n, int m);
void In_Tong_Moi_Cot(int a[row][col], int n, int m);
void In_Hang_Co_Tong_Lon_Nhat(int a[row][col], int n, int m);
void In_Cot_Co_Tong_Lon_Nhat(int a[row][col], int n, int m);
void In_Ra_Gia_Tri_Be_Nhat_Moi_Cot(int a[row][col], int n, int m);
void Sap_Xep_Thu_Tu_Tren_Moi_Hang(int a[row][col], int n, int m);
void Sap_Xep_Thu_Tu_Tang_Dan_Tren_Moi_Cot(int a[row][col], int n, int m);
void In_Ra_Cac_So_Nguyen_To_Moi_Hang(int a[row][col], int n, int m);
bool Check_So_Nguyen_To(int n);
bool Check_So_Chinh_Phuong(int n);

bool Check_So_Chinh_Phuong(int n) {
    int m = sqrt(n);
    for (size_t i = 1; i <= sqrt(n); i++)
    {
        if (i*i == n)
        {
            return 1;
        }
    }
    return 0;
}

bool Check_So_Nguyen_To(int n) {
    if (n < 2)
    {
        return 0;
    }
    for (size_t i = 3; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;
    
}

void nhapmang(int a[row][col], int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }   
    }
}

void xuatmang(int a[row][col], int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }   
        cout << endl;
    }
}

void In_So_Tren_Duong_Cheo_Chinh(int a[row][col], int n, int m) {
    if (n != m)
    {
        return;
    }
    int i = 0;
    int j = 0;
    while (i != n)
    {
        cout << a[i][j] << " ";
        i++; j++;
    }
}

void In_Cac_So_Nam_Tren_Bien(int a[row][col], int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (size_t j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << a[i][0] << " " << a[i][m-1] << " " << endl;
        }
    }
}

void In_Tong_Moi_Hang(int a[row][col], int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < m; j++)
        {
            sum = sum + a[i][j];
        }
        cout << sum << endl;
    }
}

void In_Tong_Moi_Cot(int a[row][col], int n, int m) {
    for (size_t i = 0; i < m; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < n; j++)
        {
            sum = sum + a[j][i];
        }
        cout << sum << endl;
    }   
}

void In_Hang_Co_Tong_Lon_Nhat(int a[row][col], int n, int m) {
    int sumArr[row]; 
    for (size_t i = 0; i < n; i++)
    {
        int sum = 0;
        
        for (size_t j = 0; j < m; j++)
        {
            sum = sum + a[i][j];   
        }
        sumArr[i] = sum;
    }
    int max = sumArr[0];
    for (size_t i = 1; i < n; i++)
    {
       if (sumArr[i] > max)
       {
            max = sumArr[i];
       }
        
    }
    cout << max << endl;
    
    
}

void In_Cot_Co_Tong_Lon_Nhat(int a[row][col], int n, int m){
    int sumArr[col];
    for (size_t i = 0; i < m; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < n; j++)
        {
            sum = sum + a[j][i];
        }
        sumArr[i] = sum;
    }
    int min = sumArr[0];
    for (size_t i = 0; i < n; i++)
    {
        if (sumArr[i] < min)
        {
            min = sumArr[i];
        }
    }
    cout << min << endl;
}

void In_Ra_Gia_Tri_Lon_Nhat_Moi_Hang(int a[row][col], int n, int m){
    for (size_t i = 0; i < n; i++)
    {
        int max = a[i][0];
        for (size_t j = 1; j < m; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        cout << max << endl;
    }
}

void In_Ra_Gia_Tri_Be_Nhat_Moi_Cot(int a[row][col], int n, int m){
    for (size_t i = 0; i < n; i++)
    {
        int min = a[0][i];
        for (size_t j = 1; j < m; j++)
        {
            if (a[j][i] < min)
            {
                min = a[j][i];
            }
        }
        cout << min << endl;
    }
    
}

void Sap_Xep_Thu_Tu_Tren_Moi_Hang(int a[row][col], int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m-1; j++)
        {
            for (size_t k = 0; k < m; k++)
            {
                int temp = 0;
                if (a[i][k] < a[i][k + 1])
                {
                    temp = a[i][k];
                    a[i][k] = a[i][k+1];
                    a[i][k+1] = temp;
                }
                
            }
        }
    }
}

void Sap_Xep_Thu_Tu_Tang_Dan_Tren_Moi_Cot(int a[row][col], int n, int m) {
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n-1; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                int temp = 0;
                if (a[k][i] < a[k+1][i])
                {
                    temp = a[k][i];
                    a[k][i] = a[k+1][i];
                    a[k+1][i] = temp;
                }
                
            }
        }
    }
}

void In_Ra_Cac_So_Nguyen_To_Moi_Hang(int a[row][col], int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (Check_So_Nguyen_To(a[i][j]))
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    
}

void In_Ra_Cac_So_Chinh_Phuong_Moi_Cot(int a[row][col], int n, int m) {
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (Check_So_Chinh_Phuong(a[j][i]))
            {
                cout << a[j][i] << " ";
            }
        }
        cout << endl;
    }
}

void In_Ra_So_Lon_Nhat_Cua_Mang(int a[row][col], int n, int m) {
    int arrTemp[col];
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m-1; j++)
        {
            for (size_t k = 0; k < m; k++)
            {
                int temp = 0;
                if (a[i][k] < a[i][k+1])
                {
                    temp = a[i][k];
                    a[i][k] = a[i][k+1];
                    a[i][k+1] = temp;
                }
            }
            arrTemp[i] = a[i][0];
        }
    }
    int max = arrTemp[0];
    for (size_t i = 1; i < n; i++)
    {
        if (arrTemp[i] > max)
        {
            max = arrTemp[i];
        }
    }
    cout << max << endl;
}

int main() {
    int a[row][col];
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    nhapmang(a, n, m);
    xuatmang(a, n, m);
    cout << endl;
    cout << endl;
    In_So_Tren_Duong_Cheo_Chinh(a, n, m);
    In_Cac_So_Nam_Tren_Bien(a, n, m);
    In_Tong_Moi_Hang(a, n, m);
    In_Tong_Moi_Cot(a, n, m);
    In_Hang_Co_Tong_Lon_Nhat(a, n, m);
    In_Cot_Co_Tong_Lon_Nhat(a, n, m);
    In_Ra_Gia_Tri_Lon_Nhat_Moi_Hang(a, n, m);
    In_Ra_Gia_Tri_Be_Nhat_Moi_Cot(a, n, m);
    Sap_Xep_Thu_Tu_Tren_Moi_Hang(a, n, m);
    xuatmang(a, n, m);
    Sap_Xep_Thu_Tu_Tang_Dan_Tren_Moi_Cot(a, n, m);
    xuatmang(a, n, m);
    In_Ra_Cac_So_Nguyen_To_Moi_Hang(a, n, m);
    In_Ra_Cac_So_Chinh_Phuong_Moi_Cot(a, n, m);
    In_Ra_So_Lon_Nhat_Cua_Mang(a, n, m);

    system("Pause");
}