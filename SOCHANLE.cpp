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
int viTri(SOCHANLE scl) {
    int array[100000];
    int k = scl.a;
    int count = 0;
    int rs = 0;
    while (k > 0)
    {
       k /= 10;
       count++;
    }
    int mu = count;
   
    for (size_t i = 0; i < count; i++)
    { 
        array[i] = (scl.a / (int)pow(10, mu - 1)) % 10;
        mu--;
    }
    for (size_t i = 0; i < count; i = i + 2)
    {
        rs = (rs + array[i])*10;
    }
    return rs/10;
}
istream& operator >> (istream &is, SOCHANLE &scl) {
    is >> scl.a;
    return is;
}

ostream& operator << (ostream &os, SOCHANLE scl) {
    os << viTri(scl);
    return os;
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
    cout << scl_1 << '\n';
    cout << scl_2 << '\n';
   
    if (scl_1 < scl_2)
    {
        cout << "true" << '\n';
    }
    else
    {
        cout << "false" << '\n';
    }
    cout << tongThanhPhan(scl_1.a, option) << '\n';
    cout << tongThanhPhan(scl_2.a, option) << '\n';

}