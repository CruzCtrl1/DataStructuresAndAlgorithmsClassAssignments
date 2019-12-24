#include <iostream>
using namespace std;

#include "Person.h"
#include "Dictionary.h"

int main()
{
    Person entry1("Max", "June 10, 2011");
    Person entry2("Josh", "December 21, 1990");
    Person entry3("Tony", "August 23, 2005");

    Dictionary test;

    cout << "Adding 3 entries into the dictionary.";
    test.addEntry(entry1);
    test.addEntry(entry2);
    test.addEntry(entry3);

    cout << endl << "Here is the dictionary:\n";
    test.displayEveryone();
    cout << endl;

    cout << "Testing searchName with an entry in the dictionary:\n";
    string testSearch = "Josh";
    test.searchName(testSearch);
    cout << endl;

    
    cout << "Testing searchName with a person not in the dictionary:\n";
    string notPresent = "Celina";
    test.searchName(notPresent);
    cout << endl;
    
    cout << "Testing searchForMonth:\n";
    test.searchForMonth("August");
    cout << endl;

    Person notHere("Panda", "Sept 10, 2012");
    cout << "Testing removeEntry with a nonexistant entry\n";
    test.removeEntry(notHere);
    cout << endl;

    cout << "Removing " << entry1.getName() << " from dictionary." << endl;
    cout << "Here is the dictionary before the remove:\n";
    test.displayEveryone();
    cout << endl;
    test.removeEntry(entry1);
    cout << "Here is the dictionary after the remove:\n";
    test.displayEveryone();
    cout << endl;

    cout << "Removing " << entry3.getName() << " from the dictionary." << endl;
    cout << "Here is the dictionary before the remove:\n";
    test.displayEveryone();
    cout << endl;
    cout << "Here is the dictionary after the remove:\n";
    test.removeEntry(entry3);
    test.displayEveryone();
    cout << endl;

    cout << "Testing searchForMonth to print multiple entries with a December birthday month:\n";
    Person entry4("Anna", "December 5, 2019");
    Person entry5("Serena", "December 4, 2019");
    test.addEntry(entry4);
    test.addEntry(entry5);
    cout << "Added 2 more people with birthdays in December\n";
    test.searchForMonth("December");
    cout << endl;

    return 0;
}