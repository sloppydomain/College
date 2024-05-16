//Q6a

#include <iostream>
#include <string>
using namespace std;

class media
{
protected:
    string title;
    double cost;

public:
    media(const string &title, const double &cost) : title(title), cost(cost) {}
    virtual void display() {}
};

class book : public media
{
protected:
    int pages;

public:
    book(const string &s, const double &d, const int &i) : media(s, d), pages(i) {}

    void display() override
    {
        cout << "\nTitle: " << title;
        cout << "\nCost: " << cost;
        cout << "\nPages: " << pages;
    }
};

class tape : public media
{
protected:
    double time;

public:
    tape(const string &s, const double &d, const double &t) : media(s, d), time(t) {}

    void display() override
    {
        cout << "\nTitle: " << title;
        cout << "\nCost: " << cost;
        cout << "\nPlay Time: " << time;
    }
};

int main()
{
    int n1, n2;
    string title;
    double price, time;
    int pages;

    cout << "Enter the number of books: ";
    cin >> n1;
    cout << "Enter the number of tapes: ";
    cin >> n2;

    media **books = new media *[n1];
    media **tapes = new media *[n2];

    for (int i = 0; i < n1; i++)
    {
        cout << "Enter book " << i + 1 << " details:\n";
        cout << "Title: ";
        cin >> title;
        cout << "Price: ";
        cin >> price;
        cout << "Pages: ";
        cin >> pages;
        books[i] = new book(title, price, pages);
    }

    for (int i = 0; i < n2; i++)
    {
        cout << "Enter tape " << i + 1 << " details:\n";
        cout << "Title: ";
        cin >> title;
        cout << "Price: ";
        cin >> price;
        cout << "Play time: ";
        cin >> time;
        tapes[i] = new tape(title, price, time);
    }

    cout << "Media Details....\n";
    for (int i = 0; i < n1; i++)
    {
        cout << "BOOK " << i + 1 << endl;
        books[i]->display();
    }

    for (int i = 0; i < n2; i++)
    {
        cout << "TAPE " << i + 1 << endl;
        tapes[i]->display();
    }

    for (int i = 0; i < n1; i++)
    {
        delete books[i];
    }
    for (int i = 0; i < n2; i++)
    {
        delete tapes[i];
    }

    delete[] books;
    delete[] tapes;

    return 0;
}
/*
OUTPUT : 
Enter the number of books: 2
Enter the number of tapes: 1
Enter book 1 details:
Title: usdha
Price: 9248
Pages: 93
Enter book 2 details:
Title: dfjsf
Price: 999
Pages: 99
Enter tape 1 details:
Title: jadj
Price: 888
Play time: 92
Media Details....
BOOK 1

Title: usdha
Cost: 9248
Pages: 93BOOK 2

Title: dfjsf
Cost: 999
Pages: 99TAPE 1

Title: jadj
Cost: 888
Play Time: 92
*/