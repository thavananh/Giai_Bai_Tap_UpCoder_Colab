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
}

istream& operator >> (istream &input, Mang &m) {
    input >> m.n;
    for (int i = 0; i < m.n; i++)
    {
        input >> m.array[i]; 
    } 
    return input;
}
ostream& operator << (ostream &output, Mang m) {
    for (int i = 0; i < m.n; i++)
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
            rs.array[i] = 0;
            rs.array[i] += m2.array[i] + m1.array[i];
        }
        
        
    }
    else
    {
        rs.n = m1.n;
        rs.array[rs.n - 1] = m1.array[rs.n - 1];
        for (size_t i = 0; i < m2.n; i++)
        {
            rs.array[i] = 0;
            rs.array[i] += m2.array[i] + m1.array[i];
        }
        
    }
    return rs;
    
}