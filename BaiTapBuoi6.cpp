#include <iostream>
#define row 100
#define col 100
using namespace std;
void nhapmang(int a[row][col], int n, int m);
void xuatmang(int a[row][col], int n, int m);
void In_So_Tren_Duong_Cheo_Chinh(int a[row][col], int n, int m);






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
        // đặt if ở đây
        for (size_t j = 0; j < m; i++)
        {
            
        }
        
    }
    
}

int main() {
    int a[row][col];
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    nhapmang(a, n, m);
    //xuatmang(a, n, m);
    cout << endl;
    cout << endl;
    In_So_Tren_Duong_Cheo_Chinh(a, m, n);

    system("Pause");
}