//Q8a
#include <iostream>
using namespace std;
void divide(double x, double y)
{
    cout << "Inside function \n";
    try
    {
        if (y == 0.0)
            throw y;
        else
            cout << "Division = " << x / y << endl;
    }
    catch (double)
    {
        cout << "Caught double inside function \n";
        throw;
    }
    cout << "End of function \n\n";
}
int main()
{
    cout << "Inisde main\n";
    try
    {
        divide(10.5, 2.0);
        divide(2.0, 0.0);
    }
    catch (double)
    {
        cout << "Caught double inside main function \n";
    }
    cout << "End of main\n";
    return 0;
}
/*
OUTPUT :
Inisde main
Inside function 
Division = 5.25
End of function 

Inside function 
Caught double inside function 
Caught double inside main function 
End of main
*/