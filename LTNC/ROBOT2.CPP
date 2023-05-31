 #include <iostream>
 #include <string>
 #include <algorithm>
 #include <cmath>

using namespace std;

int n;
int a[100][100];
int dx[] = {0, 1};
int dy[] = {1, 0};
string so_o_di, so_o_di_max;

void _thu(int i, int j){
    if (i == n && j == n){
        if (so_o_di <= so_o_di_max) so_o_di_max = so_o_di;
    }
    else{
        for (int k = 0; k < 2; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] != -1){
                so_o_di += (char)(a[x][y] + '0');
                _thu(x, y);
                so_o_di.erase(so_o_di.size() - 1, 1);
            }
        }
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            so_o_di_max += "1";
        }
    }
    so_o_di += (char)(a[1][1] + '0');
    _thu(1, 1);
    // đảo ngược chuỗi ddi_max để tính số thập phân:
    
    // string s = "";
    // for (int i = 0; i < ddi_max.size(); i++){
    //     s = ddi_max[i] + s;
    // }
    // cout << s << endl;
    
    reverse(so_o_di_max.begin(), so_o_di_max.end());
    int ket_qua = 0;
    for (int i = 0; i < so_o_di_max.size(); i++){
        if (so_o_di_max[i] == '1'){
            ket_qua += pow(2, i);
        }
    }
    cout << ket_qua << endl;
    return 0;
}