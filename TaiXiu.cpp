//lO HONG CUA TAI XIU
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;
int main()
{
    cout << "De dam bao chien thang thuat toan nay se lay tien cuoc la 1/(2^16-1), nghia la co the thua 15 lan và lan 16 la thang" << endl;
    cout << "Nap 6553500 VND thi tien cuoc ban dau la 100 VND" << endl;
    int testcase = 1;
    srand(time(NULL));
    long long int tiencuaban;
    long long int songaychoi = 0;   
    tiencuaban = tiencuaban % 9999999 + 1000000;
    while (testcase <= 100)
    {
       cout << "Testcase: " << testcase << endl;
       long long int tiencuoc = 0;
       unsigned long int luotthang = 0, n, mu = pow(2, 16), dem = 0;

       n = rand() % 1000000 + 1;
       tiencuoc = tiencuaban / (mu - 1);
       cout << "Tien cua ban: " << tiencuaban << endl;
       cout << "Số luot thang mong muon " << n << endl;
       while (luotthang < n && tiencuaban>0) //chay khi luot thang = so da cho va khi van con tien
       {
           int a = rand() % 2; // a random từ 0->1, 0 la thang, 1 la thua
           if (a == 1) // thang thi cong tien, cap nhat lai tien cuoc bang cong thuc tren va luot thang + 1
           {
               tiencuaban = tiencuaban + tiencuoc * 98 / 100;
               tiencuoc = tiencuaban / mu - 1;
               luotthang++;
           }
           else // thua thi tru tien, nga o dau gap đoi tien cuoc o do
           {
               tiencuaban = tiencuaban - tiencuoc;
               tiencuoc = tiencuoc * 2;
           }
           dem++;
       }
       cout << "Tien cua ban sau khi choi la: " << tiencuaban;
       cout << endl;
       cout << "So phien la: " << dem;
       cout << endl;
       songaychoi = songaychoi + dem * 90 / 3600 / 24;
       cout << "So ngay choi la: " << songaychoi;
       cout << "\n\n\n";
       testcase++;
       
    }
    system("Pause");
}