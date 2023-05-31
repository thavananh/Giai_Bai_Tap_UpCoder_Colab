#include <iostream>
using namespace std;

int main()
{
	char a = ' ';
	char b = ' ';
	cin >> a >> b;
	for (char i = a; i <= b; i++)
	{
		cout << (char)toupper(i) << " ";
	}

	return 0;
}