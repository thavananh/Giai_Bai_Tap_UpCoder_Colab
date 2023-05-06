#include <iostream>
#include <string>
#include <math.h>
 
using namespace std;
 

 
int main(){
    int N = 0;
    string a[10000];
    cin >> N;
    int n = 2;
    a[0] = "0";
    a[1] = "1";
    int k = 0;
    while (a[k].length() < N){
        a[n++] = a[k] + "0";
        a[n++] = a[k] + "1";
        k++;
    }
    for (int i = k; i < n; i++)
        cout << a[i] << endl;
}