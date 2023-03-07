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
   int x, y, z, t, k, f;
   float chuvi;
   public:
        float chuvitamgiac(tamgiac tg);
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
   return sqrt(pow(d2.hoanhDo - d1.hoanhDo, 2) + pow(d2.tungDo - d1.tungDo, 2)); 
}

bool operator == (diem d1, diem d2) {
    if (d1.hoanhDo != d2.hoanhDo || d1.tungDo != d2.tungDo)
    {
        return false; 
    }
    return true; 
}

istream& operator >> (istream &inp, tamgiac &tg) {
    inp >> tg.x >> tg.y >> tg.z >> tg.t >> tg.k >> tg.f;
    return inp;
}

ostream& operator << (ostream &output, tamgiac tg) {
    output << "(" << tg.x << "," << tg.y << ")" << "(" << tg.z << "," << tg.t << ")" << "(" << tg.k << "," << tg.f << ")";
    return output;
}

float chuvitamgiac(tamgiac tg) {
    float canh1 = sqrt(pow(tg.z - tg.x, 2) + pow(tg.t - tg.y, 2));
    float canh2 = sqrt(pow(tg.k - tg.x, 2) + pow(tg.f - tg.y, 2));
    float canh3 = sqrt(pow(tg.k - tg.z, 2) + pow(tg.f - tg.t, 2));
    tg.chuvi = canh1 + canh2 + canh3;
    return tg.chuvi;
}

float operator + (tamgiac tg1, tamgiac tg2) {
    return chuvitamgiac(tg1) + chuvitamgiac(tg2);
}

bool operator < (tamgiac tg1, tamgiac tg2) {
    if (chuvitamgiac(tg1) < chuvitamgiac(tg2))
    {
        return true;
    }
    return false;
}

bool operator == (tamgiac tg1, tamgiac tg2) {
    if ((tg1.x == tg2.x && tg1.y == tg2.y && tg1.z == tg2.z && tg1.t == tg2.t && tg1.k == tg2.k && tg1.f == tg2.f) && (chuvitamgiac(tg1) == chuvitamgiac(tg2)))
    {
        return true;
    }
    return false;
}

int main() {
    tamgiac tg1, tg2;
    cin >> tg1;
    cin >> tg2;
    cout << tg1 << '\n' << tg2 << '\n';
    if (tg1 < tg2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    if (tg1 == tg2)
    {
        cout << "TRUE" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }
    
    
    
    system("Pause");
}