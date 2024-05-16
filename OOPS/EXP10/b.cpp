// Qb
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

const string fileName = "telephone_directory.txt";

void loadTelephoneDirectory(map<string, string> &telephoneDirectory)
{
    ifstream inputFile(fileName);
    if (inputFile.is_open())
    {
        string name, number;
        while (inputFile >> name >> number)
        {
            telephoneDirectory[name] = number;
        }
        inputFile.close();
    }
}

void saveTelephoneDirectory(const map<string, string> &telephoneDirectory)
{
    ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        for (const auto &user : telephoneDirectory)
        {
            outputFile << user.first << " " << user.second << "\n";
        }
        outputFile.close();
    }
}

int main()
{
    map<string, string> telephoneDirectory;
    loadTelephoneDirectory(telephoneDirectory);

    while (true)
    {
        cout << "Telephone Directory Application\n";
        cout << "1. Add a new user\n";
        cout << "2. Search for a user\n";
        cout << "3. Update a user's telephone number\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, number;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter telephone number: ";
            cin >> number;
            telephoneDirectory[name] = number;
            saveTelephoneDirectory(telephoneDirectory);
            cout << "Entry added successfully.\n";
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, name);
            if (telephoneDirectory.find(name) != telephoneDirectory.end())
            {
                cout << "\nTelephone number: " << telephoneDirectory[name] << endl;
            }
            else
            {
                cout << "Entry not found in the directory.\n";
            }
            break;
        }
        case 3:
        {
            string name, newNumber;
            cout << "Enter name to update: ";
            cin.ignore();
            getline(cin, name);
            if (telephoneDirectory.find(name) != telephoneDirectory.end())
            {
                cout << "Enter new telephone number: ";
                cin >> newNumber;
                telephoneDirectory[name] = newNumber;
                saveTelephoneDirectory(telephoneDirectory);
                cout << "Telephone number updated successfully.\n";
            }
            else
            {
                cout << "Entry not found in the directory.\n";
            }
            break;
        }
        case 4:
        {
            cout << "Exiting the program.\n";
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again.\n";
        }
        }
    }
}

/*
OUTPUT -
Telephone Directory Application
1. Add a new user
2. Search for a user
3. Update a user's telephone number
4. Exit
Enter choice: 1
Enter name: Yash Malviya
Enter telephone number: 823483
Entry added successfully.
Telephone Directory Application
1. Add a new user
2. Search for a user
3. Update a user's telephone number
4. Exit
Enter choice: 2
Enter name to search: Yash Malviya

Telephone number: 823483
Telephone Directory Application
1. Add a new user
2. Search for a user
3. Update a user's telephone number
4. Exit
Enter choice: 1
Enter name: Piyush Malviya
Enter telephone number: 93289483
Entry added successfully.
Telephone Directory Application
1. Add a new user
2. Search for a user
3. Update a user's telephone number
4. Exit
Enter choice: 3
Enter name to update: Piyush Malviya
Enter new telephone number: 83724378
Telephone number updated successfully.
Telephone Directory Application
1. Add a new user
2. Search for a user
3. Update a user's telephone number
4. Exit
Enter choice: 2
Enter name to search: Piyush Malviya

Telephone number: 83724378
Telephone Directory Application
1. Add a new user
2. Search for a user
3. Update a user's telephone number
4. Exit
Enter choice: 4
Exiting the program.

*/