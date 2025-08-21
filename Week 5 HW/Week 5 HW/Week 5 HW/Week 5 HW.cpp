// Week 5 HW: Employee Class with 3 Constructors, mutator functions, main function. 
// Programmer: Eddy Garcia

#include <iostream>
#include <string>
using namespace std;

//Class definition for Employee
class Employee 
{
private:
    string name;          //Employee's name
    int idNumber;         //Employee's ID number
    string department;    //Department 
    string position;      //Employee's job title

public:
    //Constructor that accepts all four parameters
    Employee(string n, int id, string dept, string pos)
        : name(n), idNumber(id), department(dept), position(pos) {}

    //Constructor that accepts name and ID number only
    Employee(string n, int id)
        : name(n), idNumber(id), department(""), position("") {}

    //Default constructor
    Employee()
        : name(""), idNumber(0), department(""), position("") {}

    //Mutator (Setter) functions
    void setName(string n) { name = n; }
    void setIdNumber(int id) { idNumber = id; }
    void setDepartment(string dept) { department = dept; }
    void setPosition(string pos) { position = pos; }

    //Accessor (Getter) functions
    string getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    string getDepartment() const { return department; }
    string getPosition() const { return position; }

    //Function to display employee details
    void displayEmployeeInfo() const 
    {
        cout << "Employee Name: " << name << endl;
        cout << "ID Number: " << idNumber << endl;
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
    }
};

int main() 
{
    //Creating three Employee objects with data
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119, "IT", "Programmer");
    Employee emp3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    //Displaying details for each employee
    cout << "Employee 1 Details:" << endl;
    emp1.displayEmployeeInfo();
    cout << endl;

    cout << "Employee 2 Details:" << endl;
    emp2.displayEmployeeInfo();
    cout << endl;

    cout << "Employee 3 Details:" << endl;
    emp3.displayEmployeeInfo();
    cout << endl;

    return 0;
}
