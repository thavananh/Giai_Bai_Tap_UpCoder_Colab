#include <iostream>
#define arraySize 100
using namespace std;
void nhapMang(int a[], int n);

int CheckMax(int a, int b) {
    int max = a;
    if (b > max)
    {
        max = b;
    }
    return max;
}
void nhapMang(int a[], int n) {
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void xuatMang(int a[], int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i];
    }  
}

void Count_MaxNum_InArr(int a[], int n) {
    int max = a[0];
    int count = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == max)
        {
            count++;
        }
    }
    cout << count << endl;
}

void In_Vi_Tri_Cac_Phan_Tu_Lon_Nhat_Cua_Mang(int a[], int n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == max)
        {
            cout << i;
            break;
        }
    }
    cout << endl;
}

void Dem_Phan_Tu_Min_Cua_Mang(int a[], int n) {
    int min = a[0];
    int count = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == min)
        {
            count++;
        }
    }
    cout << count << endl;
}

void In_Ra_Vi_Tri_Phan_Tu_Min_Cua_Mang(int a[], int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == min)
        {
            cout << i;
            break;
        }
    }
    cout << endl;
}

void In_Ra_Tich_2_So_Lon_Nhat_Cua_Mang(int a[], int n) {
    int max = a[0];
    int oldmax = 0;
    int min = a[0];
    int oldmin = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            oldmax = max;
            max  = a[i];
        }
        if (a[i] > oldmax && a[i] < max)
        {
            oldmax = a[i];
        }
        if (a[i] < min)
        {
            oldmin = min;
            min = a[i];
        }
        if (a[i] < oldmin && a[i] > min)
        {
            oldmin = a[i];
        }
        
        
    }
    if (oldmin * min > oldmax * max)
    {
        cout << oldmin * min;
    }
    else
    {
        cout << oldmax * max;
    }
}

void In_Ra_Doan_Lien_Tiep_Tang_Dan_Dai_Nhat(int a[], int n) {
    int count[arraySize];
    for (size_t i = 0; i < n; i++)
    {
        count[i] = 1;
    }
    for (size_t i = n-1; i > 0; i--)
    {
        if (a[i] > a[i-1])
        {
            count[i-1] = count[i-1] + count[i];
        }
        
    }
    int max = count[0];
    for (size_t i = 1; i < n; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
    }
    int pos = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (max == count[i])
        {
            pos = i;
        }
    }
    size_t j = pos;
    for (size_t i = 0; i < count[pos]; i++)
    {
        cout << a[j] << " ";
        j++;
    }
    cout << endl;
}
//int n = 9;
// -2, 1, -3, 4, -1, 2, 1, -5, 4
void Tim_Day_Co_Tong_Lon_Nhat(int a[], int n) {
    int pos = 0;
    int best_pos = 0;
    int end = 0;
    int sum = 0;
    int sum_lon_nhat = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] > a[i] + sum)
        {
            pos = i;
            sum = a[i];
        }
        else
        {
            sum = sum + a[i];
        }
        if (sum_lon_nhat < sum)
        {
            sum_lon_nhat = sum;
            best_pos = pos;
            end = i;
        }
    }
    for (size_t i = best_pos; i <= end; i++)
    {
        cout << a[i] << " ";
    }
}

int main(){
    int arr[arraySize];
    int n;
    cin >> n;
    nhapMang(arr, n);
    //Count_MaxNum_InArr(arr, n);
    //In_Vi_Tri_Cac_Phan_Tu_Lon_Nhat_Cua_Mang(arr, n);
    //Dem_Phan_Tu_Min_Cua_Mang(arr, n);
    //In_Ra_Vi_Tri_Phan_Tu_Min_Cua_Mang(arr, n);
    //xuatMang(arr, n);
    //In_Ra_Tich_2_So_Lon_Nhat_Cua_Mang(arr, n);
    //In_Ra_Doan_Lien_Tiep_Tang_Dan_Dai_Nhat(arr, n);
    Tim_Day_Co_Tong_Lon_Nhat(arr, n);
    system("Pause");
}