//Can make sorted array based for this dictionary
//If do array based, use binary search. O(logn)

#ifndef _PERSON
#define _PERSON
#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        string birthday;
        string birthdayMonth;

    public:
        Person();

        Person(string personName, string inputBirthday);

        string getName()
        {return name;};

        string getBirthday()
        {return birthday;};

        string getBirthdayMonth()
        {return birthdayMonth;};

        //Overloading operators to support 
        //comparing different person objects
        
        bool operator==(const Person &p);
        bool operator!=(const Person &p);
        bool operator>(const Person &p);
        bool operator<(const Person &p);
};

#endif