#include<iostream>

using namespace std;

class HCN
{
    float dai,rong;
public:
    float getDai(){
        return dai;
    }
    float getRong(){
        return rong;
    }
    void setDai(int x){
        dai=x;
    }
    void setRong(int x){
        rong=x;
    }
    HCN(float _dai=2,float _rong=1){
        dai=_dai;
        rong=_rong;
    }
    HCN(const HCN &h){
        dai=h.dai;
        rong=h.rong;
    }
    ~HCN(){}
    friend istream& operator >> (istream& is, HCN &h){
        is>>h.dai>>h.rong;
        return is;
    }
    friend ostream& operator << (ostream& os, HCN  a){
        os<<"[HCN]"<<a.dai<<a.rong;
        return os;
    }
    int Chuvi();
    friend bool operator<(HCN a,HCN b);
    friend int operator+(HCN a,int b);
  
   
};
int main ()
{
     HCN a,b;
     cin>>a>>b;
     cout<<a<<endl<<b<<endl;
     if (a<b)
     cout<<"true";
     else 
     cout<<"false";
     return 0;
}
int HCN::Chuvi(){
    return((dai+rong)*2);
}
bool operator<(HCN a,HCN b){
    return(a.Chuvi()<b.Chuvi());
}
int operator+(HCN a,int b){
    int k=a.Chuvi()+b;
    return(k);
}
