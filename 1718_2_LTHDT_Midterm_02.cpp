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
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
    int id;
    string firstName, lastName;
    double salary;
    public:
        Employee(int id = 0, string firstName = "", string lastName = "", double salary = 0);
        Employee(const Employee &e);
        int getID();
        string getFirstName();
        string getLastName();
        string getName();
        double getSalary();
        void setSalary(double salary);
        double getAnnualSalary();
        double raiseSalary(double percent);
        string toString();
        friend istream& operator >> (istream &is, Employee &e);
        friend ostream& operator << (ostream &os, Employee e);
        Employee& operator++();
        Employee operator++(int);
        Employee& operator--();
        Employee operator--(int);
        Employee operator + (double);
        Employee operator - (double);
        bool operator > (Employee e2);
        bool operator < (Employee e2);
        bool operator == (Employee e2);
};

Employee::Employee(int id, string firstName, string lastName, double salary) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->salary = salary;
}

Employee::Employee(const Employee &e) {
    this->id = e.id;
    this->firstName = e.firstName;
    this->lastName = e.lastName;
    this->salary = e.salary;
}

int Employee::getID() {
    return this->id;
}

string Employee::getFirstName() {
    return this->firstName;
}

string Employee::getLastName() {
    return this->lastName;
}

string Employee::getName() {
    return this->firstName + " " + this->lastName;
}

double Employee::getSalary() {
    return this->salary;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

double Employee::getAnnualSalary() {
    return this->salary*12;
}

double Employee::raiseSalary(double percent) {
    return this->salary + this->salary*percent/100;
}

string Employee::toString() {
    return "";
}

istream &operator >> (istream &is, Employee &e) {
    is >> e.id;
    is.ignore();
    getline(is, e.firstName);
    getline(is, e.lastName);
    is >> e.salary;
    return is;
}

ostream &operator << (ostream &os, Employee e) {
    os << "Employee[";
    os << "id=" << e.id << ',';
    os << "name=" << e.firstName << " " << e.lastName << ',';
    os << fixed << setprecision(2) << "salary=$" << e.salary << "]"; 
    return os;
}

Employee& Employee::operator++() {
    this->salary = this->salary + this->salary*10/100;
    return *this;
}

Employee Employee::operator++(int) {
    Employee temp = *this;
    this->salary = this->salary + this->salary*10/100;
    return temp;
}

Employee& Employee::operator--() {
    this->salary = this->salary - this->salary*10/100;
    return *this;
}

Employee Employee::operator--(int) {
    Employee temp = *this;
    this->salary = this->salary - this->salary*10/100;
    return temp;
}

Employee Employee::operator+(double themLuong) {
    this->salary = this->salary + themLuong;
    return *this;
}

Employee Employee::operator-(double truLuong) {
    this->salary = this->salary - truLuong;
    return *this;
}

bool Employee::operator < (Employee e2) {
    return this->salary < e2.salary;
}

bool Employee::operator > (Employee e2) {
    return this->salary > e2.salary;
}

bool Employee::operator == (Employee e2) {
    return this->salary == e2.salary;
}

int main() {
    Employee e1, e2;
    cin >> e1 >> e2;
    cout << e1 << '\n';
    cout << e2 << '\n';
    if (e1 == e2) {
        cout << "BANG NHAU" << '\n';
    }
    else if (e1 < e2) {
        cout << "NHO HON" << '\n';
    } 
    else {
        cout << "LON HON" << '\n';
    }
    double a, b; cin >> a >> b;
    --e2;
    e2 = e2 + b;
    cout << "$" << (e1++ - a).getSalary() << '\n';
    cout << "$" << e2.getSalary();
}