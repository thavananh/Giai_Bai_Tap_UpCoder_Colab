#include <iostream>

using namespace std;

class HCN{
    private:
        int dai,rong;
    public:
        HCN(){
            dai = 0; 
            rong = 0;
        }
        HCN(int d, int r){
            dai = d;
            rong = r;
        }
        int tinhCV(){
            return (dai+rong)*2;
        }
        int tinhDT(){
            return dai*rong;
        }
};

class HV:public HCN{
    public:
        HV(){}
        HV(int c):HCN(c,c){}
};

int main(){
    string s;
    cin>>s;
    
    int imax = 0;
    if (s == "HCN"){
        int x,y;
        while (cin>>x>>y){
            HCN h(x,y);
            if (imax < h.tinhCV())
                imax = h.tinhCV();
        }
    }
    else{
        int x;
        while (cin>>x){
            HV h(x);
            if (imax < h.tinhCV())
                imax = h.tinhCV();
        }
    }
    
    cout<<imax;
    
    return 0;
}