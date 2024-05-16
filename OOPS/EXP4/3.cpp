#include <iostream>
using namespace std;
class String
{
    char *s;

public:
    String() : s(nullptr) {}
    ~String()
    {
        delete[] s;
    }
    String(const char *a)
    {
        int len = 0;
        while (a[len] != '\0')
        {
            len++;
        }
        s = new char[len + 1];
        for (int i = 0; i < len; i++)
            s[i] = a[i];
        s[len] = '\0';
    }
    String(const String &t)
    {
        int len = t.getLength();
        s = new char[len + 1];
        for (int i = 0; i <= len; i++)
            s[i] = t.s[i];
    }
    int getLength() const
    {
        if (s == nullptr)
            return 0;
        int len = 0;
        while (s[len] != '\0')
            len++;
        return len;
    }
    int getLength(const char *a)
    {
        if (a == nullptr)
            return 0;
        int len = 0;
        while (a[len] != '\0')
            len++;
        return len;
    }
    String operator=(const String &other)
    {
        delete[] s;       
        int len = other.getLength();
        s = new char[len + 1]; 
        for (int i = 0; i <= len; i++)
            s[i] = other.s[i];
        return s;
    }
    String operator+(const String &b)
    {
        int len1 = getLength();
        int len2 = b.getLength();
        String c;
        c.s = new char[len1 + len2 + 1];
        for (int i = 0; i < len1; i++)
            c.s[i] = s[i];
        for (int j = 0; j < len2; j++)
            c.s[j + len1] = b.s[j];
        c.s[len1 + len2] = '\0';
        return c;
    }
    void Display()
    {
        if (s == nullptr)
        {
            cout << "String is Empty.\n";
            return;
        }
        int len = getLength(s);
        cout << "String : " << s << endl;
    }
    bool operator==(const String &a)
    {
        int l1 = getLength();
        int l2 = a.getLength();
        if (l1 != l2)
            return false;
        for (int i = 0; i < l1; i++)
        {
            if (s[i] != a.s[i])
                return false;
        }
        return true;
    }
    friend void operator<<(ostream &dout, const String &a)
    {
        if (a.s == nullptr)
            return;
        int l = a.getLength();
        for (int i = 0; a.s[i] != '\0'; i++)
            dout << a.s[i];
    }
};
int main()
{
    char *x = new char[100];
    char c;
    int i = 0;
    cout << "Enter string 1 : ";
    while (cin.get(c) && c != '\n')
    {
        x[i++] = c;
        if (i % 100 == 0)
        {
            char *t = new char[i + 100];
            for (int j = 0; j < i; j++)
            {
                t[j] = x[j];
            }
            delete[] x;
            x = t;
        }
    }
    x[i] = '\0';

    char *y = new char[100];
    i = 0;
    cout << "Enter string 2 : ";
    while (cin.get(c) && c != '\n')
    {
        y[i++] = c;
        if (i % 100 == 0)
        {
            char *t = new char[i + 100];
            for (int j = 0; j < i; j++)
            {
                t[j] = y[j];
            }
            delete[] y;
            y = t;
        }
    }
    y[i] = '\0';
    String s1(x), s2(y), s3;
    s3 = s1 + s2;

    cout << '\n';
    cout << "String 1 : ";
    cout << s1;
    cout << '\n';
    cout << "String 2 : ";
    cout << s2;
    cout << '\n';
    cout << "String after comibining 1 and 2 : ";
    cout << s3;

    cout << "\n";
    if (s1 == s2)
        cout << "Strings 1 and 2 are equal." << endl;
    else
        cout << "Strings 1 and 2 are not equal." << endl;
    delete[] x;
    delete[] y;
    return 0;
}
// #include <iostream>
// using namespace std;

// class String
// {
//     char *s;

// public:
//     // Default constructor
//     String() : s(nullptr) {}

