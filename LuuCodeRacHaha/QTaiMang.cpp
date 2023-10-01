#include <iostream>
#include <cstdlib>
using namespace std;
struct Mang {
    int numberOfElemnt, array[100];
    int* ptr;
    public:
        void operator = (const Mang &m) {
            numberOfElemnt = m.numberOfElemnt;
            for (size_t i = 0; i < m.numberOfElemnt; i++)
            {
                array[i] = m.array[i];
            }
        }
        int& operator[](int);
};

int operator + (Mang a, Mang b);
istream& operator >> (istream &input, Mang &m);
ostream& operator << (ostream &output, Mang m);
bool operator == (Mang a, Mang b);
bool operator != (Mang a, Mang b); 

int main() {
    Mang m1, m2;
    cin >> m1 >> m2;
    if (m1 == m2)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}

int operator + (Mang a, Mang b) {
    int sum = 0;
    for (size_t i = 0; i < a.numberOfElemnt; i++)
    {
       sum = sum + a.array[i]; 
    }
    for (size_t i = 0; i < b.numberOfElemnt; i++)
    {
       sum = sum + b.array[i]; 
    }
    return sum;
    
}

istream& operator >> (istream &input, Mang &m) {
    input >> m.numberOfElemnt;
    for (size_t i = 0; i < m.numberOfElemnt; i++)
    {
        input >> m.array[i];
    }
    return input;
}

ostream& operator << (ostream &output, Mang m) {
    for (size_t i = 0; i < m.numberOfElemnt; i++)
    {
        output << m.array[i] << " ";
    }
    return output;
}

bool operator == (Mang a, Mang b) {
    if (a.numberOfElemnt != b.numberOfElemnt)
    {
        return false;
    }
    else  
    {
       for (size_t i = 0; i < a.numberOfElemnt; i++)
       { 
           if (a.array[i] == b.array[i])
           {
                continue;
           }
           else
           {
                return false;
           }
            
       }
       return true; 
    }
    
}

bool operator != (Mang a, Mang b) {
    if (a.numberOfElemnt != b.numberOfElemnt)
    {
        return true;    
    }
    else
    {
        for (size_t i = 0; i < a.numberOfElemnt; i++)
        {
            if (a.array[i] != b.array[i])
            {
                return true; 
            }
            else
            {
                continue;
            } 
        }
        return false; 
    }
}

int& Mang::operator[](int index) {
    if (index >= numberOfElemnt) {
        cout << "Vuot qua so phan tu";
        exit(0);
    }
    return ptr[index]; 
    
}