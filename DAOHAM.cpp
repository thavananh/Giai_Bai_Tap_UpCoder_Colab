#include <iostream>
using namespace std;

struct DaoHam {
    int mu;
    int n;
    int a[1000];
    public:
        DaoHam biendoidaoham();
};

istream &operator >> (istream &is, DaoHam &dh) {
    is >> dh.mu;
    dh.n = 0;
    while (is >> dh.a[dh.n])
    {
        dh.n++;
    }
    return is;
}

ostream &operator << (ostream &os, DaoHam dh) {
    for (size_t i = 0; i < dh.n; i++)
    {
        if (dh.a[i] != 0)
        {
            if (i == dh.n - 1)
            {
                if (dh.a[i] > 0)
                {
                    os << "+" << dh.a[i];
                    break;
                }
                else
                {
                    os << dh.a[i];
                    break;
                }
            }
            if (dh.mu == 1)
            {   
                if (dh.a[i] > 0 && i != 0)
                {
                    if (dh.a[i] == 1)
                    {
                        os << "+" << "x";
                    }
                    else
                    {
                        os << "+" << dh.a[i] << "x";
                    }
                }
                else
                {
                    if (dh.a[i] == -1)
                    {
                        os << "-x";
                    }
                    else
                    {
                        os << dh.a[i] << "x";
                    }
                }
            }
            else
            {
                if (dh.a[i] > 0 && i != 0)
                {
                    if (dh.a[i] == 1)
                    {
                        os << "+" << "x^" << dh.mu;
                    }
                    else
                    {
                        os << "+" << dh.a[i] << "x^" << dh.mu;
                    }         
                }
                else
                {
                    if (dh.a[i] == -1)
                    {
                        os << "-x^" << dh.mu;
                    }
                    else
                    {
                        os << dh.a[i] << "x^" << dh.mu;
                    }
                }
            }
        }
        dh.mu--;
    }
    return os;
}

DaoHam DaoHam::biendoidaoham() {
    DaoHam rs;
    rs.mu = this->mu - 1;
    int temp = this->n;
    for (size_t i = 0; i < this->n; i++)
    {
        if (this->a[i] == 0)
        {
            temp--;
            continue;
        }
        rs.a[i] = this->a[i]*this->mu;
        this->mu--;
    }
    rs.n = temp;
    return rs;
}

int main() {
    DaoHam dh1;
    cin >> dh1;
    cout << dh1 << '\n';
    cout << dh1.biendoidaoham() << '\n';
}