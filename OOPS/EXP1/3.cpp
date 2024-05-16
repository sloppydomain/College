#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Bank
{
private:
    string Name;
    int Transactions;
    long int AccountNum;
    long double Balance;

public: 
    Bank() // constructor
    {
        Name = "";
        Transactions = 0;
        AccountNum = 0;
        Balance = 0.0;
    }
    void Deposit(double Amount)
    {
        if (Amount > 0)
        {
            Balance += Amount;
            Transactions++;
            cout << "Deposited " << Amount << " into the account.\n";
        }
    }
    void Withdraw(double Amount)
    {
        if (Amount > 0 && Balance >= 500 && Amount <= Balance)
        {
            Balance -= Amount;
            Transactions++;
            cout << "Withdrawed " << Amount << " from the account.\n";
        }
        else
            cout << "You don't have sufficient balance to withdraw money.\n";
    }
    void transactions()
    {
        cout << "Number of transactions performed are " << Transactions;
    }
    void DisplayAccount()
    {
        cout << "Name : " << Name << "\n";
        cout << "Account Number : " << AccountNum << "\n";
        cout << "Bank Balance : " << Balance << "\n";
        cout << "Number of Transactions : " << Transactions << "\n";
    }
    void setDetails(int num)
    {
        cin.ignore();
        getline(cin, Name);
        AccountNum = num;
    }
    long int getAccNum()
    {
        return AccountNum;
    }
    long int CheckBalance()
    {
        return Balance;
    }
    long int TransacNum()
    {
        return Transactions;
    }
};
int main()
{
    int n, i;
    cout << "Enter the number of Accounts : ";
    cin >> n;
    Bank *accounts = new Bank[n];
    for (i = 0; i < n; i++)
    {
        int accountNum = 1000 + i;
        cout << "Enter account holder name for account " << i + 1 << " :\n";
        accounts[i].setDetails(accountNum);
    }
    for (i = 0; i < n; i++)
    {
        cout << "\n\nDetails of account " << i + 1 << " are : \n";
        accounts[i].DisplayAccount();
    }
    while (1)
    {
        cout << "\n\nMenu : \n";
        cout << "1. Display Account Details\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Show Transactions\n";
        cout << "6. Exit\n";
        cout << "Enter choice : ";
        int choice, AccNum;
        cin >> choice;
        double amount;
        switch (choice)
        {
        case 1:
            if (n == 1)
            {
                accounts[0].DisplayAccount();
                break;
            }
            cout << "Enter account number to display details : ";
            cin >> AccNum;
            if (AccNum >= 1000 && n > 0)
            {
                for (i = 0; i < n; i++)
                {
                    if (accounts[i].getAccNum() == AccNum)
                    {
                        cout << "\n\nDetails of account with account number " << AccNum << " are : \n";
                        accounts[i].DisplayAccount();
                    }
                }
            }
            else
                cout << "Person with that Account Number does not Exist....\n";
            break;
        case 2:
            if (n == 1)
            {
                cout << "Enter Amount to be deposited : ";
                cin >> amount;
                accounts[0].Deposit(amount);
                break;
            }
            cout << "Enter account number to Deposit Money : ";
            cin >> AccNum;
            if (AccNum >= 1000 && n > 1)
            {
                cout << "Enter Amount to be deposited : ";
                cin >> amount;
                for (i = 0; i < n; i++)
                {
                    if (accounts[i].getAccNum() == AccNum)
                    {
                        accounts[i].Deposit(amount);
                    }
                }
            }
            else
                cout << "Person with that Account Number does not Exist....\n";
            break;
        case 3:
            if (n == 1)
            {
                cout << "Enter Amount to be Withdrawed : ";
                cin >> amount;
                accounts[0].Withdraw(amount);
                break;
            }
            cout << "Enter account number to Withdraw Money : ";
            cin >> AccNum;
            if (AccNum >= 1000 && n > 0)
            {
                cout << "Enter Amount to be Withdrawed : ";
                cin >> amount;
                for (i = 0; i < n; i++)
                {
                    if (accounts[i].getAccNum() == AccNum)
                    {
                        accounts[i].Withdraw(amount);
                    }
                }
            }
            else
                cout << "Accout with that Account number does not exist....\n";
            break;
        case 4:
            if (n == 1)
            {
                cout << "Balance in account with account number " << accounts[0].getAccNum() << " is " << accounts[0].CheckBalance() << "\n";
                break;
            }
            cout << "Enter account number to Check Balance : ";
            cin >> AccNum;
            if (AccNum >= 1000 && n > 0)
            {
                for (i = 0; i < n; i++)
                {
                    if (accounts[i].getAccNum() == AccNum)
                    {
                        cout << "Balance in account with account number " << accounts[0].getAccNum() << " is " << accounts[0].CheckBalance() << "\n";
                    }
                }
            }
            else
                cout << "Person with that Account Number does not Exist....\n";
            break;
        case 5:
            if (n == 1)
            {
                cout << "Number of transactions performed with account number " << accounts[0].getAccNum() << " are " << accounts[0].TransacNum() << endl;
                break;
            }
            cout << "Enter account number to Check Transactions : ";
            cin >> AccNum;
            if (AccNum >= 1000 && n > 0)
            {
                for (i = 0; i < n; i++)
                {
                    if (accounts[i].getAccNum() == AccNum)
                    {
                        cout << "Number of transactions performed with account number " << AccNum << " are " << accounts[i].TransacNum() << endl;
                    }
                }
            }
            else
                cout << "Person with that Account Number does not Exist....\n";
            break;
        case 6:
            cout << "Exiting...\n";
            goto jump;
        default:
            cout << "Invalid choice...\n";
            break;
        }
    }
jump:
    delete[] accounts;
    return 0;
}