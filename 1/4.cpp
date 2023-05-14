#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream ifile("input.txt");
    ofstream ofile("output.txt");
    int a,b;
    ifile>>a>>b;
    ofile<< a+b;

}