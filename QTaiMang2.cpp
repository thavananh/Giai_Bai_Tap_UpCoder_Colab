#include <iostream>
using namespace std;

struct Mang {
    int n, array[100];
};

istream& operator >> (istream &input, Mang &m);
ostream& operator << (ostream &ouput, Mang m);
Mang operator + (Mang m1, Mang m2);

int main() {
   Mang m1, m2, m3;
   cin >> m1 >> m2; 
   m3 = m1 + m2;
   cout << m3; 
<<<<<<< HEAD
   system("Pause");
=======
>>>>>>> 5bce2d420b2a83be5a4549c1b68da2598547f272
}

istream& operator >> (istream &input, Mang &m) {
    input >> m.n;
<<<<<<< HEAD
    for (size_t i = 0; i < m.n; i++)
=======
    for (int i = 0; i < m.n; i++)
>>>>>>> 5bce2d420b2a83be5a4549c1b68da2598547f272
    {
        input >> m.array[i]; 
    } 
    return input;
}
ostream& operator << (ostream &output, Mang m) {
<<<<<<< HEAD
    for (size_t i = 0; i < m.n; i++)
=======
    for (int i = 0; i < m.n; i++)
>>>>>>> 5bce2d420b2a83be5a4549c1b68da2598547f272
    {
        output << m.array[i] << " "; 
    }
    return output;
}
Mang operator + (Mang m1, Mang m2) {
    Mang rs;
    if (m1.n <= m2.n)
    {
        rs.n = m2.n;
        rs.array[rs.n - 1] = m2.array[rs.n - 1];
        for (size_t i = 0; i < m1.n; i++)
        {
<<<<<<< HEAD
=======
            rs.array[i] = 0;
>>>>>>> 5bce2d420b2a83be5a4549c1b68da2598547f272
            rs.array[i] += m2.array[i] + m1.array[i];
        }
        
        
    }
    else
    {
        rs.n = m1.n;
        rs.array[rs.n - 1] = m1.array[rs.n - 1];
        for (size_t i = 0; i < m2.n; i++)
        {
<<<<<<< HEAD
=======
            rs.array[i] = 0;
>>>>>>> 5bce2d420b2a83be5a4549c1b68da2598547f272
            rs.array[i] += m2.array[i] + m1.array[i];
        }
        
    }
<<<<<<< HEAD
    return rs; 
=======
    return rs;
>>>>>>> 5bce2d420b2a83be5a4549c1b68da2598547f272
    
}