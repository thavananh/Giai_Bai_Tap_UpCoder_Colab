#include <iostream>
using namespace std;

int main(){
    int a[1][1000];
    int count[4][1000];
    int n;
    cin >> n;
    for (size_t i = 0; i < 1; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            count[i][j] = 1;
        }
        
    }
    for (size_t i = n - 1; i > 0; i--)
    {
        if (a[0][i] > a[0][i-1])
        {
            count[0][i-1] = count[0][i-1] + count[0][i];
        }
        if (a[0][i] >= a[0][i-1])
        {
            count[1][i-1] = count[1][i-1] + count[1][i];
        }
        if (a[0][i] < a[0][i-1])
        {
            count[2][i-1] = count[2][i-1] + count[2][i];
        }
        if (a[0][i] <= a[0][i-1])
        {
            count[3][i-1] = count[3][i-1] + count[3][i];
        }
        
    }
    int temp[4];
    for (size_t i = 0; i < n; i++)
    {
        int max= count[i][0];
        
        
        for (size_t j = 1; j < n; j++)
        {
            if (max <= count[i][j])
            {
                temp[i] = 1;
                break;
            }
        }
        if (temp[i] == 0)
        {
            break;
        }
        
    }
    if (temp[0] == 0)
    {
        cout << "Day tang" << endl;
    }
    else if (temp[1] == 0)
    {
        cout << "Day tang chat" << endl;
    }
    else if (temp[2] == 0)
    {
        cout << "Day giam" << endl;
    }
    else if (temp[3] == 0)
    {
        cout << "Day giam chat" << endl;
    }
    else
    {
        cout << "Day lon xon" << endl;
    }
    system("Pause");
    
    
     
}