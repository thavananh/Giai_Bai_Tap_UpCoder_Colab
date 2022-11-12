#include <iostream>
using namespace std;

int main() {
	long int a[10000];
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = n-1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
}