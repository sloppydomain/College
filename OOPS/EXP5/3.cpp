// Q5c

#include <iostream>
#include <string>
using namespace std;

class Address
{
protected:
    string street;
    string city;
    string state;
    string zipCode;

public:
    Address(const string &street, const string &city, const string &state, const string &zipCode)
        : street(street), city(city), state(state), zipCode(zipCode) {}

    void displayAddress() const
    {
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "ZIP Code: " << zipCode << endl;
    }
};

class BankAccount
{
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string &accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    void displayAccount() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Student
{
protected:
    string name;
    int age;
    Address address;
    BankAccount account;

public:
    Student() : name(""), age(0), address("", "", "", ""), account("", 0.0) {}

    Student(const string &name, int age, const Address &address, const BankAccount &account)
        : name(name), age(age), address(address), account(account) {}

    void displayStudent() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address:\n";
        address.displayAddress();
        cout << "Bank Account:\n";
        account.displayAccount();
    }
};

int main()
{
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();
    Student *students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        string studentName, studentStreet, studentCity, studentState, studentZipCode;
        int studentAge;
        cout << "Enter Student Name: ";
        getline(cin, studentName);
        cout << "Enter Student Age: ";
        cin >> studentAge;
        cin.ignore();
        cout << "Enter Student Address : \n\n";
        cout << "Enter street : ";
        getline(cin, studentStreet);
        cout << "Enter city : ";
        getline(cin, studentCity);
        cout << "Enter State : ";
        getline(cin, studentState);
        cout << "Enter ZipCode : ";
        getline(cin, studentZipCode);
        string accountNumber;
        double accountBalance;
        cout << "Enter Bank Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Balance: $";
        cin >> accountBalance;
        Address studentAddress(studentStreet, studentCity, studentState, studentZipCode);
        BankAccount studentAccount(accountNumber, accountBalance);
        students[i] = Student(studentName, studentAge, studentAddress, studentAccount);
        cin.ignore();
    }
    cout << "\nStudent Details:\n";
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].displayStudent();
    }
    delete[] students;

    return 0;
}
/*
OUTPUT :
Enter the number of students: 3

Enter details for Student 1:
Enter Student Name: yash malviya
Enter Student Age: 19
Enter Student Address : 

Enter street : dongorim
Enter city : margao
Enter State : goa
Enter ZipCode : 403707
Enter Bank Account Number: 9389423
Enter Account Balance: $999

Enter details for Student 2:
Enter Student Name: xyz
Enter Student Age: 19
Enter Student Address : 

Enter street : adjf
Enter city : jsdnfj
Enter State : jndas
Enter ZipCode : 833
Enter Bank Account Number: 8390849
Enter Account Balance: $893

Enter details for Student 3:
Enter Student Name: snjdfun
Enter Student Age: 783
Enter Student Address : 

Enter street : jand
Enter city : jdan
Enter State : jsn
Enter ZipCode : 2931
Enter Bank Account Number: 3892\
Enter Account Balance: $9384

Student Details:

Student 1:
Name: yash malviya
Age: 19
Address:
Street: dongorim
City: margao
State: goa
ZIP Code: 403707
Bank Account:
Account Number: 9389423
Balance: $999

Student 2:
Name: xyz
Age: 19
Address:
Street: adjf
City: jsdnfj
State: jndas
ZIP Code: 833
Bank Account:
Account Number: 8390849
Balance: $893

Student 3:
Name: snjdfun
Age: 783
Address:
Street: jand
City: jdan
State: jsn
ZIP Code: 2931
Bank Account:
Account Number: 3892
Balance: $9384
*/