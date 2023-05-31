#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool scp(int n)
{
    int m = sqrt(n);
    if (m*m == n)
    {
        return true;
    }
    return false;
}

int main()
{
    ifstream file_in("FSTREAM.inp");
    int n;
    if (file_in.is_open())
    {
        file_in >> n;
        file_in.close();
    }
    ofstream file_out("FSTREAM_OUT.out");
    if (file_out.is_open())
    {
        if (scp(n))
        {
            file_out << "YES";
        }
    }
}