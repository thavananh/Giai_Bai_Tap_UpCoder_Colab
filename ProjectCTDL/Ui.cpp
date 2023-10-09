#include "UI.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include "tools.h"
#include <chrono>
#include <thread>
using namespace std;

UI::UI()
{}
UI::UI(const UI& ui)
{}
UI::~UI()
{}
void UI::renderWelcomeScreen()
{
    getDefaultAttribute();
    srand(time(0));
    ifstream ifAsciiTextArt;
    ifAsciiTextArt.open("ascii-text-art.txt", ios::in);
    if (ifAsciiTextArt.is_open())
    {
        textColor(14);
        string strFileLine;
        while (getline(ifAsciiTextArt, strFileLine))
        {
            centerText(strFileLine);
            cout << strFileLine << endl;
        }   
    }
    string strWelcome = "Welcome back. We're very glad to see you again !!!";
    centerText(strWelcome);
    textColor(getRandNum());
    for (size_t i = 0; i < strWelcome.length(); i++)
    {
        if (strWelcome[i] == ' ')
        {
            textColor(getRandNum());
        }
        cout << strWelcome[i];
    }
    resetColor();
}
void UI::renderGoodByeScreen()
{
    getDefaultAttribute();
    ifstream ifAsciiTextArt;
    ifAsciiTextArt.open("ascii-text-art_goodbye.txt", ios::in);
    centerHeightText();
    if (ifAsciiTextArt.is_open())
    {
        string strFileLine;
        textColor(14);
        while (getline(ifAsciiTextArt, strFileLine))
        {
            centerText(strFileLine);
            cout << strFileLine << endl;
        }
        ifAsciiTextArt.close();
    }
    cout << flush;
    this_thread::sleep_for(chrono::milliseconds(1500));
    system("cls");
    centerHeightText();
    ifAsciiTextArt.open("ascii-text-art_thanksfor.txt", ios::in);
    if (ifAsciiTextArt.is_open())
    {
        string strFileLine;
        textColor(14);
        while (getline(ifAsciiTextArt, strFileLine))
        {
            centerText(strFileLine);
            cout << strFileLine << endl;
        }
        ifAsciiTextArt.close();
    }
    cout << flush;
    this_thread::sleep_for(chrono::milliseconds(1500));
    system("cls");
    ifAsciiTextArt.open("ascii-text-art_usingourservices.txt", ios::in);
    centerHeightText();
    if (ifAsciiTextArt.is_open())
    {
        string strFileLine;
        textColor(14);
        while (getline(ifAsciiTextArt, strFileLine))
        {
            centerText(strFileLine);
            cout << strFileLine << endl;
        }
        ifAsciiTextArt.close();
    }
    this_thread::sleep_for(chrono::milliseconds(1500));
}

void UI::renderLoginScreen()
{
    getDefaultAttribute();
    ifstream ifLoginUI;
    ifLoginUI.open("login.txt", ios::in);
    centerHeightText();
    if (ifLoginUI.is_open())
    {
        string strFileLine;
        while (getline(ifLoginUI, strFileLine))
        {
            centerText(strFileLine);
            cout << strFileLine << endl;
            stringstream ss(strFileLine);
            string tmp;
            ss >> tmp;
            if (tmp == "ID:")
            {
                this_thread::sleep_for(chrono::milliseconds(1500));
            }
            else
            {
                centerText(strFileLine);
                cout << strFileLine << endl;
            }
            
        }
    }
}