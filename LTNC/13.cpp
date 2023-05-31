#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)

int n;
vector<vector<int>> grid;
void _thu(int row, int col, int curPath, int &minPath) {
    if (row >= n || col >= n) return;
    curPath = curPath * 2 + grid[row][col];
    if (row == n - 1 && col == n - 1) {
        // Kiểm tra xem đường đi mới tạo thành số nhị phân nhỏ hơn giá trị nhỏ nhất tìm được hiện tại hay không
        if (curPath < minPath) {
            minPath = curPath;
        }
        return;
    }
    if (grid[row+1][col] != -1) _thu(row+1, col, curPath, minPath);
    if (grid[row][col+1] != -1) _thu(row, col+1, curPath, minPath);
}

int main() {
    cin >> n;
    grid.resize(n, vector<int>(n));
    FOR(i, 0, n-1) {
        FOR(j, 0, n-1) {
            cin >> grid[i][j];
        }
    }
    int minPath = pow(2, n*n);
    _thu(0, 0, 0, minPath);
    if (minPath >= pow(2, n*n)) {
        cout << -1 << endl;
    } else {
        cout << minPath << endl;
    }
    return 0;
}
