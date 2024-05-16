#include <iostream>
using namespace std;
class vector
{
private:
    float *v;
    int n;

public:
    vector() : v(nullptr), n(0) {}
    vector(int size)
    {
        n = size;
        v = new float[n];
    }
    void setData(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter value at position " << i + 1 << " : ";
            cin >> v[i];
        }
    }
    void Delete()
    {
        delete[] v;
        v = nullptr;
        n = 0;
        cout << "The previous contents of this vector are deleted...\n";
    }
    void Display()
    {
        cout << "(";
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << v[i];
                if (i != n - 1)
                    cout << ", ";
            }
        }
        cout << ")";
    }
    void modify(int x, int value)
    {
        if (x >= 1 && x <= n)
        {
            v[x - 1] = value;
            Display();
        }
        else
        {
            cout << "Invalid position..." << endl;
        }
    }
    vector operator+(vector &v22)
    {
        vector result(n);
        for (int i = 0; i < result.n; i++)
            result.v[i] = v[i] + v22.v[i];
        return result;
    }
    friend vector operator*(int, vector);
};
vector operator*(int x, vector v)
{
    vector v1;
    v1.n = v.n;
    v1.v = new float[v.n];
    int i;
    for (i = 0; i < v.n; i++)
    {
        v1.v[i] = x * v.v[i];
    }
    return v1;
}
int main()
{
    int s, size;
    vector v1, v2;
    int choice1, choice2;
    while (1)
    {
        cout << "\n1. Create a vector\n";
        cout << "2. Modify Vector\n";
        cout << "3. Multiply scalar\n";
        cout << "4. Display\n";
        cout << "5. Add two vectors\n";
        cout << "6. Delete Vector\n";
        cout << "7. Exit\n";
        cout << "Enter choice : ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            printf("Enter elements in vector 1 : \n");
            cout << "Enter the number of terms : ";
            cin >> size;
            v1.Delete();
            v1 = vector(size);
            v1.setData(size);
            break;
        case 2:
            float val;
            int pos;
            cout << "\nEnter value of element you want to insert : ";
            cin >> val;
            cout << "\nEnter position of element you want to modify : ";
            cin >> pos;
            v1.modify(pos, val);
            break;
        case 3:
            cout << "\nEnter the scalar to be multiplied : ";
            cin >> s;
            v2 = vector(size);
            v2 = s * v1;
            cout << "Contents after multiplying by a scalar are stored in vector 2.\n";
            cout << "\nContents of the vector 2 are : ";
            v2.Display();
            break;
        case 4:
            cout << "\n1. Vector 1\n";
            cout << "2. Vector 2\n";
            cout << "Enter choice : ";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                cout << "\nContents of the vector are : ";
                v1.Display();
                break;
            case 2:
                cout << "\nContents of the vector are : ";
                v2.Display();
                break;
            case 3:
                cout << "Exiting....\n";
                exit(0);
            default:
                cout << "Invalid choice...\n";
                break;
            }
            break;
        case 5:
        {
            int size1, size2;
            vector result;
            cout << "Enter the size of the first vector to be created : ";
            cin >> size1;
            cout << "Enter the size of the second vector to be created : ";
            cin >> size2;
            if (size1 == size2)
            {
                v1 = vector(size1);
                v2 = vector(size2);
                result = vector(size1);
                v1.setData(size1);
                v2.setData(size2);
                result = v1 + v2;
                cout << "\nContents of the vector after adding are : ";
                result.Display();
            }
            else
                cout << "Vectors with Unequal sizes cannot be added!\n";
            break;
        }
        case 6:
            cout << "\n1. Vector 1\n";
            cout << "2. Vector 2\n";
            cout << "Enter choice : ";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                v1.Delete();
                break;
            case 2:
                v2.Delete();
                break;
            case 3:
                cout << "Exiting....\n";
                exit(0);
            default:
                cout << "Invalid choice...\n";
                break;
            }
            break;
        case 7:
            cout << "Exiting....\n";
            exit(0);
        default:
            cout << "Invalid choice...\n";
            break;
        }
    }
    return 0;
}
/*
OUTPUT - 
1. Create a vector
2. Modify Vector
3. Multiply scalar
4. Display
5. Add two vectors
6. Delete Vector
7. Exit
Enter choice : 1
Enter elements in vector 1 : 
Enter the number of terms : 3
The previous contents of this vector are deleted...
Enter value at position 1 : 7 
Enter value at position 2 : 8
Enter value at position 3 : 4

1. Create a vector
2. Modify Vector
3. Multiply scalar
4. Display
5. Add two vectors
6. Delete Vector
7. Exit
Enter choice : 2

Enter value of element you want to insert : 4

Enter position of element you want to modify : 1
(4, 8, 4)
1. Create a vector
2. Modify Vector
3. Multiply scalar
4. Display
5. Add two vectors
6. Delete Vector
7. Exit
Enter choice : 3

Enter the scalar to be multiplied : 5
Contents after multiplying by a scalar are stored in vector 2.

Contents of the vector 2 are : (20, 40, 20)
1. Create a vector
2. Modify Vector
3. Multiply scalar
4. Display
5. Add two vectors
6. Delete Vector
7. Exit
Enter choice : 5
Enter the size of the first vector to be created : 3
Enter the size of the second vector to be created : 3
Enter value at position 1 : 7
Enter value at position 2 : 6
Enter value at position 3 : 5
Enter value at position 1 : 4
Enter value at position 2 : 5
Enter value at position 3 : 3

Contents of the vector after adding are : (11, 11, 8)
1. Create a vector
2. Modify Vector
3. Multiply scalar
4. Display
5. Add two vectors
6. Delete Vector
7. Exit
Enter choice : 6

1. Vector 1
2. Vector 2
Enter choice : 1
The previous contents of this vector are deleted...

1. Create a vector
2. Modify Vector
3. Multiply scalar
4. Display
5. Add two vectors
6. Delete Vector
7. Exit
Enter choice : 4

1. Vector 1
2. Vector 2
Enter choice : 2

Contents of the vector are : (4, 5, 3)
1. Create a vector
2. Modify Vector
3. Multiply scalar
4. Display
5. Add two vectors
6. Delete Vector
7. Exit
Enter choice : 7
Exiting....
*/