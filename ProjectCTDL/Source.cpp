#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
using namespace std;

string getTime()
{
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d %H:%M:%S");
    string timeString = ss.str();
    return timeString;
}

// class Person
// {
// private:
//     string _strID, _strMaPin;
// public:
//     Person(string strID = "", string strMaPin = "")
//     {
//         this->_strID = strID;
//         this->_strMaPin = strMaPin;
//     }
//     string getID()
//     {
//         return this->_strID;
//     }
//     string getMaPin()
//     {
//         return this->_strMaPin;
//     }
//     void setAll(string strID, string strMaPin)
//     {
//         this->_strID = strID;
//         this->_strMaPin = strMaPin;
//     }
//     virtual void dangNhap() = 0;
// };


class User : public Person
{
private:
    string _firstName, _lastName;
    double _balance;
    string _moneyType;
    string _accountStatus;
public:
    User(string strID = "", string strMaPin = "", string firstName = "No", string lastName = "Name", double balance = 0.0, string moneyType = "VND", string accountStatus = "true") : Person(strID, strMaPin)
    {
        this->_firstName = firstName;
        this->_lastName = lastName;
        this->_balance = balance;
        this->_moneyType = moneyType;
        this->_accountStatus = accountStatus;
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

    string getAccountStatus()
    {
        return this->_accountStatus;
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
                cout << "Error while opening file";
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
    void xemThongTinTaiKhoan() {
        ifstream iFile;
        string strArray[4];
        string strID;
        strID = getID() + ".txt";
        iFile.open(strID);
        for (int i = 0; i < 4; i++)
            getline(iFile, strArray[i]);
        cout << "Thong tin tai khoan cua ban: " << endl;
        cout << "ID: " << strArray[0] << endl;
        cout << "Ten tai khoan: " << strArray[1] << endl;
        cout << "So du tai khoan: " << strArray[2] << endl;
        cout << "Loai tien te: " << strArray[3] << endl;
    }
    void rutTien() {
        long iTienRut;
    Again1:
        cout << "Neu ban muon thoat bam phim 0" << endl;
        cout << "So tien can rut cua ban la: ";
        cin >> iTienRut;
        cin.ignore();
        if (iTienRut == 0)
            return;
        if (iTienRut < 50000) {
            system("cls");
            cout << "Ban can phai rut tu 50000 tro len. Vui long nhap lai: " << endl;
            goto Again1;
        }
        long iSoDu;
        ifstream iFile;
        string strID;
        string strArray[4];
        strID = getID() + ".txt";
        iFile.open(strID);
        for (int i = 0; i < 4; i++) {
            if (i == 2) {
                iFile >> iSoDu;
                iFile.ignore();
            }
            else
                getline(iFile, strArray[i]);
        }
        if (iTienRut > iSoDu) {
            system("cls");
            cout << "So du cua ban khong du. Vui long nhap lai: " << endl;
            goto Again1;
        }
        cout << "Ban co chac muon rut khong (co/khong): ";
        string iSelection;
        getline(cin, iSelection);
        if (iSelection == "co")
            iSoDu -= iTienRut;
        else if (iSelection == "khong")
            return;
        cout << "Ban da rut tien thanh cong: " << endl;
        ofstream oFile;
        oFile.open(strID);
        for (int i = 0; i < 4; i++)
            if (i == 2)
                oFile << iSoDu << endl;
            else
                oFile << strArray[i] << endl;
        ofstream oFile1;
        oFile1.open("LichSu" + getID() + ".txt", ios::app);
        time_t now = time(0);
        char* ch = ctime(&now);
        oFile1 << now << " Ban da rut " << iTienRut << "VND" << endl;
    }
    void chuyenTien() {
        string strTaiKhoan;
        long iTienChuyen;
    Again1:
        cout << "Tai khoan nhan tien: ";
        cin >> strTaiKhoan;
        cout << "So tien se chuyen: ";
        cin >> iTienChuyen;
        cin.ignore();
        if (iTienChuyen < 50000) {
            system("cls");
            cout << "Ban can phai chuyen tu 50000 tro len. Vui long nhap lai: " << endl;
            goto Again1;
        }
        long iSoDu;
        ifstream iFile;
        string strID;
        string strArray[4];
        strID = getID() + ".txt";
        iFile.open(strID);
        for (int i = 0; i < 4; i++) {
            if (i == 2) {
                iFile >> iSoDu;
                iFile.ignore();
            }
            else
                getline(iFile, strArray[i]);
        }
        if (iTienChuyen > iSoDu) {
            system("cls");
            cout << "So du cua ban khong du. Vui long nhap lai: " << endl;
            goto Again1;
        }
        cout << "Ban co chac muon chuyen khong (co/khong): ";
        string iSelection;
        getline(cin, iSelection);
        if (iSelection == "co")
            iSoDu -= iTienChuyen;
        else if (iSelection == "khong")
            return;
        cout << "Ban da chuyen tien thanh cong: " << endl;
        ofstream oFile;
        oFile.open(strID);
        for (int i = 0; i < 4; i++)
            if (i == 2)
                oFile << iSoDu << endl;
            else
                oFile << strArray[i] << endl;
        ofstream oFile1;
        oFile1.open("LichSu" + getID() + ".txt", ios::app);
        time_t now = time(0);
        char* ch = ctime(&now);
        oFile1 << now << " Ban da chuyen " << iTienChuyen << "VND cho so tai khoan " << strTaiKhoan << endl;
        ifstream iFile1;
        iFile1.open(strTaiKhoan + ".txt");
        string strArray1[4];
        long iSoDu1;
        for (int i = 0; i < 4; i++) {
            if (i == 2) {
                iFile1 >> iSoDu1;
                iFile1.ignore();
            }
            else
                getline(iFile1, strArray1[i]);
        }
        iSoDu1 += iTienChuyen;
        ofstream oFile2;
        oFile2.open(strTaiKhoan + ".txt");
        for (int i = 0; i < 4; i++)
            if (i == 2)
                oFile2 << iSoDu1 << endl;
            else
                oFile2 << strArray1[i] << endl;
        ofstream oFile3;
        oFile3.open("LichSu" + strTaiKhoan + ".txt", ios::app);
        oFile3 << now << " Ban duoc nhan " << iTienChuyen << "VND tu tai khoan " << getID() << endl;
    }
    void xemNoiDungGiaoDich() {
        ifstream iFile;
        iFile.open(getID() + ".txt");
        string strLay;
        while (getline(iFile, strLay)) {
            cout << strLay << endl;
        }
    }
    void doiMaPin() {
        string strPinCu, strPinMoi, strKiemTraPinMoi;
        vector<string> ID;
        vector<string> Pin;
        ifstream iFile;
        iFile.open("TheTu.txt");
        string strLay;
        while (getline(iFile, strLay)) {
            stringstream ss(strLay);
            string strID, strPin;
            ss >> strID >> strPin;
            ID.push_back(strID);
            Pin.push_back(strPin);
        }
        string strKiemTraPinCu;
        for (int i = 0; i < ID.size(); i++)
            if (ID[i] == getID())
                strKiemTraPinCu = Pin[i];
    Again:
        cout << "Nhap Pin cu: ";
        getline(cin, strPinCu);
        cout << "Nhap Pin Moi: ";
        getline(cin, strPinMoi);
        cout << "Nhap Pin Moi 1 lan nua: ";
        getline(cin, strKiemTraPinMoi);
        if (strPinCu != strKiemTraPinCu)
        {
            system("cls");
            cout << "Ban da nhap sai Pin cu. Vui long nhap lai: " << endl;
            goto Again;
        }
        else if (strPinMoi != strKiemTraPinMoi)
        {
            system("cls");
            cout << "Ban da nhap sai Pin Moi. Vui long nhap lai: " << endl;
            goto Again;
        }
        cout << "Ban da doi ma pin thanh cong" << endl;
        for (int i = 0; i < Pin.size(); i++)
            if (ID[i] == getID())
                Pin[i] = strPinMoi;
        ofstream oFile;
        oFile.open("TheTu.txt");
        for (int i = 0; i < ID.size(); i++)
            oFile << ID[i] << " " << Pin[i] << endl;
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
                cout << "error while opening file";
            }
            if (thanhCong)
            {
                cout << "login successfully";
            }
            else
            {
                cout << "login failed";
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
                cout << "Error, found duplicate";
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
            FileID << usr.getAccountStatus() << '\n';
            FileID.close();
        }
        ofstream historyFile;
        historyFile.open("LichSu" + usr.getID() + ".txt", ios::out);
        if (historyFile.is_open())
        {

            historyFile << "init account " << getTime() << '\n';
            historyFile.close();
        }
    }

    void danhSachTaiKhoan()
    {
        ifstream File;
        File.open("TheTu.txt");
        string strUser;
        cout << "List of accounts: " << endl;
        while (getline(File, strUser)) {
            cout << strUser << endl;
        }
    }
    void xoaThe()
    {
        string strID;
        cout << "Input an account to remove: ";
        cin >> strID;
        if (remove((strID + ".txt").c_str()) == 0)
        {
            cout << "remove successfully";
        }
        else
        {
            cout << "Error while removing account";
            return;
        }
        ifstream readAccountFile;
        readAccountFile.open("TheTu.txt", ios::in);
        vector<string>v;
        if (readAccountFile.is_open())
        {
            string line;
            while (getline(readAccountFile, line))
            {
                stringstream ss(line);
                string tmp;
                ss >> tmp;
                if (tmp == strID)
                {
                    continue;
                }
                else
                {
                    v.push_back(line);
                }

            }
        }
        ofstream writeAccountFile;
        writeAccountFile.open("TheTu.txt", ios::out);
        if (writeAccountFile.is_open())
        {
            for (auto it : v)
            {
                writeAccountFile << it << '\n';
            }
            writeAccountFile.close();
        }
        else
        {
            cout << "Error while opening file";
        }
        ofstream writeAccountHistoryFile;
        writeAccountHistoryFile.open("LichSu" + strID + ".txt", ios::app);
        if (writeAccountHistoryFile.is_open())
        {
            writeAccountHistoryFile << "Account removed successfully " << getTime() << '\n';
        }
    }
    void unlockAccount()
    {
        ifstream File;
        string strID;
        cout << "Please input account to unlock: ";
        cin >> strID;
        vector<string>v;
        File.open(strID + ".txt", ios::in);
        if (File.is_open())
        {
            string line;
            while (getline(File, line))
            {
                v.push_back(line);
                if (line == "false")
                {
                    v.push_back("true");
                }
            }
            File.close();
        }
        ofstream writeAccountFile;
        writeAccountFile.open(strID + ".txt", ios::out);
        for (auto it : v)
        {
            writeAccountFile << it << '\n';
        }
    }
};



int main()
{
    Admin ad;
    //ad.layThongTin();
    //ad.dangNhap();
    //ad.themTaiKhoan();
    //ad.xoaThe();
}
