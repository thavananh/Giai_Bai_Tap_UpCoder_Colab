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


class User : public Person
{
private:
    string _firstName, _lastName;
    double _balance;
    string _moneyType;
public:
    User(string strID = "", string strMaPin = "", string firstName = "No", string lastName = "Name", double balance = 0.0, string moneyType = "VND") : Person(strID, strMaPin)
    {
        this->_firstName = firstName;
        this->_lastName = lastName;
        this->_balance = balance;
        this->_moneyType = moneyType;
    }
    void layThongTin()
    {
        string strID, strMaPin;
        cin >> strID >> strMaPin;
        User::setAll(strID, strMaPin);
    }

    string getFirstName()
    {
        return this->_firstName;
    }

    string getLastName()
    {
        return this->_lastName;
    }

    double getBalance()
    {
        return this->_balance;
    }

    string getMoneyType()
    {
        return this->_moneyType;
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

class Admin : public Person
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

    bool kiemTraTrungLapTaiKhoan(string strID)
    {
        ifstream File;
        File.open("TheTu.txt", ios::in);
        if (File.is_open())
        {
            string line;
            string id;
            while (getline(File, line))
            {
                stringstream ss(line);
                ss >> id;
                if (strID == id)
                {
                    return true;
                }      
            }
            File.close();
        }
        return false;
    }

    void themTaiKhoan() {
        ofstream File;
        File.open("TheTu.txt", ios::app);
        User usr;
        if (File.is_open())
        {    
            string strID;
            cout << "Input account to add: ";
            cin >> strID;
            if (kiemTraTrungLapTaiKhoan(strID))
            {
                return;
            }
            usr.setAll(strID, "123456");
            cin.ignore();
            File << usr.getID() << " " << usr.getMaPin() << endl;
            File.close();
        }
        else
        {
            cout << "Something wrong while opening file";
        }
        ofstream FileID;
        FileID.open(usr.getID() + ".txt", ios::out);
        if (FileID.is_open())
        {
            FileID << usr.getID() << '\n';
            FileID << usr.getFirstName() + " " + usr.getLastName() << '\n';
            FileID << usr.getBalance() << '\n';
            FileID << usr.getMoneyType() << '\n';
        }
                
        

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



int main()
{
    Admin ad;
    //ad.layThongTin();
   // ad.dangNhap();
    ad.themTaiKhoan();
}