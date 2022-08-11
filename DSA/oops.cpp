#include <iostream>
#include <string>
using namespace std;

class student
{
    // IF name IS PRIVATE
    string name;

public:
    // string name;
    int age;
    bool gender;

    // DEFAULT CONSTRUCTOR
    student()
    {
        cout << "Default Constructor" << endl;
    }

    ~student()
    {
        cout << "Destructor Called" << endl;
    }

    // FOR DECLARING A OBJECT OF A CLASS AT THE INITIALIZATION
    student(string s)
    {
        name = s;
    } // PARAMETERISED CONSTRUCTOR

    void printInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Gender : " << ((gender == 1) ? "Female" : "Male") << endl;
    }

    void setName(string s)
    {
        name = s;
    }

    void getName()
    {
        cout << name << endl;
    }

    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    // DECLARING THE OBJECTS OF A CLASS MANUALLY
    // student a;
    // a.name = "Rupam";
    // a.age = 20;
    // a.gender = 0;

    // MAKING A ARRAY OF OBJECTS OF A CLASS
    // int arrSize = 3;
    // student arr[arrSize];
    // for (int i = 0; i < arrSize; i++)
    // {
    //     string s;
    //     cin >> s;
    //     arr[i].setName(s);
    //     cin >> arr[i].age;
    //     cin >> arr[i].gender;
    // }

    // for (int i = 0; i < arrSize; i++)
    // {
    //     arr[i].printInfo();
    // }

    // FOR DECLARING A OBJECT OF A CLASS AT THE INITIALIZATION
    student a("Rupam");
    a.getName();

    // FOR COPYING ALL OBJECTS OF A CLASS TO ANOTHER
    student c = a;
    c.printInfo();

    if (c == a)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }

    return 0;
}