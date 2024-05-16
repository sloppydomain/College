//Q6b

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
    virtual void display() = 0;
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
        cout << "\nBOOK " << i + 1 << endl;
        books[i]->display();
    }
    cout <<"\n\n";
    for (int i = 0; i < n2; i++)
    {
        cout << "\nTAPE " << i + 1 << endl;
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
Enter the number of books: 1
Enter the number of tapes: 1
Enter book 1 details:
Title: sba
Price: 984
Pages: 84
Enter tape 1 details:
Title: jasdn
Price: 8947
Play time: 94
Media Details....
BOOK 1
Title: sba
Cost: 984
Pages: 84
TAPE 1
Title: jasdn
Cost: 8947
Play Time: 94




CONCLUSION - VIRTAULS FUNCTIONS AND RUN TIME POLYMORPHISM WERE SUCCESSFULLY STUDIED AND IMPLEMENTED.

*/