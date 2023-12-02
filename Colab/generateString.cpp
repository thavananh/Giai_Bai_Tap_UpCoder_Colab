#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream FILE;
    FILE.open("outputForRange.txt", ios::out);
    if (FILE.is_open())
    {
        for (size_t i = 1501; i <= 4694; i+=50)
        {
            FILE << i << ", " << i+50 << endl;
        }
        FILE.close();
    }
    FILE.open("outputPath.txt", ios::out);
    if (FILE.is_open())
    {
        for (size_t i = 1501; i <= 4694; i+=50)
        {
            FILE << "/content/drive/MyDrive/output_colab/NonDepression_"  << i << "_" << i+50 << "test.csv" << endl;
        }
        FILE.close();
    }
}