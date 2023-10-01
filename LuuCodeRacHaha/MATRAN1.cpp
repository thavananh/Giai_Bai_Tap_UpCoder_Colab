#include <iostream>
using namespace std;

int main() {
  int a[100][100];
  int n; cin >> n;
  int sum = 0;
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
    
  }
  for (size_t i = 0; i < n; i++) {
    sum = sum + a[i][i];
  }
  for (size_t i = 0; i < n; i++) {
    
    sum = sum + a[i][n-i - 1];
  }
  cout << sum;
  system("Pause");
}
