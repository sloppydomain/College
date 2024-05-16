// Q5b

#include <iostream>
using namespace std;
class student
{
protected:
    int roll_Number;
    string Name;

public:
    void getData(const int &a, const string &Name)
    {
        roll_Number = a;
        this->Name = Name;
    }
    void displayroll()
    {
        cout << "Name : " << Name << endl;
        cout << "Roll No : " << roll_Number << endl;
    }
};
class test : virtual public student
{
protected:
    double sub1, sub2;

public:
    void getmarks(double x, double y)
    {
        sub1 = x;
        sub2 = y;
    }
    void displaymarks()
    {
        cout << "Marks Obtained : "
             << "\n"
             << "Subject 1 : " << sub1 << "\n"
             << "Subject 2 : " << sub2 << "\n";
    }
};
class sports : virtual public student // To allow only one copy of student data memebers to be shared between sports and test or to prevent multipile copies to be formed
{
protected:
    double sports_marks;

public:
    void getsmarks(double x)
    {
        sports_marks = x;
    }
    void displaysmarks()
    {
        cout << "Sports marks obtained : " << sports_marks << endl;
    }
};
class result : public test, public sports
{
    double total;

public:
    void results()
    {
        total = sub1 + sub2 + sports_marks;
        displayroll();
        displaymarks();
        displaysmarks();
        cout << "Final Score : " << total << endl;
        double percentage = total / 2.1;
        if (percentage > 100)
            cout << "Invalid marks....";
        else
            cout << "Percentage: " << percentage << " %" << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore();
    result *s = new result[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        string studentName;
        int rn, m1, m2, m3;
        cout << "Enter student name : ";
        getline(cin, studentName);
        cout << "Enter student roll Number : ";
        cin >> rn;
        s[i].getData(rn, studentName);
        cout << "Enter marks in subject 1: ";
        cin >> m1;
        cout << "Enter marks in subject 2: ";
        cin >> m2;
        cout << "Enter sports marks: ";
        cin >> m3;
        if (m1 > 100 || m2 > 100 || m3 > 10)
        {
            cout << "Invalid marks. Marks should be <= 100 for subjects and <= 10 for sports." << endl;
            i--;
        }
        else
        {
            s[i].getmarks(m1, m2);
            s[i].getsmarks(m3);
        }
        cin.ignore();
    }
    cout << "\nStudents Results:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "\nStudent " << i + 1 << ":\n";
        s[i].results();
    }
    delete[] s;
    return 0;
}
/*
OUTPUT :
Enter the number of students: 2

Enter details for Student 1:
Enter student name : yash malviya
Enter student roll Number : 75
Enter marks in subject 1: 99
Enter marks in subject 2: 96
Enter sports marks: 10

Enter details for Student 2:
Enter student name : piyush malviya
Enter student roll Number : 99
Enter marks in subject 1: 111 
Enter marks in subject 2: 1000
Enter sports marks: 99
Invalid marks. Marks should be <= 100 for subjects and <= 10 for sports.

Enter details for Student 2:
Enter student name : piyush malviya 
Enter student roll Number : 99
Enter marks in subject 1: 99
Enter marks in subject 2: 94
Enter sports marks: 10

Students Results:

Student 1:
Name : yash malviya
Roll No : 75
Marks Obtained : 
Subject 1 : 99
Subject 2 : 96
Sports marks obtained : 10
Final Score : 205
Percentage: 97.619 %

Student 2:
Name : piyush malviya
Roll No : 99
Marks Obtained :
Subject 1 : 99
Subject 2 : 94
Sports marks obtained : 10
Final Score : 203
Percentage: 96.6667 %
*/