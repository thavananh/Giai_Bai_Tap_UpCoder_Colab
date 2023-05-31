#include<iostream>
#include<string>
using namespace std;

struct Date {
    string day;
    string month;
    string year;

    void getDate(string strDate) {
        if (strDate.length() > 8) {
            day = (strDate.substr(0, 2));
            month = (strDate.substr(3, 2));
            year = (strDate.substr(6, 4));
        }
        else {
            day = (strDate.substr(0, 2));
            month = (strDate.substr(2, 2));
            year = (strDate.substr(4, 4));
        }
    }

    void printDate() {
        cout << day << "/" << month << "/" << year;
    }
};

struct Player {
    string ID;
    string name;
    Date birthday;

    void getPlayerInfor() {
        getline(cin, ID);
        getline(cin, name);
        string strDate = "";
        getline(cin, strDate);
        birthday.getDate(strDate);
    }

    void printPlayerInfor() {
        cout << ID << endl;
        cout << name << endl;
        birthday.printDate();
    }
};

int main() {
    Player p;
    p.getPlayerInfor();
    p.printPlayerInfor();
    return 0;
}