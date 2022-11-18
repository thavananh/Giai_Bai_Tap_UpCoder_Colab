#include <iostream>
using namespace std;
//Khai báo chương trình con
int Sum_EvenNum(int n);
void Print_Divisor(int n);
int Count_Divisior(int n);
int Sum_EvenDivsiorNum(int n);
void Print_PerfectSqrt_Divisior(int n);
int Sum_Perfect_Sqrt_Divisior_Smaller_Than_n(int n);
void Check_Prime_Num(int n);
void Print_Prime_Num_Smaller_Than_n(int n);
void Test_NotKnown();
int Sum_Element_Of_n();
void print_Max_Element_Of_n(int n);
void print_PrimeNum_Divisior_of_n(int n);


int main()
{
    int n;
    cout << "input n";
    cin >> n;
    cout << "*****************Chọn Chương Trình*****************" << endl;
    cout << "*1. Tổng các số chẵn từ 1 đến n                   *" << endl;
    cout << "*2. In ra tất cả các ước số của n                 *" << endl;
    cout << "*3. Đếm các ước số của n                          *" << endl;
    cout << "*4. In số các ước số là số chính phương của n     *" << endl;
    cout << "*5. Tổng các số chính phương nhỏ hơn n            *" << endl;
    cout << "*6. Kiểm tra n có là số nguyên tố không ?         *" << endl;
    cout << "*7. In ra số nguyên tố nhỏ hơn n                  *" << endl;
    cout << "*8. ???" << endl;
    cout << "*9. Tổng các chữ số của n                         *" << endl;
    cout << "*10. in ra chữ số lớn nhất của n                  *" << endl;
    cout << "*11. In ra các ước số nguyên tố của n             *" << endl;
    switch (n)
    {
    case 1:
    {
        system("cls");
        cout << "Bạn chọn 1. Tổng các số chẵn từ 1 đến n" << endl;
        cout << "Tổng = " << Sum_EvenNum(n) << endl;
        break;
    }
    case 2:
    {
        system("cls");
        cout << "Bạn chọn 2. In ra tất cả các ước số của n" << endl;
        Print_Divisor(n);
        break;
    }
    case 3:
    {
        system("cls");
        cout << "Bạn chọn 3. Đếm các ước số của n" << endl;
        cout << "Số các ước số: " << Count_Divisior(n) << endl;
    }
    default:
        break;
    }
    return 0;
}

int Sum_EvenNum(int n){
    int sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
        
    }
    return sum;
}
void Print_Divisor(int n){
    cout << "Tất cả ước số của n: ";
    for (size_t i = 0; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "i, ";
        }
    }
    cout << "\n";
}
int Count_Divisior(int n){
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
        
    }
    return count;
}
int Sum_EvenDivsiorNum(int n){
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (n % i == 0)
            {
                sum += sum;
            }
            
        }
        
    }
}
void Print_PerfectSqrt_Divisior(int n){
    for (size_t i = 0; i < n; i++)
    {
        int j = 0;
        if (n % i == 0)
        {
            while (j <= i)
            {
                if (j*j == i)
                {
                    
                }
                
            }
            
        }
        
    }
    
}
int Sum_Perfect_Sqrt_Divisior_Smaller_Than_n(int n){

}
void Check_Prime_Num(int n){

}
void Print_Prime_Num_Smaller_Than_n(int n){

}
void Test_NotKnown(){

}
int Sum_Element_Of_n(){

}
void print_Max_Element_Of_n(int n){

}
void print_PrimeNum_Divisior_of_n(int n){

}
