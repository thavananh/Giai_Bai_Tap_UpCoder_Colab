#include <iostream>

using namespace std;

int n, m, x, y;
int danhdau[105][105];
int dem;

int dx[4] = {-1, 0, 0, 1};

int dy[4] = {0, -1, 1, 0};

void quay_lui(int i, int j){
    
    danhdau[i][j] = 1;
    
    for(int k=0;k<4;k++)
    {
        int imoi = i + dx[k];
        int jmoi = j + dy[k];
        if(imoi>=0 && imoi<n && jmoi>=0 && jmoi<m && danhdau[imoi][jmoi]==0){
            dem++;
            danhdau[imoi][jmoi] = 1;
            quay_lui(imoi, jmoi);
        }

    }
}


int main(){
    cin >> n >> m >> x >> y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> danhdau[i][j];
    }
    dem = 1;
    quay_lui(x-1, y-1);
    cout << dem;
}