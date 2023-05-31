#include <iostream>
#include <string>
using namespace std;

struct Ngay{
   string ngay, thang, nam;
};
istream& operator >> (istream &in, Ngay &n){
    string ngay;
    getline(in,ngay);
    if(ngay[2] < '0' && ngay[2] < '9'){
        n.ngay = ngay.substr(0,2);
        n.thang = ngay.substr(3,2);
        n.nam = ngay.substr(6,4);
        return in;
    }else{
        if(ngay[2] == '_'){
            n.ngay = ngay.substr(0,2);
            n.thang = ngay.substr(3,2);
            n.nam = ngay.substr(6,4);
            return in;
        }
        n.ngay = ngay.substr(0,2);
        n.thang = ngay.substr(2,2);
        n.nam = ngay.substr(4,4);
        return in;
    }
    
}
ostream& operator << (ostream& out, Ngay n){
    out << n.ngay << "/" << n.thang << "/" << n.nam;
    return out;
}
struct Cauthu{
    string ma;
    string ten;
    Ngay ngay;
};
istream& operator >> (istream &in, Cauthu &n){
    getline(in,n.ma);
    getline(in,n.ten);
    in>>n.ngay;
    return in;
}
ostream& operator << (ostream& out, Cauthu n){
    out << n.ma << "\n" << n.ten << "\n" << n.ngay;
    return out;
}
int main(){
    Cauthu a;
    cin>>a;
    cout<<a;
}