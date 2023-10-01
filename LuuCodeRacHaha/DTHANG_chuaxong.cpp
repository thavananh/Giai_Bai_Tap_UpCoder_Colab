#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct DTHANG
{
    int a, b, c;
    public:
        friend void vitrituondoi(DTHANG d1, DTHANG d2);
};

istream &operator >> (istream &is, DTHANG &d) {
    is >> d.a >> d.b >> d.c;
    return is;
}

ostream &operator << (ostream &os, DTHANG d) {
    if (d.a != 0)
    {
        if (d.a == 1)
        {
            os << "x ";
        }
        else
        {
            os << d.a << "x ";
        }
    }
    if (d.b != 0)
    {
        if (d.b == 1)
        {
            os << "+ y";
        }
        else
        {
            if (d.b > 0) 
            {
                os << "+ " << d.b << "y ";
            }
            else
            {
                os << "- " << abs(d.b) << "y ";
            }
        }
    }
    if (d.c != 0)
    {
        if (d.c > 0)
        {
            os << "+ " << d.c;
        }
        else
        {
            os << "- " << abs(d.c);
        }
    }
    os << " = 0";
    return os;
}

bool operator == (DTHANG d1, DTHANG d2) {
    return d1.a == d2.a && d1.b == d2.b && d1.c == d2.c;
}

void vitrituondoi(DTHANG d1, DTHANG d2) {
    int D = d1.a*d2.b - d2.a*d1.b;
    int Dx = d1.c*d2.b - d2.c*d1.b;
    int Dy = d1.a*d2.c - d2.a*d1.c;
    int x, y;
    if (D != 0)
    {
        x = Dx / D;
        y = Dy / D;
        if (d1.a*d2.a + d1.b * d2.b == 0) {
        cout << "V" << '\n';
        cout << "(" << x << ", " << y << ")";
        }
        else {
        cout << "C" << '\n';
        cout << "(" << x << ", " << y << ")";
        }
    }
    else if (D == 0)
    {
        if (Dx == 0 && Dy == 0)
        {
            cout << "T" << '\n';
            cout << 0;
        }
        else
        {
            cout << "S" << '\n';
            double khoangcach = (abs(d1.a*0 + d1.a*0 + d1.c))/(sqrt(pow(d1.a, 2) + pow(d2.b, 2)));
            cout << setiosflags(ios::fixed) << setprecision(3) << khoangcach;
        }
    }
    
}


int main() {
    DTHANG d1, d2;
    cin >> d1 >> d2;
    cout << d1 << '\n';
    cout << d2 << '\n';
    vitrituondoi(d1, d2);
}