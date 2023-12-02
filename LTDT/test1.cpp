#include <iostream>
#include <fstream>
#include <vector>
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

bool operator < (CANH c1, CANH c2)
{
    return c1.trongso < c2.trongso;
}

bool operator > (CANH c1, CANH c2)
{
    return c1.trongso > c2.trongso;
}

void readGraph(GRAPH &g)
{
	ifstream FILE_MATRAN;
	FILE_MATRAN.open("DOTHI2.txt", ios::in);
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

vector<CANH>a;//Mảng lưu các cạnh trong thuật toán Prim
vector<CANH>b;

void timCacCanh(GRAPH g)
{
    int nT = 0;
    CANH tmp;
    for (size_t i = 0; i < g.sodinh; i++)
    {
        g.visited[i] = 0;
    }
    for (size_t i = 0; i < g.sodinh; i++)
    {
        g.visited[i] = 1;
        for (size_t j = 0; j < g.sodinh; j++)
        {
            if (g.a[i][j] != 0 && g.visited[j] == 0)
            {
                tmp.u = i;
                tmp.v = j;
                tmp.trongso = g.a[i][j];
                a.push_back(tmp);
            }
        }
    }
}

void sortLinhTinh()
{
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a.size() - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                CANH tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i].u << " " << a[i].v << " " << a[i].trongso << endl;
    }
}

bool timChuTrinh(GRAPH g)
{
    
}

void thuatToanKruskal(GRAPH g)
{
    for (size_t i = 0; i < g.sodinh; i++)
    {
        g.visited[i] = 0;
    }
}

int main()
{
	GRAPH g;
	readGraph(g);
	ofstream FILE_OUTPUT;
	FILE_OUTPUT.open("output3.txt", ios::out);
	timCacCanh(g);
    sortLinhTinh();

    system("pause");
}