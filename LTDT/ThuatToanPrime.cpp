#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct GRAPH 
{ 
	int sodinh;//so dinh do thi
	int a[MAX][MAX];//ma tran ke	
	int visited[MAX]; //danh dau dinh i da xet hay chua, 0 la chua xet
};
struct CANH
{
	int u;//Dinh thu nhat
	int v;//Dinh thu hai
	int trongso;
};

void readGraph(GRAPH &g)
{
	ifstream FILE_MATRAN;
	FILE_MATRAN.open("DOTHI.txt", ios::in);
	if (FILE_MATRAN.is_open())
	{
		FILE_MATRAN >> g.sodinh;
		for (size_t i = 0; i < g.sodinh; i++)
		{
			for (size_t j = 0; j < g.sodinh; j++)
			{
				FILE_MATRAN >> g.a[i][j];
			}
			
		}
	}
}

CANH T[MAX];//Mảng lưu các cạnh trong thuật toán Prim

void Prim(GRAPH g)
{
	//B1: Gán số cạnh của cây khung ban đầu là 0
	int nT = 0;
	//B2: Khởi tạo nhãn các đỉnh là chưa duyệt (0)
	for(int i = 0; i < g.sodinh; i++)
		g.visited[i] = 0;

	//B3: Đánh dấu đỉnh 0 là đã duyệt
	g.visited[0] = 1;

	while(nT < g.sodinh - 1)//nếu đủ n -1 cạnh thì dừng (Tại sao, dựa vào đâu??)	
	{
		CANH canhnhonhat;//dùng để lưu trữ cạnh nhỏ nhất từ một đỉnh đã xét tới đỉnh chưa xét
		int min = -1;	//Tại sao lấy -1????
		for(int i = 0; i < g.sodinh; i++)
			if(g.visited[i] == 0) //nếu là đỉnh chưa duyệt. Điều kiện đúng khi j thuộc tập Y hay V\Y
			{
				for(int j = 0; j < g.sodinh; j++)
					if(g.visited[j] == 1 && (g.a[i][j] != 0))
					{
						if(min == -1 || g.a[i][j] < min)
						{
							min = g.a[i][j];
							canhnhonhat.u = i;
							canhnhonhat.v = j;
							canhnhonhat.trongso = g.a[i][j];
						}
					}
			}

		//Thêm cạnh nhỏ nhất vào tập T
		T[nT] = canhnhonhat;
		nT++;//tăng số cạnh lên 1
		g.visited[canhnhonhat.u] = 1;//Tại sao????
		
	}

	
}


int main()
{
	GRAPH g;
	readGraph(g);
	ofstream FILE_OUTPUT;
	FILE_OUTPUT.open("output.txt", ios::out);
	Prim(g);
	if (FILE_OUTPUT.is_open())
	{
		//Tổng trọng số của cây khung
		int sum = 0;
		FILE_OUTPUT<<"Cay khung nho nhat cua do thi la: "<<endl;
		for(int i = 0; i < g.sodinh; i++)
		{
			FILE_OUTPUT<<"("<<T[i].u<<", "<<T[i].v<<") ";
			sum += T[i].trongso;
		}
		FILE_OUTPUT<<endl;
		FILE_OUTPUT<<"Tong gia tri cua cay la: "<<sum<<endl;
	}
	
	
}