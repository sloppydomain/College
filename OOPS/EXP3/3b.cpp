#include <iostream>
using namespace std;
class student
{
    int RollNo;
    string Name;
    double percent;

public:
    // student() : RollNo(0),Name(" "),percent(0) {};
    student()
    {
        RollNo = 0;
        Name = " ";
        percent = 0;
    }
    student(int rn, string n, double p)
    {
        RollNo = rn;
        Name = n;
        percent = p;
    }
    student(const student &s)
    {
        RollNo = s.RollNo;
        Name = s.Name;
        percent = s.percent;
    }
    void Display()
    {
        cout << "\nRoll No - " << RollNo << "\nName - " << Name << "\nPercentage - " << percent << "%" << endl;
    }
};
int main()
{
    student s1(75, "Yash", 99);
    student s3,s4;
    student s2(s1);  // User defined copy constructor
    s3 = s2; // Default copy Constructor
    s1.Display();
    s2.Display();
    s3.Display();
    s4.Display();
    return 0;
}
/*
OUTPUT - 

Roll No - 75
Name - Yash
Percentage - 99%

Roll No - 75
Name - Yash
Percentage - 99%

Roll No - 75
Name - Yash
Percentage - 99%

Roll No - 0
Name -  
Percentage - 0%
*/