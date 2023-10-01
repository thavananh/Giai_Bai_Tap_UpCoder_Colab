#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long int>a;
	long int x = 0;
	while (cin >> x)
	{
		a.push_back(x);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	long int max = a[0];
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == max)
		{
			cout << i << " ";
		}
	}
}