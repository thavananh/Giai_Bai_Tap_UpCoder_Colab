#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct GRAPH 
{ 
	int sodinh;
	int a[MAX][MAX];
	int visited[MAX]; 
};
struct CANH
{
	int u;
	int v;
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

CANH T[MAX];

void Prim(GRAPH g)
{
	
	int nT = 0;
	
	for(int i = 0; i < g.sodinh; i++)
		g.visited[i] = 0;
	g.visited[0] = 1;
	while(nT < g.sodinh - 1)
	{
		CANH canhnhonhat;
		int min = -1;	
		for(int i = 0; i < g.sodinh; i++)
			if(g.visited[i] == 0) 
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
		T[nT] = canhnhonhat;
		nT++;
		g.visited[canhnhonhat.u] = 1;
		
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
	system("pause");
	
}