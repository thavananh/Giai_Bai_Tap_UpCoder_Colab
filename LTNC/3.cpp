#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==0)
    {
        cout << 0;
        return 0;
    }
    vector<int> v;
    while(n)
    {
        v.push_back(n%2);
        n/=2;
    }
    
    int j = v.size();
    
    for(int i=j-1;i>=0;i--) 
    cout << v[i];
}