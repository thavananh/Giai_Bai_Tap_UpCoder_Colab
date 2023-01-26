#include <iostream>
using namespace std;

int length(char input[]) {
    int count = 0;
    for (size_t i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main() {
    char input[100];
    cin.getline(input, 100);
    int start = 0;
    int end = length(input) - 1;
    while (start <= end)
    {
        swap(input[start], input[end]);
        start++;
        end--;
    }
    
    cout << input;
    system("Pause");    
}