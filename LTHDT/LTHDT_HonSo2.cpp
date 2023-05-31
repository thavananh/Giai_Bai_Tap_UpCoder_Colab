#include<iostream>
#include<math.h>

using namespace std;

class PhanSo{
    int tu,mau;
public:
    int getTu(){
        return tu;
    }
    int getMau(){
        return mau;
    }
    void setTu(int x){
        tu=x;
    }
    void setMau(int x){
        mau=x;
    }
    PhanSo(int _tu=0, int _mau=1){
        tu=_tu;
        mau=_mau;
    }
    PhanSo(const PhanSo& p){
        tu=p.tu;
        mau=p.mau;
    }
    friend istream& operator>>(istream& is, PhanSo &p){
        is>>p.tu>>p.mau;
        return is;
    }
    friend ostream& operator<<(ostream& os, PhanSo p){
        os<<p.tu<<"/"<<p.mau;
        return os;
    }
    PhanSo operator+(PhanSo a){
        PhanSo c;
        c.tu=tu*a.mau+a.tu*mau;
        c.mau=a.mau*mau;
        return c;
    }
    void RutGon(){
        int a=abs(tu),b=abs(mau);
        while(a!=b)
        {
            if(a>b) a-=b;
            if(a<b) b-=a;
        }
        tu/=a;
        mau/=a;
    }
};
class HonSo:public PhanSo{
    int nguyen;
public:
    void setNguyen(int x){
        nguyen=x;
    }
    HonSo(int _nguyen=0){
        nguyen=_nguyen;
    }
    HonSo(const HonSo& p){
        nguyen=p.nguyen;
    }
    friend istream& operator>>(istream& is,HonSo &p){
        int tuso,mauso,nguyen;
      is>>nguyen>>tuso>>mauso;
      if(nguyen<0) tuso=0-tuso;
      p=HonSo(nguyen,tuso,mauso);
     return is;
    }
    friend ostream& operator<<(ostream& os,HonSo p){
    p.PhanSo::RutGon();
    os<<p.nguyen<<" "<<p.getTu()<<"/"<<p.getMau();
    return os;
    }
    HonSo operator+(HonSo a){
    HonSo c(nguyen+a.nguyen,getTu()*a.getMau()+a.getTu()*getMau(),a.getMau()*getMau());
    return c;
    }
};
int main(){
    HonSo a[2];
    cin>>a[0]>>a[1];
    cout<<a[0]+a[1];
}