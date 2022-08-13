#include <iostream>
using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "This is the base class's print function" << endl;
    }

    void display()
    {
        cout << "This is the base class's display function" << endl;
    }
};

class derived : public base
{
public:
    void print()
    {
        cout << "This is the derived class's print function" << endl;
    }

    void display()
    {
        cout << "This is the derived class's display function" << endl;
    }
};

class Rupam
{
public:
    void fun()
    {
        cout << " I'm a funtion with no arguments" << endl;
    }

    void fun(int x)
    {
        cout << " I'm a funtion with nint arguments" << endl;
    }

    void fun(double x)
    {
        cout << " I'm a funtion with double arguments" << endl;
    }
};

// class complex
// {
// private:
//     int real, imag;

// public:
//     complex(int r = 0, int i = 0)
//     {
//         real = r;
//         imag = i;
//     }

//     complex operator+(complex const &obj)
//     {
//         complex res;
//         res.imag = imag.obj.imag;
//         res.real = real + obj.real;
//         return res;
//     }

//     void display()
//     {
//         cout << real << " + i" << imag << endl;
//     }
// };

int main()
{
    // complex c1(12, 7), c2(6, 7);
    // complex c3 = c1 + c2;
    // c3.display();

    base *baseptr;
    derived d;
    baseptr = &d;

    baseptr->print();
    baseptr->display();

    return 0;
}