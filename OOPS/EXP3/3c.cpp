#include <iostream>
#include <cstring>
using namespace std;

class temp
{
private:
    char *p;
    int len;

public:
    temp() : p(nullptr), len(0) {}
    ~temp()
    {
        delete[] p;
    }

    temp(const char *q)
    {
        len = strlen(q);
        p = new char[len + 1];
        strcpy(p, q);
    }

    void join(const temp &a, const temp &b)
    {
        len = a.len + b.len;
        delete[] p;
        p = new char[len + 1];
        strcpy(p, a.p);
        strcat(p, b.p);
    }

    void Display()
    {
        cout << p << " ";
    }
};

int main()
{
    const char *f1 = "Goa";
    temp name1(f1), name2("College"), name3("Engineering"), s1, s2;

    s1.join(name1, name2);
    s2.join(s1, name3);

    s2.Display();

    return 0;
}
/*
OUTPUT -

GoaCollegeEngineering
*/
