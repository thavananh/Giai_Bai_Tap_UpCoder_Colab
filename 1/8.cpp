#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int a[105][105];
int cnt;

int di[4] = {-1, 0, 0, 1};

int dj[4] = {0, -1, 1, 0};

void f(int i, int j){
    
    a[i][j] = 1;
    
    for(int k=0;k<4;k++){
        int im = i + di[k];
        int jm = j + dj[k];
        if(im>=0 && im<n && jm>=0 && jm<m && a[im][jm]==0){
            cnt++;
            a[im][jm] = 1;
            f(im, jm);
        }
    }
}

int main(){
    cin >> n >> m >> x >> y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    cnt = 1;
    f(x-1, y-1);
    cout << cnt;
}