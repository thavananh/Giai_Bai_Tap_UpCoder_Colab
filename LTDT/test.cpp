#include <iostream>
#include <fstream> // thư viện đọc, ghi  file
using namespace std;

//don`g 1 so luong cay khung
//do

struct GRAPH
{
    int n;
    int arr[100][100];
    int visited[100];       // lưu số đỉnh, đỉnh chưa đi qua = 0, đi qua rồi = 1
};

void readGraph(GRAPH &g)
{
    ifstream FILE_DOTHI;
    FILE_DOTHI.open("DOTHI1.txt", ios::in); // ios::in = đọc file
    if (FILE_DOTHI.is_open()) // kiểm tra file có mở được không
    {
        FILE_DOTHI >> g.n;
        for (size_t i = 0; i < g.n; i++)
        {
            for (size_t j = 0; j < g.n; j++)
            {
                FILE_DOTHI >> g.arr[i][j];
            }
        }
        FILE_DOTHI.close(); // đóng file lại
    }
}

struct CanhNhoNhat
{
    int u, v;               // u: lưu đỉnh trước đó             v: lưu đỉnh hiện tại
    int trongso;            // v: trọng số của đồ thị, ảnh tao gửi qua mess
};

CanhNhoNhat T[100]; // dùng để lưu cạnh của cây đồ thị

void thuatToanPrim(GRAPH g)
{
    int soCanhCuaCayMaTran = 0; // có n-1 cạnh

    for (size_t i = 0; i < g.n; i++)
    {
        g.visited[i] = 0;   // gán cho tất cả các định về giá trị 0
                            // 0 = là chưa đi qua, 1 là đi qua rồi         ọke
    }

    while (soCanhCuaCayMaTran < g.n - 1) // kiểm tra xem có thoả định lý của cây đồ thị hay chưa
    {
        CanhNhoNhat tmp; // dùng để lưu cạnh
        for (size_t i = 0; i < g.n; i++) // dùng để duyệt đỉnh
        {
            int min = 9999;           // dùng để xác định cạnh có trọng số nhỏ nhất
            if (g.visited[i] == 0)
            {
                for (size_t j = 0; j < g.n; j++) // dùng để duyệt đỉnh có kết nối với đỉnh mình vừa đi qua
                {
                    if (g.arr[i][j] != 0 && min > g.arr[i][j] && g.visited[j] == 0)      // khác 0 để xác định có kết nối không, min dùng để check xem nó có nhỏ nhất không
                    {
                        min = g.arr[i][j];          
                        tmp.u = i + 1;             
                        tmp.v = j + 1;
                        tmp.trongso = g.arr[i][j];                  
                    }
                }
            }
            T[soCanhCuaCayMaTran] = tmp;
            soCanhCuaCayMaTran++;
            g.visited[tmp.u - 1] = 1;       
        }
    // đánh dấu đỉnh đã đi qua rồi // cái này hơi đặc biệt tí, nó khác với dfs
    }
    
}

int main()
{
    GRAPH g;
    readGraph(g);
    thuatToanPrim(g);
    ofstream OUTPUT_CAYMATRAN;
    OUTPUT_CAYMATRAN.open("output1.txt", ios::out);      // tạo file có tên là "output.txt", ios::out: ghi file
    if (OUTPUT_CAYMATRAN.is_open())
    {
        OUTPUT_CAYMATRAN << g.n - 1 << endl;
        int sum = 0;
        for (size_t i = 0; i < g.n - 1; i++)        // mình biết số cây ma trận sẽ là n - 1, vì nó là định lý
        {
            OUTPUT_CAYMATRAN << T[i].u << " " << T[i].v << " " << T[i].trongso << endl;
            sum = sum + T[i].trongso;
        }       
        OUTPUT_CAYMATRAN << sum;
    }
}
