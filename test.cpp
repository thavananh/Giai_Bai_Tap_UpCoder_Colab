#include <iostream>
using namespace std;

int main(){
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        
        for (size_t j = 0; j < col; j++)
        {
            int temp = 0;
            for (size_t k = 0; k < col - 1; k++)
            {
                if (a[i][k] > a[i][k+1])
                {
                    temp = a[i][k+1];
                    a[i][k+1] = a[i][k];
                    a[i][k] = temp;
                }
                
            }
            
        }
        
    }
    cout << "\n\n\n";
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    system("Pause");
}
