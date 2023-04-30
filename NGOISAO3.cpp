#include <iostream>
using namespace std;

int main() {
    int dai, rong;
    cin >> dai >> rong;
    for (size_t i = 0; i < dai; i++)
    {
        for (size_t j = 0; j < rong; j++)
        {
            if (i == 0 || i == dai - 1)
            {
                cout << "*";
            }
            else
            {
                if (j == 0 || j == rong - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        if (i == dai - 1)
        {
            break;
        }
        else
        {
            cout << '\n';
        }
    }
    system("Pause");
}