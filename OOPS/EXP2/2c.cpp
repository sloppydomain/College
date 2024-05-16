#include <iostream>
#include <math.h>
#define PI 4.0 * atan(1.0)
using namespace std;
class Area
{
public:
    void get_data();
    void area(double r);
    void area(double l, double b);
    void area(float b, float h);
};
void Area::area(double r)
{
    double area = PI * r * r;
    cout << "\n\nArea of circle is " << area << "\n";
}
void Area::area(double l, double b)
{
    double area = l * b;
    cout << "Area of rectangle is " << area << "\n";
}
void Area::area(float b, float h)
{
    double area = b * h * 0.5;
    cout << "Area of triangle is " << area << "\n";
}
int main()
{
    double r, l, b;
    float base, height;
    cout << "Enter radius of circle : ";
    cin >> r;
    cout << "\n\nEnter length of rectangle : ";
    cin >> l;
    cout << "Enter breadth of rectangle : ";
    cin >> b;
    cout << "\n\nEnter base of triangle : ";
    cin >> base;
    cout << "Enter height of triangle : ";
    cin >> height;
    Area a;
    a.area(r);
    a.area(l, b);
    a.area(base, height);
    return 0;
}