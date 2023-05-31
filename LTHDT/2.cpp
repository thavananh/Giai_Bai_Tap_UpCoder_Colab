#include<iostream>
using namespace std;
//super CLASS
class HCN{
    float dai,rong;
public:
    //get-set
    float getDai(){
        return dai;
    }
    float getRong(){
        return rong;
    }
    void setDai(float x){
        dai = x;
    }
    void setRong(float x){
        rong = x;
    }
    //ktao-huy
    HCN(float _dai = 2, float _rong=1){
        dai=_dai;
        rong=_rong;
    }
    HCN(const HCN &h){
        dai=h.dai;
        rong=h.rong;
    }
    ~HCN(){};
    //nhap-xuat
    friend istream &operator >> (istream& is, HCN &h){
        is >> h.dai >>h.rong;
        return is;
    }
    friend ostream &operator << (ostream& os , HCN h){
        os <<"HCN: "<<h.dai<<" " <<h.rong<<endl;
        return os;
    }
    //ham bo tro
    void Set(float _dai = 2, float _rong=1){
        dai=_dai;
        rong=_rong;
    }
    float DT(){
        return dai*rong;
    }
};
//sup class
class HV:public HCN
{
    float canh;
public:
    void setCanh(float x){
        canh = x;
        HCN::Set(x,x);
    }
    //ktao-huy
    HV(float _canh=1){
        canh=_canh;
        HCN::Set(canh,canh);
    }
    HV(const HV &h){
        canh=h.canh;
        HCN::Set(canh,canh);
    }
    ~HV(){};
    //nhap-xuat
    friend istream &operator >> (istream& is, HV &h){
        is >> h.canh;
        return is;
    }
    friend ostream &operator << (ostream& os , HV h){
        os <<"HV: "<<h.canh<<endl;
        return os;
    }
    //ham bo tro
    void Set(float _canh=1){
        canh=_canh;
        HCN::Set(canh,canh);
    }
    //float DT(){ return canh*canh;}
    
};
int main(){
    HV hv(3);
    cout<<hv.DT()<<endl;
    return 0;
} 