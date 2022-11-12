#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<long int>a;
	long int x;
	while (cin >> x)
	{
		a.push_back(x);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	long int max = a[0];
	long int oldmax = 0;
	for (long int i = 0; i < a.size(); i++)
	{
		if (a[i] > max)
		{
			oldmax = max;
			max = a[i];
		}
		if (a[i] > oldmax && a[i] < max)
		{
			oldmax = a[i];
		}
	}
	cout << oldmax << " " << max;
}