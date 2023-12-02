#include <iostream>
#include <fstream>
using namespace std;

const int voCuc = -1;

struct GRAPH
{
	int sodinh;//so dinh do thi
	int a[100][100];//ma tran ke	
	int visited[100]; //danh dau dinh i da xet hay chua, 0 la chua xet
};

bool ThuocT[100];
int Length[100];
int lastV[100];

void khoiTao(GRAPH g)
{
	for (size_t i = 0; i < g.sodinh; i++)
	{
		ThuocT[i] = true;
		Length[i] = voCuc;
		lastV[i] = -1;
	}
}

void thuatToanDijkstra(GRAPH g, int x, int y)
{
	Length[x] = 0;
	ThuocT[x] = false;
	lastV[x] = x;
	int v = x;
	while (ThuocT[y] == true)
	{
		for (size_t k = 0; k < g.sodinh; k++)
		{
			if (g.a[v][k] != 0 && ThuocT[k] == true && (Length[k] == voCuc || Length[k] > Length[v] + g.a[v][k]))
			{
				Length[k] = Length[v] + g.a[v][k];
				lastV[k] = v;
			}
		}
		v = -1;
		for (size_t i = 0; i < g.sodinh; i++)
		{
			if (ThuocT[i] == true && Length[i] != voCuc)
			{
				if (v == -1 || Length[v] > Length[i])
				{
					v = i;
				}
			}
		}
		ThuocT[v] = false;
	}
	
}

void Xuat(int x, int y)
{
	int DuongDi[100];
	int v = y;
	int i;
	int id = 0;
	while (v != x)
	{
		DuongDi[id] = v;
		v = lastV[v];
		id++;
	}
	DuongDi[id] = x;
	for (i = id; i > 0; i--)
	{
		cout << DuongDi[i] << "-->";
	}
	cout << DuongDi[i] << endl;
}

void readGraph(GRAPH& g)
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


int main()
{
	GRAPH g;
	readGraph(g);
    khoiTao(g);
	thuatToanDijkstra(g, 0, 6);
	Xuat(0, 6);
	system("pause");
}