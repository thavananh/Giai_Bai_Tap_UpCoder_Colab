#include <iostream>
using namespace std;
struct Mang {
    int numberOfElemnt, array[100];
    public:
        // void operator = (const Mang &m) {
        //     numberOfElemnt = m.numberOfElemnt;
        //     for (size_t i = 0; i < m.numberOfElemnt; i++)
        //     {
        //         array[i] = m.array[i];
        //     }
        // }
};

void Mang::operator = (const Mang &m);

istream& operator >> (istream &input, Mang &m);
ostream& operator << (ostream &output, Mang m);

int main() {
    Mang m1, m2;
    cin >> m1;
    system("Pause");

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
