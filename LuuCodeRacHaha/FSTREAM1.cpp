#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

bool scp(int n) {
    int m = sqrt(n);
    if (m*m == n)
    {
        return true;
    }
    return false;
}

int main() {
    ifstream in_file("FSTREAM.txt");
    
    vector<int>v;
    int n;
    if (in_file.is_open())
    {
        string line;
        while (getline(in_file, line))
        {
            n = stoi(line);
        }
        in_file.close();
    }
    else
    {
        cout << "ngu";
    }
    ofstream out_file("FSTREAM_OUT.txt");
    if (out_file.is_open())
    {
        if (scp(n)) 
        {
            out_file << "YES";
        }
        else
        {
            out_file << "NO";
        }
        out_file.close();
    }
}