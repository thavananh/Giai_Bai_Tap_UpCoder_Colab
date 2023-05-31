#include<iostream>

using namespace std;

class HCN
{
    float dai,rong;
public:
    HCN(float _dai=2,float _rong=1){
        dai=_dai;
        rong=_rong;
    }
    HCN(const HCN &h){
        dai=h.dai;
        rong=h.rong;
    }
    ~HCN(){}
    int tinhCV(){
        return (dai+rong)*2;
    }
    int tinhDT(){
        return dai*rong;
    }
};
class HV:public HCN
{
    float canh;
public:
    HV(){}
    HV(float canh):HCN(canh,canh){}
};
int main(){
    string s;
    cin >> s;
    int cv_max = 0;
    if(s=="HCN"){
        int x,y;
        while(cin>>x>>y){
            HCN h(x,y);
            if (cv_max < h.tinhCV())
            cv_max = h.tinhCV();
        }
    }
    else{
        int x;
        while (cin>>x){
            HV h(x);
            if (cv_max< h.tinhCV())
                cv_max = h.tinhCV();
        }
    }
    
    cout<<cv_max;
}