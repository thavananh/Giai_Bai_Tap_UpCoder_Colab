#include <iostream>
#include <string>
using namespace std;

class nguoi
{
    string hoten, quequan;
    int namsinh;
    public:
        nguoi(string _hoten = "", string _quequan = "", int _namsinh = 0)
        {
            this->hoten = _hoten;
            this->quequan = _quequan;
            this->namsinh = _namsinh;
        }
        nguoi(const nguoi &ng)
        {
            this->hoten = ng.hoten;
            this->quequan = ng.quequan;
            this->namsinh = ng.namsinh;
        }
        ~nguoi()
        {

        }
        friend istream &operator >> (istream &is, nguoi &ng)
        {
            getline(is, ng.hoten);
            is >> ng.namsinh;
            is.ignore();
            getline(is, ng.quequan);
        }
        friend ostream &operator << (ostream &os, nguoi ng)
        {
            os << "Ho Ten: " << ng.hoten << '\n';
            os << "Nam Sinh: " << ng.namsinh << '\n';
            os << "Que quan: " << ng.quequan << '\n';
            return os;
        }
        string getHoTen()
        {
            return this->hoten;
        }
        string getQueQuan()
        {
            return this->quequan;
        }
};

int main()
{

}