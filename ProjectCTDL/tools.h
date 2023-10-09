#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
WORD defaultWordAttributes;
int width;
int height;

int getRandNum()
{
    srand(time(0));
    return rand() % 5 + 10;
}


void centerText(string text) 
{
    // Calculate the number of spaces to pad before the text
    int padding = (width - text.length()) / 2;

    // Print the padding and then the text
    for (int i = 0; i < padding; ++i)
        cout << " ";
}

void centerHeightText()
{
    for (size_t i = 0; i < height/2 - 4; i++)
    {
        cout << '\n';
    }
}

void lineBreak(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
    }
}

void getDefaultAttribute()
{
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    defaultWordAttributes = csbi.wAttributes;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void resetColor()
{
    SetConsoleTextAttribute(hConsole, defaultWordAttributes);
}

void textColor(int n)
{
    SetConsoleTextAttribute(hConsole, n);
}