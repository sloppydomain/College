// Qabc
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    cout << "\033[1mString Assignment and Concatenation.\033[0m\n";
    string s1 = "Goa ";
    string s2 = "College Of Engineering";
    if (s1 == s2)
        cout << "Both Strings are equal\n";
    else
        cout << "Both strings are not equal\n";
    string s3;
    s3 = s1 + s2;
    cout << "String 1: " << s1 << "\n";
    cout << "String 2: " << s2 << "\n";
    cout << "Concatenated String: " << s3 << "\n\n";

    string s4 = "College Of";
    char c1 = 'r';

    cout << "\033[1mSubstring and Characters in a string.\033[0m\n";
    int foundSubStr = s3.find(s4);
    if (foundSubStr != s4.length())
    {
        cout << "Substring '" << s4 << "' found at position " << foundSubStr << "\n";
    }
    else
    {
        cout << "Substring '" << s4 << "' not found.\n";
    }

    int foundChar = s3.find(c1);
    if (foundChar != s4.length())
    {
        cout << "Character '" << c1 << "' found at position " << foundChar << "\n\n";
    }
    else
    {
        cout << "Character '" << c1 << "' not found.\n\n";
    }

    cout << "\033[1mSwapping Strings.\033[0m\n";
    string swapStr1 = "One";
    string swapStr2 = "Two";
    cout << "Before swapping:\n";
    cout << "String 1: " << swapStr1 << "\n";
    cout << "String 2: " << swapStr2 << "\n";

    swap(swapStr1, swapStr2);

    cout << "After swapping:\n";
    cout << "String 1: " << swapStr1 << "\n";
    cout << "String 2: " << swapStr2 << "\n";
    cout << "\n\n";

    cout << "\033[1mString Iterators.\033[0m\n";
    cout << "1. Using Range Based For Loop.\n";
    for (auto c : s3)
        cout << c;
    cout << "\n\n";
    cout << "2. Using iterators to output the string:\n";
    string ::iterator it;
    for (it = s3.begin(); it != s3.end(); ++it)
        cout << *it;
    cout << "\n\n";

    cout << "\033[1mString stream and processing concept.\033[0m\n";
    string numStr = "123";
    int num;
    stringstream numStream(numStr);
    numStream >> num;
    if (!numStream.fail())
    {
        cout << "Converted integer: " << num << endl;
    }
    else
    {
        cerr << "Conversion failed." << endl;
    }
    cout << "\n";
    double pi = 3.14159;
    stringstream piStream;
    piStream << pi;
    string piStr = piStream.str();

    cout << "Converted string: " << piStr << endl;
    cout << "\n";

    string firstName = "Yash";
    string lastName = "Malviya";
    stringstream fullNameStream;
    fullNameStream << firstName << " " << lastName;
    string fullName = fullNameStream.str();

    cout << "Full Name: " << fullName << endl;
    return 0;
}

/*
OUTPUT -
String Assignment and Concatenation.
Both strings are not equal
String 1: Goa
String 2: College Of Engineering
Concatenated String: Goa College Of Engineering

Substring and Characters in a string.
Substring 'College Of' found at position 4
Character 'r' found at position 22

Swapping Strings.
Before swapping:
String 1: One
String 2: Two
After swapping:
String 1: Two
String 2: One


String Iterators.
1. Using Range Based For Loop.
Goa College Of Engineering

2. Using iterators to output the string:
Goa College Of Engineering

String stream and processing concept.
Converted integer: 123

Converted string: 3.14159

Full Name: Yash Malviya

CONCLUSION - CLASS STRING AND STREAM PROCESSING WERE SUCCESSFULLY STUDIED AND IMPLEMENTED...
*/