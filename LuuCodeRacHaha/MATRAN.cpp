#include <iostream>
#include <type_traits>
using namespace std;
int main() {
  int a[100][100];
  int n, m; cin >> n >> m;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int x, y; cin >> x >> y;
  cout << endl << endl;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if (i == x-1) {
        swap(a[j][i], a[j][y-1]); 
        continue;
      }
    }
  }
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      cout << a[i][j] << " ";
    }
  }
  system("Pause");
}
