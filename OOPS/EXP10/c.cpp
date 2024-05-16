// Qc
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cstring>

#ifdef _WIN32
#define CLR system("cls");
#else
#define CLR system("clear");
#endif

class Student
{
private:
    std::string name;
    int age;
    std::string rollNo;
    std::string address;
    std::string branch;

public:
    // Constructor
    Student() : age(0) {}

    // Getter functions
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getRollNo() const { return rollNo; }
    std::string getAddress() const { return address; }
    std::string getBranch() const { return branch; }

    // Setter functions
    void setName(const std::string &newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setRollNo(const std::string &newRollNo) { rollNo = newRollNo; }
    void setAddress(const std::string &newAddress) { address = newAddress; }
    void setBranch(const std::string &newBranch) { branch = newBranch; }

    // Overloaded input and output operators
    friend std::ostream &operator<<(std::ostream &out, const Student &student)
    {
        out << "Name: " << student.name << "\n"
            << "Age: " << student.age << "\n"
            << "Roll No: " << student.rollNo << "\n"
            << "Address: " << student.address << "\n"
            << "Branch: " << student.branch << "\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Student &student)
    {
        std::cout << "Enter Name: ";
        in.ignore();
        getline(in, student.name);
        std::cout << "Enter Age: ";
        in >> student.age;
        std::cout << "Enter Roll No: ";
        in.ignore();
        getline(in, student.rollNo);
        std::cout << "Enter Address: ";
        in.ignore();
        getline(in, student.address);
        std::cout << "Enter Branch: ";
        in.ignore();
        getline(in, student.branch);
        return in;
    }

    // Function to update each detail separately
    void updateName()
    {
        std::cout << "Enter updated Name: ";
        std::cin.ignore();
        getline(std::cin, name);
    }

    void updateAge()
    {
        std::cout << "Enter updated Age: ";
        std::cin >> age;
    }

    void updateRollNo()
    {
        std::cout << "Enter updated Roll No: ";
        std::cin.ignore();
        getline(std::cin, rollNo);
    }

    void updateAddress()
    {
        std::cout << "Enter updated Address: ";
        std::cin.ignore();
        getline(std::cin, address);
    }

    void updateBranch()
    {
        std::cout << "Enter updated Branch: ";
        std::cin.ignore();
        getline(std::cin, branch);
    }
};

void saveStudentsToFile(const std::map<std::string, Student> &students)
{
    std::ofstream outFile("students.dat", std::ios::binary | std::ios::out);

    for (const auto &pair : students)
    {
        outFile.write(reinterpret_cast<const char *>(&pair.second), sizeof(Student));
    }

    outFile.close();
}

void loadStudentsFromFile(std::map<std::string, Student> &students)
{
    students.clear();
    std::ifstream inFile("students.dat", std::ios::binary | std::ios::in);

    if (!inFile)
    {
        std::cerr << "Error opening file for reading.\n";
        return;
    }

    Student student;
    while (inFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        students[student.getRollNo()] = student;
    }

    inFile.close();

    // Debug print
    std::cout << "Loaded " << students.size() << " students from file.\n";
}

void createStudent(std::map<std::string, Student> &students)
{
    Student s;
    // Input student details
    std::cout << "Enter student details:\n";
    std::cin >> s;

    // Add the student to the map
    students[s.getRollNo()] = s;
}

void displayStudent(const std::map<std::string, Student> &students)
{
    std::string rollNo;
    std::cout << "Enter student roll number: ";
    std::cin >> rollNo;

    // Search for the student in the map
    auto it = students.find(rollNo);
    if (it != students.end())
    {
        std::cout << "Student details:\n"
                  << it->second;
    }
    else
    {
        std::cout << "Student not found.\n";
    }
}

// Function to update all details of a student
void updateStudentDetails(std::map<std::string, Student> &students)
{
    std::string rollNo;
    std::cout << "Enter student roll number to update details: ";
    std::cin >> rollNo;

    auto it = students.find(rollNo);
    if (it != students.end())
    {
        int updateChoice;
        do
        {
            CLR;
            std::cout << "Update student details:\n"
                      << "1---Name\n"
                      << "2---Age\n"
                      << "3---Roll No\n"
                      << "4---Address\n"
                      << "5---Branch\n"
                      << "6---Exit\n"
                      << "Enter choice No. : ";
            std::cin >> updateChoice;

            switch (updateChoice)
            {
            case 1:
                it->second.updateName();
                break;
            case 2:
                it->second.updateAge();
                break;
            case 3:
                it->second.updateRollNo();
                break;
            case 4:
                it->second.updateAddress();
                break;
            case 5:
                it->second.updateBranch();
                break;
            case 6:
                saveStudentsToFile(students);
                std::cout << "Student details updated successfully.\n";
                break;
            default:
                std::cout << "\nInvalid choice....";
                break;
            }
        } while (updateChoice != 6);
    }
    else
    {
        std::cout << "Student not found.\n";
    }
}

int main()
{
    char t;
    CLR;
    std::map<std::string, Student> students;
    loadStudentsFromFile(students);
    int choice;
    do
    {
        CLR;
        std::cout << "1---Create student\n"
                  << "2---Display student\n"
                  << "3---Update student details\n"
                  << "4---Exit\n"
                  << "Enter choice No. : ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            createStudent(students);
            saveStudentsToFile(students);
            break;
        case 2:
            displayStudent(students);
            break;
        case 3:
            updateStudentDetails(students);
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            CLR;
            std::cout << "\nInvalid choice....";
            break;
        }
        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    } while (choice != 4);

    return 0;
}

/*
OUTPUT -
1---Create student
2---Display student
3---Update student details
4---Exit
Enter choice No. : 2
Enter student roll number: 22B-CO-075
Student details:
Name: Yash Malviya
Age: 20
Roll No: 22B-CO-075
Address: ARGAO GOA
Branch: OMPUTER ENGINEERING
Press Enter to continue...

Update student details:
1---Name
2---Age
3---Roll No
4---Address
5---Branch
6---Exit
Enter choice No. : 2
Enter updated Age: 20

Update student details:
1---Name
2---Age
3---Roll No
4---Address
5---Branch
6---Exit
Enter choice No. : 4
Enter updated Address: PONDA GOA

Update student details:
1---Name
2---Age
3---Roll No
4---Address
5---Branch
6---Exit
Enter choice No. : 6
Student details updated successfully.

1---Create student
2---Display student
3---Update student details
4---Exit
Enter choice No. : 2
Enter student roll number: 22B-CO-075
Student details:
Name: Yash Malviya
Age: 20
Roll No: 22B-CO-075
Address: PONDA GOA
Branch: OMPUTER ENGINEERING



CONCLUSION - FILE PROCESSING WAS SUCCESSFULLY STUDIED AND IMPLEMENTED....
*/