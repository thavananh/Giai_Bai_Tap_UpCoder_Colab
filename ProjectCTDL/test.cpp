#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string input = "4801104035 123456";
    string test;
    stringstream ss(input);
    ss >> test;
    cout << test;
    system("pause");
}