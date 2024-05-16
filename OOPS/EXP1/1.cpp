#include <iostream>
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32)
#define CLR system("cls")
#else
#define CLR system("clear")
#endif
using namespace std;

class student
{
private:
    static int set_RollNo;
    string Name;
    int Roll_No;
    string Branch;
    double marks[5];
    double percentage;

public:
    student()
    {
        Roll_No = set_RollNo++;
        Name = "";
        Branch = "";
        for (int i = 0; i < 5; ++i)
        {
            marks[i] = 0.0;
        }
        percentage = 0.0;
    }

    void getDetails()
    {
        cout << "Enter Name of Student : ";
        cin.ignore();
        getline(cin, Name);
        cout << "Enter Branch : ";
        cin >> Branch;
        cout << "\nEnter Marks of each subject :-\n";
        cout << "Enter math marks : ";
        cin >> marks[0];
        cout << "Enter Logic Design marks : ";
        cin >> marks[1];
        cout << "Enter Computer Organisation marks : ";
        cin >> marks[2];
        cout << "Enter Data Structures marks : ";
        cin >> marks[3];
        cout << "Enter OOPS marks : ";
        cin >> marks[4];
    }
    void calculate_percentage()
    {
        double total_marks = 0.0;
        for (int i = 0; i < 5; i++)
        {
            total_marks += marks[i];
        }
        percentage = total_marks / 5;
        cout << "Percentage : " << percentage << "%\n";
    }
    void display_marks()
    {
        cout << "Math marks : " << marks[0] << "\n";
        cout << "Logic Design marks : " << marks[1] << "\n";
        cout << "Computer Organization marks : " << marks[2] << "\n";
        cout << "Data Strcutures marks : " << marks[3] << "\n";
        cout << "OOPS marks : " << marks[4] << "\n";
    }
    void DisplayDetails()
    {
        cout << "Name : " << Name << "\n";
        cout << "Roll No : " << Roll_No << "\n";
        cout << "Branch : " << Branch << "\n";
        cout << "\nMarks of the student in each subject are :- \n";
        display_marks();
        calculate_percentage();
    }
    int getRollNo()
    {
        return Roll_No;
    }
};
int student ::set_RollNo = 1;
int main()
{
    int n, RollNo, flag = 1, i;
    cout << "Enter Number of students : ";
    cin >> n;
    student s[n];
    int choice;
    while (1)
    {
        printf("Menu : \n");
        printf("1. Enter student Details.\n");
        printf("2. Display details of all students.\n");
        printf("3. Display student details based on roll no.\n");
        printf("4. Compute and display all students result.\n");
        printf("5. Display result of student with roll no.\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (i = 0; i < n; i++)
            {
                cout << "Enter the Details of student " << i + 1 << " :\n";
                s[i].getDetails();
            }
            break;
        case 2:
            for (i = 0; i < n; i++)
            {
                cout << "\nThe details of student " << i + 1 << " are :\n";
                s[i].DisplayDetails();
            }
            break;
        case 3:
            cout << "Enter roll_no to display details: ";
            cin >> RollNo;
            if (n >= RollNo && RollNo >= 1)
                for (int i = 0; i < n; ++i)
                {
                    if (s[i].getRollNo() == RollNo)
                    {
                        cout << "\nThe details of student with Roll No " << RollNo << " are :\n";
                        s[i].DisplayDetails();
                        break;
                    }
                }
            else
                cout << "Student with that roll no does not exist...\n";
            break;
        case 4:
            for (i = 0; i < n; i++)
            {
                s[i].display_marks();
                s[i].calculate_percentage();
            }
            break;
        case 5:
            cout << "Enter roll no to display result : \n";
            cin >> RollNo;
            if (n >= RollNo && RollNo >= 1)
                for (i = 0; i < n; i++)
                {
                    if (s[i].getRollNo() == RollNo)
                    {
                        cout << "\nThe result of student with Roll No " << RollNo << " are :\n";
                        s[i].display_marks();
                        s[i].calculate_percentage();
                    }
                }
            else
                cout << "Student with that roll no does not exist...\n";
            break;
        case 6:
            goto jump;
        default:
            cout << "Wrong choice...\n";
        }
    }
jump:
    return 0;
}