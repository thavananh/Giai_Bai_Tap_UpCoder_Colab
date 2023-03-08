#include <iostream>
using namespace std;
template <typename T>
struct Mang
{
    int element;
    T array[100];
};


template <typename T>
istream& operator >> (istream &input, Mang <T> &m) {
   input >> m.element; 
   for (size_t i = 0; i < m.element; i++)
   {
     input >> m.array[i];
   }
   return input;
}

template <typename T>
ostream& operator << (ostream &output, Mang<T> m) {
    for (size_t i = 0; i < m.element; i++)
    {
        output << m.array[i] << " ";
    } 
    return output;
}

int main() {
    Mang<int>m;
    cin >> m;
    cout << m;
    system("Pause");
}