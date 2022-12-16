#include <iostream>
using namespace std;

int main(){
    int a = 3, b= 4;
    int t = ++a>--b?++a:b--;
    cout << t+a+b;
    
}
