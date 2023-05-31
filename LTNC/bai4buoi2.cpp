#include <iostream>

using namespace std;

char a[100][100];

bool danhdau[100][100];

int xc,yc ;//tọa độ con bò
int xb,yb;//tọa độ chuồng bò

int n,m;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

int so_o_di_qua=0;
int imin;

void _thu(int x , int y);


int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;j++){
            
            cin>>a[i][j];
            
            if(a[i][j]=='C') {// toa do xuat phat cua bo
                xc = i ;
                yc = j ;
            }
            
            if(a[i][j]=='B') {// toa do xuat phat cua bo
                xb = i ;
                yb = j ;
            }
        }
    }
    //di tu o xuat phat
    so_o_di_qua=1;
    danhdau[xc][yc]=true;
    imin=n*m;
    
    _thu(xc,yc);
    cout<<imin-1;// khong tinh o ket thuc
}
void _thu(int x, int y){
    if(x==xb && y==yb){
        if(so_o_di_qua<imin)  imin=so_o_di_qua;
        
    }
    else{
        for(int i=0;i<4;++i){
            int newx=x + dx[i];
            int newy=y + dy[i];
            if(newx>=0 && newx<n &&newy>=0 && newy<m //đk 1 : toa do moi phai nam trong ban do
                 && danhdau [newx][newy]==false && a[newx][newy]!='*'){
                
                  danhdau[newx][newy] =true;
                 ++so_o_di_qua;
                
                 _thu(newx,newy);
                
                 //quay lui lại
                 --so_o_di_qua;
                 danhdau[newx][newy] =false;
                
            }
        }
    }
    
}