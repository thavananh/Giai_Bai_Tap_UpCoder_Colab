#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int a;
    int b;
    ifstream FILE_IN("input.txt");
    if (FILE_IN.is_open())
    {
        FILE_IN >> a >> b;
        FILE_IN.close();
    }
    ofstream FILE_OUT("output.txt");
    if (FILE_OUT.is_open())
    {
        FILE_OUT << a + b;
        FILE_OUT.close();
    }
}