#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#if defined(_WIN32)
#define CLR system("cls");
#else
#define CLR system("clear");
#endif
void menuUI()
{
    cout << setw(72) << setfill('-') << "" << endl;
    cout << setw(50) << setfill(' ') << "TRAVEL INFORMATION SYSTEM" << endl;
    cout << setw(47) << setfill(' ') << "*/Powered By C++/*" << endl;
    cout << setw(72) << setfill('-') << "" << endl;
}
void line()
{
    cout << setw(72) << setfill('-') << "" << endl;
}
using namespace std;

class Traveller
{
private:
    string t_name;
    int t_age;
    string destination_addr;

public:
    void EditAge()
    {
        int t;
        do
        {
            CLR;
            menuUI();
            cout << "Enter the traveler's name: ";
            cin.ignore();
            string t_name;
            getline(cin, t_name);

            ifstream in(t_name + ".txt");

            if (in.is_open())
            {
                string line;
                string updatedContent = "";
                bool found = false;

                while (getline(in, line))
                {
                    if (line.find("Age:") != string::npos)
                    {
                        cout << "Enter New Age: ";
                        int newAge;
                        cin >> newAge;
                        line = "Age: " + to_string(newAge);
                        found = true;
                    }
                    updatedContent += line + '\n';
                }

                in.close();

                if (found)
                {
                    ofstream out(t_name + ".txt");
                    out << updatedContent;
                    out.close();

                    cout << "Age updated successfully for " << t_name << ".\n";
                }
                else
                {
                    cout << "Age not found for traveler " << t_name << ".\n";
                }
                cout << "\n";
                cout << "Displaying Traveler Information for " << t_name << ":\n";
                ifstream in(t_name + ".txt");
                if (in.is_open())
                {
                    string str;
                    while (getline(in, str))
                    {
                        if (str.find("Destination Address:") != string::npos)
                            cout << endl;
                        cout << str << endl;
                    }
                    in.close();
                }
                else
                {
                    cout << "Traveler not found." << endl;
                    cout << "\nEnter 1 to go to main menu\n";
                    cout << "Enter 2 to try again\n";
                    cin >> t;
                    cout << "\n";
                }
                cout << "\nEnter 1 to go to main menu\n";
                cout << "Enter 2 to try again\n";
                cin >> t;
                cout << "\n";
            }
            else
            {
                cout << "Traveler " << t_name << " not found. Please enter a valid traveler name.\n";
                cout << "\nEnter 1 to go to main menu\n";
                cout << "Enter 2 to try again\n";
                cin >> t;
                cout << "\n";
            }
        } while (t != 1);
    }

    void EnterTravellerdetail()
    {
        CLR;
        menuUI();
        int t;
        do
        {
            cout << "Enter traveler name: ";
            cin.ignore();
            getline(cin, t_name);
            cout << "Enter traveler age: ";
            cin >> t_age;
            cout << "Enter destination address: ";
            cin.ignore();
            getline(cin, destination_addr);

            ofstream out(t_name + ".txt");
            out << "Name: " << t_name << endl;
            out << "Age: " << t_age << endl;
            out << "Destination Address: " << destination_addr << endl;
            out.close();

            ifstream in(t_name + ".txt");
            if (in.is_open())
            {
                string mode;

                cout << "Enter Travel Mode: ";
                cin >> mode;

                in.close();

                ofstream out(t_name + ".txt", ios::app);
                out << "Travel Mode: " << mode << endl;
                out.close();
            }
            else
            {
                cout << "Traveler not found." << endl;
                cout << " \nEnter 1 to go to main menu\n";
                cout << " \n Enter 2 to try again\n";
                cin >> t;
            }

            displayTravelerInfo();
            cout << "\nEnter 1 to go to main menu\n";
            cout << "Enter 2 to try again\n";
            cin >> t;
            cout << "\n";
        } while (t != 1);
    }

    // void SaveInfoInFile()
    // {
    //     ofstream out(t_name + ".txt");
    //     out << "Name: " << t_name << endl;
    //     out << "Age: " << t_age << endl;
    //     out << "Destination Address: " << destination_addr << endl;
    //     out.close();
    // }

