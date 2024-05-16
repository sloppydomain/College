//Q7a
#include <iostream>
#include <iomanip>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(5) {}

    Counter& operator++() {
        count++;
        return *this;
    }

    Counter& operator--() {
        count--;
        return *this;
    }

    int operator++(int) {
        int temp = count;
        ++(*this);
        return temp;
    }

    int operator--(int) {
        int temp = count;
        --(*this);
        return temp;
    }

    int getCount() {
        return count;
    }
};

int main() {
    Counter c;
    cout.width(20);
    cout.fill('-');
    cout << "" << endl;

    cout.width(20);
    cout.fill(' ');
    cout << "Initial Count: ";
    cout.width(3);
    cout << c.getCount() << endl;

    ++c;

    cout.width(20);
    cout.fill(' ');
    cout << "After Prefix Increment: ";
    cout.width(3);
    cout << c.getCount() << endl;

    --c;

    cout.width(20);
    cout.fill(' ');
    cout << "After Prefix Decrement: ";
    cout.width(3);
    cout << c.getCount() << endl;

    int d = c++;

    cout.width(20);
    cout.fill(' ');
    cout << "After Postfix Increment: ";
    cout.width(3);
    cout << d << endl;

    int e = c--;

    cout.width(20);
    cout.fill(' ');
    cout << "After Postfix Decrement: ";
    cout.width(3);
    cout << e << endl;

    cout.width(20);
    cout.fill('-');
    cout << "" << endl;

    cout.width(20);
    cout.fill(' ');
    cout << "Final Value: ";
    cout.width(3);
    cout << c.getCount() << endl;

    return 0;
}
/*
    OUTPUT - 
    --------------------
     Initial Count:   5
After Prefix Increment:   6
After Prefix Decrement:   5
After Postfix Increment:   5
After Postfix Decrement:   6
--------------------
       Final Value:   5
       */