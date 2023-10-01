#include <iostream>
using namespace std;

int main() {
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int dinhthuc = a1*b2 - a2*b1;
    int dinhthuc_x = c1*b2 - c2*b1;
    int dinhthuc_y = a1*c2 - a2*c1;
    if (dinhthuc == 0)
    {
        if (dinhthuc_x + dinhthuc_y == 0)
        {
            cout << -1;
        }
        else 
        {
            cout << 0;
        }
    }
    else
    {
        cout << 1;
    }
}

// #include<iostream>
// using namespace std;
// int main(){
//     int a1, b1, c1, a2, b2, c2;
//     float D, Dx, Dy, x, y;
//     cout << "a1*x + b1*y = c1" << endl;
//     cout << "a2*x + b2*y = c2" << endl;
//     cout << "Nhap a1: ";
//     cin >> a1;
//     cout << "Nhap b1: ";
//     cin >> b1;
//     cout << "Nhap c1: ";
//     cin >> c1;
//     cout << "Nhap a2: ";
//     cin >> a2;
//     cout << "Nhap b2: ";
//     cin >> b2;
//     cout << "Nhap c2: ";
//     cin >> c2;
//     D = a1 * b2 - a2 * b1;
//     Dx = c1 * b2 - c2 * b1;
//     Dy = a1 * c2 - a2 * c1;
//     if (D == 0) {
//         if (Dx + Dy == 0)
//             cout << "He phuong trinh co vo so nghiem";
//         else
//             cout << "He phuong trinh vo nghiem";
//     }
//     else {
//         x = Dx / D;
//         y = Dy / D;
//         cout << "He phuong trinh nghiem" << endl;
//         cout << "x = " << x<<endl;
//         cout << "y = " << y;
//     }
//     system("pause");
//     return 0;
// }