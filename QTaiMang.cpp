#include <iostream>
using namespace std;
struct Mang {
    int numberOfElemnt, array[100];
    public:
        Mang &operator = (const Mang &m);
};

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

Mang& Mang::operator = (const Mang &m) {
    for (size_t i = 0; i < m.numberOfElemnt; i++)
    {
        
    }
    
}

int main() {
    Mang m;
    cin >> m;

}