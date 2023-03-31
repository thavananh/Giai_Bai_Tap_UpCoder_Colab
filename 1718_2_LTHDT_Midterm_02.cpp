// #include <iostream>
// #include <string>

// using namespace std;

// class Employee
// {
//     int id;
//     string firstName, lastName;
//     double salary;
//     public:
//         Employee(int, string, string, double);
//         ~Employee();
//         int getID();
//         string getFirstName();
//         string getLastName();
//         string getName();
//         double getSalary();
//         void setSalary(double salary);
//         double getAnnualSalary();
//         double raiseSalary(double percent);
//         string toString();
//         friend istream &operator >> (istream &is, Employee &e);
//         friend ostream &operator << (ostream &os, Employee e);
//         friend Employee operator + (Employee)
// };

// Employee::Employee(int id = 0, string firstName = "", string lastName = "", double salary = 0) {
//     this->id = id;
//     this->firstName = firstName;
//     this->lastName = lastName;
//     this->salary = salary;
// }

// Employee::~Employee() {

// }

// istream &operator >> (istream &is, Employee &e) {
//     is >> e.id >> e.firstName >> e.lastName >> e.salary;
//     return is;
// }

// ostream &operator << (ostream &os, Employee e) {
//     os << e.id << '\n';
//     os << e.firstName << '\n';
//     os << e.lastName << '\n';
//     os << e.salary;
//     return os;
// }

// int Employee::getID() {
//     return this->id;
// }

// string Employee::getFirstName() {
//     return this->firstName;
// }

// string Employee::getLastName() {
//     return this->lastName;
// }

// string Employee::getName() {
//     return firstName + " " + lastName;
// }

// double Employee::getSalary() {
//     return salary;
// }

// double Employee::getAnnualSalary() {
//     return salary*12;
// }

// double Employee::raiseSalary(double percent) {
//     return salary*percent;
// }

// int main() {

// }

#include <iostream>
using namespace std;

struct PhanSo
{
    int n;
    int tu, mau;
    public:
        PhanSo timMin(PhanSo ps1, PhanSo ps2);
};

istream &operator >> (istream &is, PhanSo &ps);
ostream &operator << (ostream &os, PhanSo p);

int main() {

}

istream &operator >> (istream &is, PhanSo &ps) {
    is >> ps.tu >> ps.mau;
    return is;
}

ostream &operator << (ostream &os, PhanSo ps) {
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
    os << ps.tu << "/" << ps.mau;
    return os;
}



bool operator < (PhanSo ps1, PhanSo ps2) {
    return (float)ps1.tu / ps1.mau < (float)ps2.tu / ps2.mau;
    
}