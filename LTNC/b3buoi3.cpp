#include <iostream>

using namespace std;

bool kt_nt(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return n>1;
}

int tong(int n){
    int sum=0;
    while(n){
        int t = n%10;
        if(t!=2 && t!=3 && t!=5 && t!=7) sum += t;
        n/=10;
    }
    return sum;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(kt_nt(n)){
            cout << tong(n) << endl;
        }
        else cout << -1 << endl;
    }
}