//     // Parameterized constructor
//     String(const char *a)
//     {
//         int len = 0;
//         while (a[len] != '\0')
//         {
//             len++;
//         }
//         s = new char[len + 1];
//         for (int i = 0; i <= len; i++)
//             s[i] = a[i];
//     }

//     // Destructor to release memory
//     ~String()
//     {
//         delete[] s;
//     }

//     // Copy constructor
//     String(const String &other)
//     {
//         int len = other.getLength();
//         s = new char[len + 1];
//         for (int i = 0; i <= len; i++)
//             s[i] = other.s[i];
//     }

//     // Get the length of the string
//     int getLength() const
//     {
//         int len = 0;
//         while (s[len] != '\0')
//             len++;
//         return len;
//     }

//     // Overloaded assignment operator
//     String &operator=(const String &other)
//     {
//         if (this == &other)
//             return *this; // Check for self-assignment
//         delete[] s;       // Release the old memory
//         int len = other.getLength();
//         s = new char[len + 1]; // Allocate new memory
//         for (int i = 0; i <= len; i++)
//             s[i] = other.s[i];
//         return *this;
//     }

//     // Concatenation operator
//     String operator+(const String &b)
//     {
//         int len1 = getLength();
//         int len2 = b.getLength();
//         String c;
//         c.s = new char[len1 + len2 + 1];
//         for (int i = 0; i < len1; i++)
//             c.s[i] = s[i];
//         for (int j = 0; j < len2; j++)
//             c.s[j + len1] = b.s[j];
//         c.s[len1 + len2] = '\0';
//         return c;
//     }

//     // Display the string
//     void Display()
//     {
//         if (s == nullptr)
//         {
//             cout << "String is Empty.\n";
//             return;
//         }
//         cout << "String : " << s << endl;
//     }

//     // Comparison operator
//     bool operator==(const String &a)
//     {
//         int l1 = getLength();
//         int l2 = a.getLength();
//         if (l1 != l2)
//             return false;
//         for (int i = 0; i < l1; i++)
//         {
//             if (s[i] != a.s[i])
//                 return false;
//         }
//         return true;
//     }

//     // Friend function to overload the << operator
//     friend void operator<<(ostream &dout, const String &a)
//     {
//         if (a.s == nullptr)
//             return;
//         int l = a.getLength();
//         for (int i = 0; i < l; i++)
//             dout << a.s[i];
//     }
// };

// int main()
// {
//     char *x = new char[100];
//     char c;
//     int i = 0;
//     cout << "Enter string 1 : ";
//     while (cin.get(c) && c != '\n')
//     {
//         x[i++] = c;
//         if (i % 100 == 0)
//         {
//             char *t = new char[i + 100];
//             for (int j = 0; j < i; j++)
//             {
//                 t[j] = x[j];
//             }
//             delete[] x;
//             x = t;
//         }
//     }
//     x[i] = '\0';

//     char *y = new char[100];
//     i = 0;
//     cout << "Enter string 2 : ";
//     while (cin.get(c) && c != '\n')
//     {
//         y[i++] = c;
//         if (i % 100 == 0)
//         {
//             char *t = new char[i + 100];
//             for (int j = 0; j < i; j++)
//             {
//                 t[j] = y[j];
//             }
//             delete[] y;
//             y = t;
//         }
//     }
//     y[i] = '\0';

//     String s1(x), s2(y), s3;
//     s3 = s1 + s2;

//     cout << '\n';
//     cout << "String 1 : ";
//     cout << s1;
//     cout << '\n';
//     cout << "String 2 : ";
//     cout << s2;
//     cout << '\n';
//     cout << "String after combining 1 and 2 : ";
//     cout << s3;

//     cout << "\n";
//     if (s1 == s2)
//         cout << "Strings 1 and 2 are equal." << endl;
//     else
//         cout << "Strings 1 and 2 are not equal." << endl;

//     delete[] x;
//     delete[] y;
//     return 0;
// }
