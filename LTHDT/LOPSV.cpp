#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/**Khai bao lop nguoi*/
class Nguoi{
    string hoten, quequan;
    int namsinh;
public:
    string getHoTen();
    void setHoTen(string s);
    string getQueQuan();
    void setQueQuan(string s);
    int getNamSinh();
    void setNamSinh(int s); 

    Nguoi(string _hoten="hoten", int _namsinh=2000, string _quequan="quequan");
    Nguoi(const Nguoi &n);
    ~Nguoi();

    friend istream& operator >> (istream& is, Nguoi &n);
    friend ostream& operator << (ostream& os, Nguoi  n);

    void Set(string _hoten="hoten", int _namsinh=2000, string _quequan="quequan");
};
/*Khai bao lop sv*/

int main(){
    return 0;
}
/*Dinh nghia ham tp lop nguoi*/
string getHoTen();
void setHoTen(string s);
string getQueQuan();
void setQueQuan(string s);
int getNamSinh();
void setNamSinh(int s); 

Nguoi(string _hoten="hoten", int _namsinh=2000, string _quequan="quequan");
Nguoi(const Nguoi &n);
~Nguoi();

friend istream& operator >> (istream& is, Nguoi &n);
friend ostream& operator << (ostream& os, Nguoi  n);

void Set(string _hoten="hoten", int _namsinh=2000, string _quequan="quequan");