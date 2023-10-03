#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

class Person
{
private:
    string _strID, _strMaPin;
public:
    Person(string strID = "", string strMaPin = "")
    {
        this->_strID = strID;
        this->_strMaPin = strMaPin;
    }
    string getID()
    {
        return this->_strID;
    }
    string getMaPin()
    {
        return this->_strMaPin;
    }
    void setAll(string strID, string strMaPin)
    {
        this->_strID = strID;
        this->_strMaPin = strMaPin;
    }
    virtual void dangNhap() = 0;
};

class Admin : Person
{
public:
    Admin(string strID = "", string strMaPin = "") : Person(strID, strMaPin)
    {

    }
    void layThongTin()
    {
        string strID, strMaPin;
        cin >> strID >> strMaPin;
        Admin::setAll(strID, strMaPin);
    }
    int kiemTraSoLuongAdmin()
    {
        int iSoLuongAdmin = 0;
        ifstream File;
        File.open("Admin.txt", ios::in);
        if (File.is_open())
        {
            string line;
            while (getline(File, line))
            {
                iSoLuongAdmin++;
            }

        }
        return iSoLuongAdmin;
    }
    void dangNhap() override
    {
        if (kiemTraSoLuongAdmin() < 3)
        {
            cout << "khong du so luong admin";
        }
        else
        {
            ifstream File;
            File.open("Admin.txt", ios::in);
            bool thanhCong = false;
            if (File.is_open())
            {
                string line;
                while (getline(File, line))
                {
                    stringstream ss(line);
                    string ID;
                    string Pin;
                    ss >> ID;
                    ss >> Pin;
                    if (ID == Admin::getID() && Pin == Admin::getMaPin())
                    {
                        thanhCong = true;
                    }
                }
            }
            else
            {
                cout << "NGU";
            }
            if (thanhCong)
            {
                cout << "dang nhap thanh cong";
            }
            else
            {
                cout << "dang nhap that bai";
            }
        }
    }
    void themTaiKhoan() {
        ofstream File;
        File.open("TheTu.txt", ios::app);
        string strID;
        string strPin;
        cin >> strID;
        cin.ignore();
        cin >> strPin;
        File << strID << " " << strPin << endl;
    }
    void danhSachTaiKhoan() {
        ifstream File;
        File.open("TheTu.txt");
        string strUser;
        cout << "Danh sach tai khoan: " << endl;
        while (getline(File, strUser)) {
            cout << strUser << endl;
        }
    }
};

class User : Person
{
    User(string strID = "", string strMaPin = 0) : Person(strID, strMaPin)
    {

    }
    void layThongTin()
    {
        string strID, strMaPin;
        cin >> strID >> strMaPin;
        User::setAll(strID, strMaPin);
    }

    int kiemTraSoLuongUser()
    {
        int iSoLuongUser = 0;
        ifstream File;
        File.open("Admin.txt", ios::in);
        if (File.is_open())
        {
            string line;
            while (getline(File, line))
            {
                iSoLuongUser++;
            }

        }
        return iSoLuongUser;
    }

    void dangNhap() override
    {

        if (kiemTraSoLuongUser() < 10)
        {
            cout << "So luong the tu khong du" << '\n';
        }
        else
        {
            ifstream File;
            File.open("TheTu.txt", ios::in);
            bool thanhCong = false;
            if (File.is_open())
            {
                string line;
                while (getline(File, line))
                {
                    stringstream ss(line);
                    string ID;
                    string Pin;
                    ss >> ID;
                    ss >> Pin;
                    if (ID == User::getID() && ID.size() >= 14 && Pin == User::getMaPin() && Pin.size() == 6)
                    {
                        thanhCong = true;
                    }
                }
            }
            else
            {
                cout << "NGU";
            }
            if (thanhCong)
            {
                cout << "dang nhap thanh cong";
            }
            else
            {
                cout << "dang nhap that bai";
            }
        }
    }
};

int main()
{
    Admin ad;
    //ad.layThongTin();
   // ad.dangNhap();
    ad.themTaiKhoan();
    ad.danhSachTaiKhoan();
}