// Q5a

#include <iostream>
#include <string>
using namespace std;
class Student
{
protected:
    string name;
    string u_regNumber;

public:
    Student(string name, string u_regNumber) : name(name), u_regNumber(u_regNumber) {}

    void displayInfo()
    {
        cout << "Name: " << name << ", University Registration Number: " << u_regNumber << endl;
    }
};

class Arts : public Student
{
protected:
    string major;
    string arts_RollNo;

public:
    Arts(const string &name, const string &u_regNumber, const string &major, const string &arts_RollNo) : Student(name, u_regNumber), major(major), arts_RollNo(arts_RollNo) {}

    void displayInfo()
    {
        cout << "\n";
        Student::displayInfo();
        cout << "Major: " << major << "\nDepartment: Arts"
             << "\nDepartment Roll Number: " << arts_RollNo << endl;
    }
};

class Engineering : public Student
{
protected:
    string engineeringMajor;
    string EngRollNo;

public:
    Engineering(const string &name, const string &u_regNumber, const string &engineeringMajor, const string &EngRollNo) : Student(name, u_regNumber), engineeringMajor(engineeringMajor), EngRollNo(EngRollNo) {}

    void displayInfo()
    {
        cout << "\n";
        Student::displayInfo();
        cout << "Engineering Major: " << engineeringMajor << "\nDepartment: Engineering"
             << "\nDepartment Roll Number: " << EngRollNo << endl;
    }
};

class MechanicalEngineering : public Engineering
{
protected:
    string specialization;

public:
    MechanicalEngineering(string name, string u_regNumber, string engineeringMajor, string specialization, string EngRollNo)
        : Engineering(name, u_regNumber, engineeringMajor, EngRollNo), specialization(specialization) {}

    void displayInfo()
    {
        cout << "\n";
        Engineering::displayInfo();
        cout << "Specialization: " << specialization << endl;
    }
};

class ElectricalEngineering : public Engineering
{
protected:
    string specialization;

public:
    ElectricalEngineering(string name, string u_regNumber, string engineeringMajor, string specialization, string EngRollNo)
        : Engineering(name, u_regNumber, engineeringMajor, EngRollNo), specialization(specialization) {}

    void displayInfo()
    {
        cout << "\n";
        Engineering::displayInfo();
        cout << "Specialization: " << specialization << endl;
    }
};

class ComputerEngineering : public Engineering
{
protected:
    string specialization;

public:
    ComputerEngineering(string name, string u_regNumber, string engineeringMajor, string specialization, string EngRollNo)
        : Engineering(name, u_regNumber, engineeringMajor, EngRollNo), specialization(specialization) {}

    void displayInfo()
    {
        cout << "\n";
        Engineering::displayInfo();
        cout << "Specialization: " << specialization << endl;
    }
};
class Medicine : public Student
{
protected:
    string major;
    string med_RollNo;

public:
    Medicine(const string &name, const string &u_regNumber, const string &major, const string &med_RollNo) : Student(name, u_regNumber), major(major), med_RollNo(med_RollNo) {}

    void displayInfo()
    {
        cout << "\n";
        Student::displayInfo();
        cout << "Major: " << major << "\nDepartment: Arts"
             << "\nDepartment Roll Number: " << med_RollNo << endl;
    }
};
int main()
{
    Arts artsStudent("Alice", "101", "History", "9248424");
    ComputerEngineering mechanicalStudent("Yash", "201", "Computer Engineering", "Engineering Graphics", "8478543");
    Medicine medStudent("xyz", "102", "Botany", "934902");

    artsStudent.displayInfo();
    mechanicalStudent.displayInfo();
    medStudent.displayInfo();

    return 0;
}
/*
OUTPUT :
Name: Alice, University Registration Number: 101
Major: History
Department: Arts
Department Roll Number: 9248424


Name: Yash, University Registration Number: 201
Engineering Major: Computer Engineering
Department: Engineering
Department Roll Number: 8478543
Specialization: Engineering Graphics

Name: xyz, University Registration Number: 102
Major: Botany
Department: Arts
Department Roll Number: 934902
*/