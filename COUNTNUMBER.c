// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     long long int n;
//     cin >> n;
//     vector<long long int>a;
//     long long int x = 0;
//     long long int i = 1;
//     while (cin >> x)
//     {
//         a.push_back(x);
//         if (i == n)
//         {
//             break;
//         }
//         i++;
//     }
//     long long int count = 1;
//     for (size_t i = 0; i < n; i++)
//     {
//         if (a[i] != -1)
//         {
//             for (size_t j = i+1; j < n; j++)
//             {
//                 if (a[i] == a[j])
//                 {
//                     a[j] = -1;
//                     count++;
//                 }
                
//             }
//             cout << count << " ";
//             count = 1;
//         }
//     }
//     system("Pause");
// }


#include <stdio.h>

int main()
{
    long long int arr[1000000], freq[1000000];
    long long int size, i, j, count;

    /* Input size of array */
    scanf("%lld", &size);

    /* Input elements in array */
    for(i=0; i<size; i++)
    {
        scanf("%lld", &arr[i]);

        /* Initially initialize frequencies to -1 */
        freq[i] = -1;
    }


    for(i=0; i<size; i++)
    {
        count = 1;
        for(j=i+1; j<size; j++)
        {
            /* If duplicate element is found */
            if(arr[i]==arr[j])
            {
                count++;

                /* Make sure not to count frequency of same element again */
                freq[j] = 0;
            }
        }

        /* If frequency of current element is not counted */
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    for(i=0; i<size; i++)
    {
        if(freq[i] != 0)
        {
            printf("%lld ", freq[i]);
        }
    }
}
