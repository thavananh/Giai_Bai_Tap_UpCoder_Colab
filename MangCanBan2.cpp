#include <iostream>
#include <stdio.h>
#define ArraySize 1000
using namespace std;

int main() {
	float a[ArraySize];
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	float sum = 0;
	float min = a[0];
	float max = a[0];
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	sum = (max + min) / 2;
	printf("%.2f", sum);
}