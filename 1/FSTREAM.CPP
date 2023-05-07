#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("FSTREAM.inp");
    ofstream fout("FSTREAM.out");
    int n;
    fin >> n;
    if (sqrt(n) == round(sqrt(n))) 
    {
        fout << "YES";
    } else {
        fout << "NO";
    }

    fin.close();
    fout.close();
    return 0;
}
