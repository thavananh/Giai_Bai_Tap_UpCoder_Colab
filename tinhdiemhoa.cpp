#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct diemTrungBinhHoa
{
    string s;
    double a, b;
};

istream &operator >> (istream &is, diemTrungBinhHoa &d)
{
    is >> d.s;
    is >> d.a >> d.b;
    is.ignore();
    return is;
}

ostream &operator << (ostream &os, diemTrungBinhHoa d)
{
    os << d.s << " ";
    if (d.a > 0 && d.b > 0) {
        os << fixed << setprecision(1) << (double)(d.a + d.b) / 2;
    }
    os << endl;
    return os;
}

bool operator < (diemTrungBinhHoa d1, diemTrungBinhHoa d2)
{
    return double(d1.a + d1.b)/2 < double(d2.a + d2.b)/2;
}

int main ()
{
    diemTrungBinhHoa d[100];
    int n;
    cin >> n;
    cin.ignore();
    diemTrungBinhHoa temp;
    for (size_t i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << d[i] << '\n';
    // }
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (d[i] < d[j])
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
            
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << i+1 << " " << d[i] << '\n';
    }
    system("Pause");
}