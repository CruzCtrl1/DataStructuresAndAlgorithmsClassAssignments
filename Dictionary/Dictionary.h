#ifndef _DICTIONARY
#define _DICTIONARY
#include "Person.h"

#include <iostream>
using namespace std;

const int MAX_ENTRIES = 20;

class Dictionary
{
    private:
       Person entriesArray[MAX_ENTRIES];
       int numberOfEntries;

    public:
        Dictionary();

        bool addEntry(Person input);

        bool removeEntry(Person input);

        //Returns the birthday of given name
        bool searchName(string name);

        //Returns the name(s) of people in given month
        void searchForMonth(string month);

        void displayEveryone();

        int getNumberOfEntries()
        {return numberOfEntries;};

        int binarySearch(Person array[], int start, int end, string name);
};

#endif