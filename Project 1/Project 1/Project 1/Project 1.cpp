//CS3330 Programming Project 1 - Eddy Garcia

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Employee 
{
public:
    int employeeId;
    string firstName;
    string lastName;
    string phoneNumber;
    string emailAddress;
    double salary;

    Employee(int id, string fName, string lName, string phone, string email, double sal)
        : employeeId(id), firstName(fName), lastName(lName), phoneNumber(phone), emailAddress(email), salary(sal) {}

    void display() const 
    {
        cout << employeeId << " " << firstName << " " << lastName << " " << phoneNumber
            << " " << emailAddress << " " << salary << endl;
    }
};

class LinkedList 
{
private:
    struct Node 
    {
        Employee employee;
        Node* next;

        Node(Employee emp) : employee(emp), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    //Insert an employee into the list, ordered by employeeId
    void insert(Employee emp) 
    {
        Node* newNode = new Node(emp);

        //If the list is empty or the new employee's id is less than the head's id
        if (!head || head->employee.employeeId > emp.employeeId) 
        {
            newNode->next = head;
            head = newNode;
        }
        else 
        {
            Node* current = head;
            while (current->next && current->next->employee.employeeId < emp.employeeId) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    //Display all employees in the list
    void display() const 
    {
        Node* current = head;
        while (current) 
        {
            current->employee.display();
            current = current->next;
        }
    }

    ~LinkedList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() 
{
    LinkedList employeeList;

    //Open the file
    ifstream file("Week 1-employeeDataset_Project 1.txt");
    if (!file) 
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) 
    {
        stringstream ss(line);
        int id;
        string fName, lName, phone, email;
        double salary;

        //Read employee data from the file
        ss >> id >> fName >> lName >> phone >> email >> salary;

        //Create an Employee object and insert it into the list
        Employee emp(id, fName, lName, phone, email, salary);
        employeeList.insert(emp);
    }

    //Close the file
    file.close();

    //Display all employees ordered by employeeId
    employeeList.display();

    return 0;
}
