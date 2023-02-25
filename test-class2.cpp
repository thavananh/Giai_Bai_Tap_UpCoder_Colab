#include <iostream>
using namespace std;
class Point {
    int x, y;
  public:
      Point(int xx, int yy) {
        cout << "Diem duoc tao \n";
        x = xx; y = yy;
    }
    void Print() {
      cout << "Diem (" << x << ", " << y <<")\n";
    }
};

int main() {
  Point a(2, 5);
  a.Print();
  Point b(3, 5);
  b.Print();
  system("Pause");
}
