#include <iostream>
using namespace std;

void thayDoiA(int *&a)
{
    int* b = a;
    *b = 10;
}

int main()
{
    int value = 5;
    int* a = &value;
    thayDoiA(a);

}