#include "Person.h"

#include <iostream>
using namespace std;

//Default constructor
Person::Person()
{
    name = "";
    birthday = "";
    birthdayMonth = "";
}

//Constructor
Person::Person(string personName, string inputBirthday)
{
    name = personName;
    birthday = inputBirthday;

    string temp; //To locate the end char of the month
    int i = birthday.find(' ');

    //This stores the birthday into temp
    temp = inputBirthday.substr(0, i);

    birthdayMonth = temp;
}

bool Person::operator==(const Person &p)
{
    bool result = false;

    if(name == p.name && birthday == p.birthday)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Person::operator!=(const Person &p)
{
    bool result = false;

    if(name != p.name && birthday != p.birthday)
    {
        result = true;
    }
    return result;
}

bool Person::operator>(const Person &p)
{
    bool result = false;

    if(name > p.name)
    {
        result = true;
    }
    return result;
}

bool Person::operator<(const Person &p)
{
    bool result = false;

    if(name < p.name)
    {
        result = true;
    }
    return result;
}