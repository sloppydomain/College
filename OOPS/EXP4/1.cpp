//Q4a

#include <iostream>
using namespace std;
class Counter
{
private:
    int count;

public:
    Counter() : count(5) {}
    Counter &operator++()
    {
        count++;
        return *this;
    }
    Counter &operator--()
    {
        count--;
        return *this;
    }
    int operator++(int)
    {
        int temp = count;
        ++(*this);
        return temp;
    }
    int operator--(int)
    {
        int temp = count;
        --(*this);
        return temp;
    }

    int getCount()
    {
        return count;
    }
};

int main()
{
    Counter c;

    cout << "Initial Count: " << c.getCount() << endl;
    ++c;
    cout << "After Prefix Increment: " << c.getCount() << endl;
    --c;
    cout << "After Prefix Decrement: " << c.getCount() << endl;
    int d = c++;
    cout << "After Postfix Increment: " << d << endl;
    int e = c--;
    cout << "After Postfix Decrement: " << e << endl;
    cout << "Final Value: " << c.getCount() << endl;
    return 0;
}
/*
OUTPUT - 
Initial Count: 5
After Prefix Increment: 6
After Prefix Decrement: 5
After Postfix Increment: 5
After Postfix Decrement: 6
Final Value: 5
*/