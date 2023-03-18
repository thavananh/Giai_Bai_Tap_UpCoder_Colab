#include <iostream>
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
    int result = 0;
    int count = 0;
    while (scl.a > 0)
    {   
        array[count] = scl.a % 10;
        scl.a = scl.a / 10;
        count++;
    }
    int j = 0;
    for (size_t i = count; i > 0; i--)
    {
        if (array[i] % 2 == 0)
        {
            result = (result + j)*10;
        }
        j++;
    }
    return result;
}

int tongThanhPhan(SOCHANLE scl, int option = 0) {
    int sum = 0;
    if (option == 0)
    {
        while (scl.a > 0)
        {
            int k = scl.a % 10;
            if (k % 2 != 0)
            {
                sum = sum + k;
            }
            scl.a = scl.a / 10;
        }
    }
    else
    {
        while (scl.a > 0)
        {
            int k = scl.a % 10;
            if (k % 2 == 0)
            {
                sum = sum + k;
            }
            scl.a = scl.a / 10;
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
    cout << tongThanhPhan(scl_1, option) << '\n';
    cout << tongThanhPhan(scl_2, option) << '\n';
    
    system("Pause");
}