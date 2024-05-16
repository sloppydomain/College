// //Q7b
// #include <iostream>
// #include <string>
// #include <iomanip>
// using namespace std;
// ostream &line(ostream &output)
// {
//     output << setfill(' ') << setw(31) <<""<< setfill(' ') << endl;
//     return output;
// }
// ostream &lhs(ostream &out)
// {
//     out << left << setw(20);
//     return out;
// }
// ostream &rhs(ostream &out)
// {
//     out << right << setw(10);
//     return out;
// }
// int main()
// {
//     string input;
//     int numLines = 0;
//     int numWords = 0;
//     int numChars = 0;

//     cout << "Enter text (Ctrl+Z/Ctrl+D then Enter to end input):\n";

//     while (getline(cin, input))
//     {
//         numLines++;
//         numChars += input.length();
//         bool inWord = false;
//         for (char c : input)
//         {
//             if (c == ' ' || c == '\t')
//             {
//                 inWord = false;
//             }
//             else if (!inWord)
//             {
//                 inWord = true;
//                 numWords++;
//             }
//         }
//     }

//     cout << line << lhs << "Number of lines:" << rhs << numLines << endl;
//     cout << lhs << "Number of words:" << rhs << numWords << endl;
//     cout << lhs << "Number of characters:" << rhs << setw(9) << numChars << endl;
//     cout << line;
//     return 0;
// }
/*
OUTPUT - Enter text (Ctrl+Z/Ctrl+D then Enter to end input):
BHDSAB JDBJLA  ISPOQWWSOQ OQLSKQIJ
^Z

Number of lines:             1
Number of words:             4
Number of characters:       34
*/







// #include <iostream>
// #include <string>
// #include <iomanip>
// using namespace std;

// int main()
// {
//     string s = "";
//     int wordCount = 0, lineCount = 0, charCount = 0;
//     int i = 0;
//     // press ctrl + z for windows to finish input
//     cout << "Enter the text: \n";
//     while (getline(cin, s))
//     {
//         lineCount++;
//         charCount += s.length();
//         i = 0;
//         while (i < s.length())
//         {
//             while (i < s.length() && (s[i] == ' '))
//             {
//                 i++;
//             }
//             if (s[i] == '\n')
//                 break;
//             if (i < s.length())
//             {
//                 wordCount++;
//                 while (i < s.length() && s[i] != ' ')
//                 {
//                     i++;
//                 }
//             }
//             if (s[i] == '\n')
//                 break;
//         }
//     }

//     cout << "Number of words: " << setw(20) << wordCount << endl;
//     cout << "Number of characters: " << setw(15) << charCount << endl;
//     cout << "Number of lines: " << setw(20) << lineCount << endl;
//     return 0;
// }