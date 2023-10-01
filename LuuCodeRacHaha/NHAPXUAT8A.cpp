#include <iostream>
#include <cctype>
using namespace std;

int giaithua(int n) {
    int value = 1;
    for (size_t i = 2; i <= n; i++)
    {
        value = value * i;
    }
    return value;
}

int tohop(int k, int n) {
    return giaithua(n) / (giaithua(k)*giaithua(n-k));
}


int main() {
    string input1; // biến 1
    char input2; // dấu
    string input3; // biến 2;
    int input4 = 2; // mũ
    cin >> input1 >> input2 >> input3;
    
    if (input1 == input3 && input2 == '+')
    {
        cout << "( " << input1 << " " << input2 << " " << input3 << " )" << "^" << input4 << "= ";
        cout << 5 << " a ^2";
    }
    else if (input1 == input3 && input2 == '-')
    {
        cout << "( " << input1 << " " << input2 << " " << input3 << " )" << "^" << input4 << "= ";
        cout << 0;
    }
    else
    {
        cout << "( " << input1 << " " << input2 << " " << input3 << " )" << "^" << input4 << "= ";
        for (size_t i = 0; i <= input4; i++)
        {
        if (input2 == '+')
        {
            if (i == 0)
            {
                cout << input1 << " ^" << input4;
            }
            else if (i == input4)
            {
                cout << input3 << " ^" << input4;
            }
            else if (input4 - i == i)
            {
                if (input4 - i != 1)
                {
                    cout << tohop(i, input4) << " "<< input1 << " ^" << input4 - i << " " << input3 << " ^" << i;
                }
                else
                {
                    cout << tohop(i, input4) << " " << input1 << " " << input3;
                }
            }
            else if (i == 1)
            {
                cout << tohop(i, input4) << " " << input1 << " ^" << input4 - i << " " << input3;
            }
            else if (input4 - i == 1)
            {
                cout << tohop(i, input4) << " "<<input1 << " " << input3 << " ^" << i;
            }
            else
            {
                cout << tohop(i, input4) << " "<<input1 << " ^" << input4 - i << " " << input3 << " ^" << i;
            }
            if (i < input4)
            {
                cout << " + ";
            }
            
        }
        else
        {
            if (i == 0)
            {
                cout << input1 << " ^" << input4;
            }
            else if (i == input4)
            {
                cout << input3 << " ^" << input4;
            }
            else if (input4 - i == i)
            {
                if (input4 - i != 1)
                {
                    cout << tohop(i, input4) << " "<< input1 << " ^" << input4 - i << " " << input3 << " ^" << i;
                }
                else
                {
                    cout << tohop(i, input4) << " " << input1 << " " << input3;
                }
            }
            else if (i == 1)
            {
                cout << tohop(i, input4) << " " << input1 << " ^" << input4 - i << " " << input3;
            }
            else if (input4 - i == 1)
            {
                cout << tohop(i, input4) << " "<<input1 << " " << input3 << " ^" << i;
            }
            else
            {
                cout << tohop(i, input4) << " "<<input1 << " ^" << input4 - i << " " << input3 << " ^" << i;
            }
            if (i < input4)
            {
                if (i % 2 == 0)
                {
                    cout << " - ";
                }
                else
                {
                    cout << " + ";
                } 
            }
        }
        }
    }
    
    
    cout << endl;
    system("Pause");
}