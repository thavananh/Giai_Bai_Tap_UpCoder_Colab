#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<vector<char>>& board, int startRow, int startCol) {
    int numRows = board.size();
    int numCols = board[0].size();
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
    
    // Hàng và cột di chuyển theo 4 hướng (trên, dưới, trái, phải)
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    
    queue<vector<int>> q;
    q.push({startRow, startCol, 0}); // Thêm ô bắt đầu vào hàng đợi
    visited[startRow][startCol] = true; // Đánh dấu ô bắt đầu đã được thăm
    
    while (!q.empty()) {
        vector<int> curr = q.front();
        q.pop();
        
        int currRow = curr[0];
        int currCol = curr[1];
        int currDist = curr[2];
        
        if (board[currRow][currCol] == 'B') {
            return currDist; // Đã tìm thấy chuồng bò, trả về số bước đi
        }
        
        // Duyệt qua các ô kề cạnh chưa thăm
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dr[i];
            int newCol = currCol + dc[i];
            
            // Kiểm tra xem ô mới có hợp lệ và chưa được thăm
            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols &&
                (board[newRow][newCol] == '.' || board[newRow][newCol] == 'B') &&
                !visited[newRow][newCol]) {
                
                q.push({newRow, newCol, currDist + 1});
                visited[newRow][newCol] = true; // Đánh dấu ô mới là đã thăm
            }
        }
    }
    
    return -1; // Không tìm thấy đường đi đến chuồng bò
}

int main() {
    int numRows, numCols;
    cin >> numRows >> numCols;
    
    vector<vector<char>> board(numRows, vector<char>(numCols));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> board[i][j];
        }
    }
    
    int shortest = shortestPath(board, numRows - 1, numCols - 1);
    cout << shortest << endl;
    
    return 0;
}