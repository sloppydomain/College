#include <iostream>
using namespace std;
int main()
{
    int rows, columns, i, j, t;
    cout << "Enter the rows : ";
    cin >> rows;
    cout << "Enter the columns : ";
    cin >> columns;
    if (rows != columns)
    {
        cout << "Matrix is not a square matrix\n";
        return 0;
    }
    else
    {
        int arr[rows][columns];
        cout<<"Enter the elements of Matrix : "<<endl;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < columns; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << "Matrix before interchanging diagonal elements : " << endl;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < columns; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        for (i = 0; i < rows; i++)
        {
            t = arr[i][rows - i - 1];
            arr[i][rows - i - 1] = arr[i][i];
            arr[i][i] = t;
        }
        cout << "Matrix after interchanging diagonal elements : " << endl;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < columns; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
}