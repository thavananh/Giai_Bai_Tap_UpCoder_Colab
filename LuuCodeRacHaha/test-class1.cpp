#include <iostream>
using namespace std;

class ELEPHANT {
        int age, root;
        float weight;
    public:
        void Set(int, float, int);
        void Fater(float);
        void Older(int);
        void Print();
        void Trumpet();
};

void ELEPHANT::Set(int a, float w, int r) {
    this->age = a;
    this->weight = w;
    this->root = r;
}

void ELEPHANT::Fater(float w) {
    this->weight = w;
}

void ELEPHANT::Older(int a) {
    this->age = this->age + a;
}

void ELEPHANT::Print() {
    if (this->root == 0)
    {
        cout << "Toi la voi Chau A.";
    }
    else
    {
        cout << "TOi la voi Chau Phi.";
    }
    cout << "Toi " << age << " tuoi";
    cout << "Toi nang" << weight << " tan";
}

void ELEPHANT::Trumpet() {
    cout << "Voi dang rong.";
}

int main() {
    ELEPHANT a;
    a.Set(1, 1.0, 0);
    a.Print();
    a.Fater(1.5);
    a.Older(1);
    a.Trumpet();
    Set(10, 5.0, 1);
    a.Set(5, 4.5);
    a.age = 8;
    system("Pause");
}