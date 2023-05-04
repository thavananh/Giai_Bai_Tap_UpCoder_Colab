
#include <iostream>
#include <string>

using namespace std;

char a[100][100];
int n,m,x,y;
string z; //chuoi can tim
bool danhdau[100][100]; //true: da di qua, false: chua di qua
int stt = 0 ;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool flag = false;

void Try(int x, int y){
    if (stt == z.size()-1){
        cout<<"YES"<<endl;
        cout<<"("<<x<<","<<y<<")"<<endl;
        flag = true;
    }
    else{
        for (int i=0;i<4;++i){
            int xx = x + dx [i];
            int yy = y + dy [i];
            if (0<=xx && xx <n && 0<=yy && yy <m
                && danhdau[xx][yy]==false && a[xx][yy]==z[stt+1]){
                    danhdau[xx][yy] = true;
                    ++stt;
                    Try(xx,yy);
                    --stt;
                    danhdau[xx][yy]=false;
                }
        }
    }
}

int main(){
    cin>>n>>m>>x>>y;
    cin>>z;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    
    /*
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j)
            cout<<danhdau[i][j]<<" ";
        cout<<endl;
    }
    */
    
    if (a[x][y]==z[stt]){
        danhdau[x][y] = true;
        Try(x,y);
    }
    if (flag == false)
        cout<<"NO";
    return 0;
}
