#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int sodaonguoc(int n) {
    int sum = 0;
    while (n)
    {
        sum = sum + n % 10;
        sum = sum * 10;
        n = n / 10;
    }
    return sum/10;
}

int main() {
    ifstream file_in("inDaoNguoc2.txt");
    vector<int>pos;
    int i = 0;
    int max = -999999;
    if (file_in.is_open())
    {
        string line;
        while (getline(file_in, line))
        {
            int n = stoi(line);
            int k = sodaonguoc(n);
            if (k >= max)
            {
                max = k;
                pos.push_back(i);
            }
            i++;
        }
        file_in.close();
    }
    ofstream file_out("outDaoNguoc2.txt");
    if (file_out.is_open()) 
    {
        file_out << sodaonguoc(max) << '\n';
        for (auto it : pos) {
            file_out << it << " ";
        }
        file_out.close();
    }
    
}