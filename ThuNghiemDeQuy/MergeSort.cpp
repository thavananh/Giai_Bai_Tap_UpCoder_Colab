#include <iostream>
using namespace std;
void merge(int a[], int start, int mid, int end);
void MergeSort(int a[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end)/2;
        MergeSort(a, start, mid);
        MergeSort(a, mid + 1, end);
        merge(a, start, mid , end);
    }
    
}

void merge(int a[], int start, int mid, int end)
{
    int temp[10000];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    
    while (j <= end)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = start; i <= end; i++)
    {
        a[i] = temp[i-start];
    }
}

int main()
{
    int n;
    cin >> n;
    int a[10000];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    MergeSort(a, 0, n-1);
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << '\n';
    }
    system("Pause");
}