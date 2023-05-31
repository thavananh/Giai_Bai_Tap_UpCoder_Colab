#include <iostream>

using namespace std;

int n, m;
char a[100][100];
int min_val;

int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

void f(int i, int j, int cnt){
    if(i==n-1 && j==m-1){
        min_val = min(min_val, cnt);
        return;
    }
    for(int k=0;k<4;k++){
        int im = i + di[k];
        int jm = j + dj[k];
        if(im>=0 && im<n && jm>=0 && jm<m && (a[im][jm]=='.' || a[im][jm]=='C')){
            cnt++;
            a[i][j] = ' ';
            f(im, jm, cnt);
            cnt--;
            a[i][j] = '.';
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> a[i][j];
    }

    
    min_val = 1e9;
    
    f(0, 0, 0);
    
    cout << min_val;
}