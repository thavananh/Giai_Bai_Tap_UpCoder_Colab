#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
void Max_OldMax(int x, int y, int z, int t) {
    int max = x;
    int oldmax = INT_MIN;
    if (y > max)
    {
        oldmax = max;
        max = y;
    }
    if (z > max)
    {
        oldmax = max;
        max = z;
    }
    if (t > max)
    {
        oldmax = max;
        max = t;
    }
    if (y > oldmax && y < max)
    {
        oldmax = y;
    }
    if (z > oldmax && z < max)
    {
        oldmax = z;
    }
    if (t > oldmax && t < max)
    {
        oldmax = t;
    }
    cout << max << endl;
    cout << oldmax << endl;
}


int main() {
    // int x;
    // int y;
    // int z;
    // int t;
    //cin >> x >> y >> z >> t;
    //Max_OldMax(x, y, z, t);
    // char KyTu1[100];
    // char KyTu2[100];
    // int Temp1 = 0;
    // int Temp2 = 0;
    // cin >> KyTu1;
    // cin >> KyTu2;
    // for (size_t i = 0; i < strlen(KyTu1); i++)
    // {
    //     Temp1  = Temp1 + int(KyTu1[i]);
    // }
    // for (size_t i = 0; i < strlen(KyTu2); i++)
    // {
    //     Temp2 = Temp2 + int(KyTu1[i]);
    // }
    // if (Temp1 > Temp2)
    // {
    //     cout << "Chu So co chu so ASCII Lon Nhat: " << KyTu1;
    // }
    // else
    // {
    //     cout << "Chu So co chu so ASCII Lon Nhat: " << KyTu2;
    // }
    int n;
    cin >> n;
    int Original_Num = n;
    int Reverse_Num = 0;
    int Sum = 0;
    while (n)
    {
        Reverse_Num = (Reverse_Num + n%10)*10;
        n = n/10;
    }
    Reverse_Num /= 10;
    cout << Reverse_Num << endl;
    Sum = Reverse_Num + Original_Num;
    int Reverse_Sum = 0;
    while (Sum)
    {
        Reverse_Sum = (Reverse_Sum + Sum%10) * 10;
        Sum = Sum / 10;
    }
    int count = 0;
    int temp1 = Reverse_Sum;
    int ChuSoThu3 = 0;
    while (Reverse_Sum)
    {
        Reverse_Sum = Reverse_Sum / 10;
        count++;
    }
    ChuSoThu3 = temp1/pow(10, count - 2);
    ChuSoThu3 = ChuSoThu3 % 10;
    cout << "Chu so thu 3 tu trai qua phai: " << ChuSoThu3;
    system("Pause");
}