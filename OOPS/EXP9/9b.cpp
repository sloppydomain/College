//Q9b

#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
class Vector
{
    T *v;
    int size_;

public:
    Vector(int size_, const T &value = T()) : size_(size_), v(new T[size_])
    {
        for (int i = 0; i < size_; i++)
            v[i] = value;
    }

    ~Vector()
    {
        delete[] v;
    }

    void getData()
    {
        for (int i = 0; i < size_; i++)
        {
            cout << "Element at position " << i + 1 << " : ";
            cin >> v[i];
        }
    }

    void modify(int x, T y)
    {
        if (x <= 0 || x > size_)
        {
            cout << "Invalid Position\n";
        }
        else
        {
            v[x - 1] = y;
        }
    }

    void display() const
    {
        for (int i = 0; i < size_; i++)
            cout << v[i] << " ";
    }
    int size()
    {
        return size_;
    }
    void resize(int x, const T &value = T())
    {
        if (size_ == x)
            return;
        T *v1 = new T[x];
        for (int i = 0; i < min(size_, x); i++)
            v1[i] = v[i];
        if (x > size_)
        {
            for (int i = size_; i < x; i++)
                v1[i] = value;
        }
        delete[] v;
        v = v1;
        size_ = x;
    }
    void push_back(const T &value)
    {
        T *v1 = new T[size_ + 1];
        for (int i = 0; i < size_; i++)
            v1[i] = v[i];
        v1[size_] = value;
        delete[] v;
        v = v1;
        size_++;
    }
    void pop_back()
    {
        if (size_ <= 0)
            return;
        size_--;
        T *v1 = new T[size_];
        for (int i = 0; i < size_; i++)
        {
            v1[i] = v[i];
        }
        delete[] v;
        v = v1;
    }
};

int main()
{
    int size, choice;
    cout << "Enter the size of the vector: ";
    cin >> size;

    Vector<int> a(size);

    cout << "Enter vector elements:\n";
    a.getData();

    while (1)
    {
        cout << "\n\n1. Append" << endl;
        cout << "2. Modify" << endl;
        cout << "3. Display" << endl;
        cout << "4. Resize" << endl;
        cout << "5. Remove from last " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int n;
            cout << "Enter value of element to be appended : ";
            cin >> n;
            a.push_back(n);
            break;
        case 2:
            int p, x;
            cout << "Enter position of element to be updated: ";
            cin >> p;
            cout << "Enter value of element to be updated: ";
            cin >> x;
            a.modify(p, x);
            break;
        case 3:
            cout << "Contents of vector are: ";
            a.display();
            break;
        case 4:
            cout << "Enter new size : ";
            cin >> size;
            a.resize(size);
            break;
        case 5:
            a.pop_back();
            break;
        case 6:
            cout << "Exiting" << endl;
            exit(0);
        default:
            cout << "Invalid choice...";
            break;
        }
    }
    return 0;
}
/*
OUTPUT - 
Enter the size of the vector: 2
Enter vector elements:
Element at position 1 : 2
Element at position 2 : 33


1. Append
2. Modify
3. Display
4. Resize
5. Remove from last 
6. Exit 
Enter choice : 1
Enter value of element to be appended : 44


1. Append
2. Modify
3. Display
4. Resize
5. Remove from last 
6. Exit 
Enter choice : 2
Enter position of element to be updated: 1
Enter value of element to be updated: 99


1. Append
2. Modify
3. Display
4. Resize
5. Remove from last 
6. Exit 
Enter choice : 3
Contents of vector are: 99 33 44 

1. Append
2. Modify
3. Display
4. Resize
5. Remove from last
6. Exit
Enter choice : 4
Enter new size : 4


1. Append
2. Modify
3. Display
4. Resize
5. Remove from last
6. Exit
Enter choice : 3
Contents of vector are: 99 33 44 0

1. Append
2. Modify
3. Display
4. Resize
5. Remove from last
6. Exit
Enter choice : 5


1. Append
2. Modify
3. Display
4. Resize
5. Remove from last
6. Exit
Enter choice : 3
Contents of vector are: 99 33 44

1. Append
2. Modify
3. Display
4. Resize
5. Remove from last
6. Exit
Enter choice : 6
Exiting


CONCLUSION - TEMPLATES IN C++ WERE SUCCESSFULLY STUDIED AND IMPLEMENTED
*/