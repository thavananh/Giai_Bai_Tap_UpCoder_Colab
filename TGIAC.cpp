#include <iostream>
#include <cmath>
using namespace std;

struct diem {
    int tungDo, hoanhDo;
    public:
        friend float tinhkhoangcach(diem, diem);
};

struct tamgiac
{
   int x, y, z; 
};


istream& operator >> (istream &inp, diem &d) {
    inp >> d.hoanhDo >> d.tungDo;
    return inp;
}

ostream& operator << (ostream &output, diem d) {
    output << d.hoanhDo << "(," << d.tungDo << ")";
    return output;  
}

float tinhkhoangcach(diem d1, diem d2) {
   return sqrt(pow(d2.hoanhDo - d1.hoanhDo, 2) - pow(d2.tungDo - d1.tungDo, 2)); 
}

bool operator == (diem d1, diem d2) {
    if (d1.hoanhDo != d2.hoanhDo || d1.tungDo != d2.tungDo)
    {
        return false; 
    }
    return true; 
}

istream& operator >> (istream &inp, tamgiac &tg) {
    inp >> tg.x >> tg.y >> tg.z;
    return inp;
}

ostream& operator << (ostream &output, tamgiac tg) {
    output << tg.x << tg.y << tg.z;
    return output;
}


int main() {

}