#include <iostream>
#include <cstring>
#include <cmath>
#include <limits>
using namespace std;
class Book
{
    string author;
    string publisher;
    long int price;
    int stockposition;
    static int successfulTransactions;
    static int unsuccessfulTransactions;
    void updatePrice(long int newPrice)
    {
        price = newPrice;
        cout << "Price updated successfully!" << endl;
    }

public:
    Book()
    {
        author = "";
        title = "";
        publisher = "";
        price = 0;
        stockposition = 0;
        void updatePrice(long int);
    }
    string title;
    ~Book()
    {
        cout << "Book instance for '" << title << "' destroyed." << endl;
    }
    void getdata()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the author's name: ";
        cin.ignore();
        getline(cin, author);
        cout << "Enter the book title: ";
        getline(cin, title);
        cout << "Enter the publisher's name: ";
        getline(cin, publisher);
        cout << "Enter the book's price: ";
        cin >> price;
        cout << "Enter the stock position: ";
        cin >> stockposition;
    }
    void displaydata()
    {
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock Position: " << stockposition << endl;
    }

    void purchase(int numCopies)
    {
        if (numCopies <= stockposition)
        {
            stockposition -= numCopies;
            successfulTransactions++;
            cout << "Purchase successful! Remaining stock: " << stockposition << endl;
        }
        else
        {
            unsuccessfulTransactions++;
            cout << "Purchase failed. Not enough copies in stock." << endl;
        }
    }

    inline int getStockPosition() const
    {
        return stockposition;
    }
    inline long int getPrice() const
    {
        return price;
    }

    static void showTransactionStats()
    {
        cout << "Successful Transactions: " << successfulTransactions << endl;
        cout << "Unsuccessful Transactions: " << unsuccessfulTransactions << endl;
    }
    friend void checkBook(string t, string a, int n, Book books[]);
    friend void purchaseBook(string t, string a, int n, Book books[]);
    void updateBookPrice(long int newPrice)
    {
        updatePrice(newPrice);
    }
};

int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;
void purchaseBook(string t, string a, int n, Book books[])
{
    for (int i = 0; i < n; i++)
    {
        if (books[i].title == t && books[i].author == a)
        {
            int numCopies;
            cout << "Enter the number of copies you want to purchase: ";
            cin >> numCopies;

            books[i].purchase(numCopies);

            if (numCopies <= books[i].getStockPosition())
            {
                cout << "Total Price: " << numCopies * books[i].getPrice() << endl;
            }
            break;
        }
        if (i == n - 1)
        {
            cout << "Book with the entered title not found." << endl;
        }
    }
}
void checkBook(string t, string a, int n, Book books[])
{
    long int newP;
    for (int i = 0; i < n; i++)
    {
        if (books[i].title == t && books[i].author == a)
        {
            cout << "Enter new price of the book : ";
            cin >> newP;
            books[i].updateBookPrice(newP);
            break;
        }
        if (i == n - 1)
        {
            cout << "Book with the entered title not found." << endl;
        }
    }
}
int main()
{
    int n;
    string requestedTitle, requestedAuthor;
label:
    cout << "Enter the number of books: ";
    cin >> n;

    Book *books = new Book[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for Book " << i + 1 << ":" << endl;
        books[i].getdata();
    }

    cout << "\nBook Details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nBook " << i + 1 << ":\n";
        books[i].displaydata();
    }

    int choice;
    while (1)
    {
        cout << "\n1. Purchase books\n";
        cout << "2. Update Book Price\n";
        cout << "3. Display Transactions\n";
        cout << "4. Display Book Details\n";
        cout << "5. Delete all details of books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "\nEnter the title of the book you want to purchase: ";
            getline(cin, requestedTitle);
            cout << "\nEnter the name of the book's author you want to purchase: ";
            getline(cin, requestedAuthor);
            purchaseBook(requestedTitle, requestedAuthor, n, books);
            Book::showTransactionStats();
            break;
        case 2:
            cin.ignore();
            cout << "\nEnter the title of the book : ";
            getline(cin, requestedTitle);
            cout << "\nEnter the name of the book's author : ";
            getline(cin, requestedAuthor);
            checkBook(requestedTitle, requestedAuthor, n, books);
            break;
        case 3:
            Book::showTransactionStats();
            break;
        case 4:
            cout << "\nBook Details:\n";
            for (int i = 0; i < n; i++)
            {
                cout << "\nBook " << i + 1 << ":\n";
                books[i].displaydata();
            }
            break;
        case 5:
            delete[] books;
            cout << "All details of books have been deleted\n";
            goto label;
        case 6:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid choice\n";
            break;
        }
    }
    return 0;
}
/*
OUTPUT - 
Enter the number of books: 2   
Enter details for Book 1:
Enter the author's name:  yash1
Enter the book title: science1
Enter the publisher's name: dgbshd
Enter the book's price: 800
Enter the stock position: 5
Enter details for Book 2:
Enter the author's name:  yash2
Enter the book title: science2
Enter the publisher's name: ajs
Enter the book's price: 400
Enter the stock position: 5

Book Details:

Book 1:
Author: yash1
Title: science1
Publisher: dgbshd
Price: 800
Stock Position: 5

Book 2:
Author: yash2
Title: science2
Publisher: ajs
Price: 400
Stock Position: 5

1. Purchase books
2. Update Book Price
3. Display Transactions
4. Display Book Details
5. Delete all details of books
6. Exit
Enter your choice : 1

Enter the title of the book you want to purchase: science1

Enter the name of the book's author you want to purchase: yash1
Enter the number of copies you want to purchase: 5  
Purchase successful! Remaining stock: 0
Successful Transactions: 1
Unsuccessful Transactions: 0

1. Purchase books
2. Update Book Price
3. Display Transactions
4. Display Book Details
5. Delete all details of books
6. Exit
Enter your choice : 2

Enter the title of the book : science1

Enter the name of the book's author : yash1
Enter new price of the book : 900
Price updated successfully!

1. Purchase books
2. Update Book Price
3. Display Transactions
4. Display Book Details
5. Delete all details of books
6. Exit
Enter your choice : 3
Successful Transactions: 1
Unsuccessful Transactions: 0

1. Purchase books
2. Update Book Price
3. Display Transactions
4. Display Book Details
5. Delete all details of books
6. Exit
Enter your choice : 4

Book Details:

Book 1:
Author: yash1
Title: science1
Publisher: dgbshd
Price: 900
Stock Position: 0

Book 2:
Author: yash2
Title: science2
Publisher: ajs
Price: 400
Stock Position: 5

1. Purchase books
2. Update Book Price
3. Display Transactions
4. Display Book Details
5. Delete all details of books
6. Exit
Enter your choice : 5
Book instance for 'science2' destroyed.
Book instance for 'science1' destroyed.
All details of books have been deleted
*/