    void displayTravelerInfo()
    {
        cout << "\n";
        CLR;
        menuUI();
        cout << "Displaying Traveler Information for " << t_name << ":\n";
        ifstream in(t_name + ".txt");
        if (in.is_open())
        {
            string str;
            while (getline(in, str))
            {
                if (str.find("Destination Address:") != string::npos)
                {
                    cout << endl;
                }
                cout << str << endl;
            }
            in.close();
        }
        else
        {
            cout << "Traveler not found." << endl;
        }
    }

    void appendTravelMode()
    {
        int t;
        do
        {
            CLR;
            menuUI();
            cout << "Enter Name of the Traveller: ";
            cin.ignore();
            getline(cin, t_name);

            ifstream in(t_name + ".txt");
            if (in.is_open())
            {
                string mode;

                cout << "Enter Travel Mode: ";
                cin >> mode;

                in.close();

                ofstream out(t_name + ".txt", ios::app);
                out << "Travel Mode: " << mode << endl;
                out.close();

                cout << "Travel mode appended successfully." << endl;
            }
            else
            {
                cout << "Traveler not found." << endl;
                cout << " \nEnter 1 to go to main menu\n";
                cout << " \n Enter 2 to try again\n";
                cin >> t;
            }
            displayTravelerInfo();
            cout << "\nEnter 1 to go to main menu\n";
            cout << "Enter 2 to try again\n";
            cin >> t;
            cout << "\n";
        } while (t != 1);
    }
    void appendDestinationAddress()
    {
        int t;
        do
        {
            CLR;
            menuUI();
            cout << "Enter Name of the Traveller: ";
            cin.ignore();
            getline(cin, t_name);

            ifstream in(t_name + ".txt");
            if (in.is_open())
            {
                string address;
                string tmode;

                cout << "Enter Destination Address: ";
                getline(cin, address);

                cout << "Travel Mode: ";
                getline(cin, tmode);

                in.close();

                ofstream out(t_name + ".txt", ios::app);
                out << "Destination Address: "
                    << " " << address << endl;
                out << "Travel Mode: "
                    << " " << tmode << endl;
                out.close();

                cout << "Destination address and Travel Mode appended successfully." << endl;
            }
            else
            {
                cout << "Traveler not found." << endl;
                cout << "\nEnter 1 to go to the main menu\n";
                cout << "Enter 2 to try again\n";
                cin >> t;
            }
            displayTravelerInfo();
            cout << "\nEnter 1 to go to the main menu\n";
            cout << "Enter 2 to try again\n";
            cin >> t;
            cout << "\n";
        } while (t != 1);
    }
};
int main()
{
    Traveller trav_obj;
    int choose;
    CLR;
    menuUI();
    while (true)
    {
        CLR;
        menuUI();
        cout << "                  1. Enter new Traveler Details" << endl;
        cout << "                  2. Edit Age of a Traveler" << endl;
        cout << "                  3. Append Travel Mode to a Traveler File" << endl;
        cout << "                  4. Append Destination Address" << endl;
        cout << "                  5. Exit" << endl;
        cout << "                  Enter your choice: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            cout << "You selected: Enter traveller detail.\n";
            trav_obj.EnterTravellerdetail();
            // trav_obj.SaveInfoInFile();
            break;

        case 2:
            cout << "You selected: Edit age of traveller.\n";
            trav_obj.EditAge();
            //  trav_obj.displayTravelerInfo();
            break;

        case 3:
            cout << "You selected: Append travel mode.\n";
            trav_obj.appendTravelMode();
            break;
        case 4:
            cout << "You selected: Append Destination Address to a Traveler File.\n";
            trav_obj.appendDestinationAddress();
            break;

        case 5:
            cout << "Exited Successfully\n";
            return 0;

        default:
            CLR;
            menuUI();
            cout << "Invalid choice. Please enter a valid option (1-4).\n";
            break;
        }
    p:
        fflush(stdin);
    }

    return 0;
}
