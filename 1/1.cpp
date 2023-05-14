#include <iostream>

using namespace std;

char a[100][100];

bool check[100][100];

int xc,yc ;
int xb,yb;

int n,m;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

int number_of_cells_to_pass_through=0;
int imin;

void _try(int x , int y);


int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;j++){
            
            cin>>a[i][j];
            
            if(a[i][j]=='C') {
                xc = i ;
                yc = j ;
            }
            
            if(a[i][j]=='B') {
                xb = i ;
                yb = j ;
            }
        }
    }
    
    number_of_cells_to_pass_through=1;
    check[xc][yc]=true;
    imin=n*m;
    
    _try(xc,yc);
    cout<<imin-1;
}
void _try(int x, int y){
    if(x==xb && y==yb){
        if(number_of_cells_to_pass_through<imin)  
        imin=number_of_cells_to_pass_through;
        
    }
    else{
        for(int i=0;i<4;++i){
            int newx=x + dx[i];
            int newy=y + dy[i];
            if(newx>=0 && newx<n &&newy>=0 && newy<m 
                 && check [newx][newy]==false && a[newx][newy]!='*'){
                    check[newx][newy] =true;
                 ++number_of_cells_to_pass_through;
                
                 _try(newx,newy);
                
                 
                 --number_of_cells_to_pass_through;
                 check[newx][newy] =false;
                
            }
        }
    }
    
}