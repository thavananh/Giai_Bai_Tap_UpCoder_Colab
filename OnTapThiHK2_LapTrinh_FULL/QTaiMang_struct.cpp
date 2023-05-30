#include <iostream>
using namespace std;

struct M1C 
{
    int n;
    int a[1000];
};

istream &operator >> (istream &is, M1C &m)
{
    is >> m.n;
    for (size_t i = 0; i < m.n; i++)
    {
        cin >> m.a[i];
    }
    return is;
}

ostream &operator << (ostream &os, M1C m)
{
    for (size_t i = 0; i < m.n; i++)
    {
        os << m.a[i] << " ";
    }
    return os;
}



int main()
{

}