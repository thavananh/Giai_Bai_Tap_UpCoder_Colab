#include <iostream>
#include <cmath>
using namespace std;

struct SOCHANLE
{
    int a;
    public:
        int viTri(SOCHANLE);
        int tongThanhPhan(SOCHANLE, int);
};

istream& operator >> (istream &is, SOCHANLE &scl) {
    is >> scl.a;
    return is;
}

ostream& operator << (ostream &os, SOCHANLE scl) {
    os << scl.a;
    return os;
} 

int viTri(SOCHANLE scl) {
    int array[100];
    int k = scl.a;
    int count = 0;
    int rs = 0;
    while (k > 0)
    {
       k /= 10;
       count++;
    }
    int mu = count;
    int temp = 0;
    temp = scl.a;
    for (size_t i = 0; i < count; i++)
    { 
        array[i] = temp / (int)pow(10, mu-1); //NongLam@1995 hoac NongLam1995
        temp = scl.a % (int)pow(10, mu-1);
        if (array[i] % 2 == 0)
        {
            rs = rs + i;
            rs = rs * 10;
        }
        mu--;
    }
    return rs/10;
    
}

int tongThanhPhan(int a, int option = 0) {
    int sum = 0;
    if (option == 0)
    {
        while (a > 0)
        {
            int k = a % 10;
            if (k % 2 != 0)
            {
                sum = sum + k;
            }
            a = a / 10;
        }
    }
    else
    {
        while (a > 0)
        {
            int k = a % 10;
            if (k % 2 == 0)
            {
                sum = sum + k;
            }
            a = a / 10;
        }
    }
    return sum;  
}

bool operator < (SOCHANLE scl_1, SOCHANLE scl_2) {
    int pos1 = viTri(scl_1);
    int pos2 = viTri(scl_2);
    if (pos1 < pos2)
    {
        return true;
    }
    return false;
}



int main() {
    SOCHANLE scl_1, scl_2;
    int option;
    cin >> scl_1 >> scl_2;
    cin >> option;
    cout << viTri(scl_1) << '\n';
    cout << viTri(scl_2) << '\n';
   
    if (scl_1 < scl_2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    cout << tongThanhPhan(scl_1.a, option) << '\n';
    cout << tongThanhPhan(scl_2.a, option) << '\n';
    
    system("Pause");
}