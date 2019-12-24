#include "Dictionary.h"
#include "Person.h"

#include <iostream>
using namespace std;

Dictionary::Dictionary()
{
    numberOfEntries = 0;
}

//Adds to dictionary and puts entries in order
bool Dictionary::addEntry(Person input)
{
    bool added = false;
    if(numberOfEntries != MAX_ENTRIES)
    {
        if(numberOfEntries == 0)
        {
            //Add the person into the unsorted array dictionary
            entriesArray[numberOfEntries] = input;
            numberOfEntries++;
            added = true;
        }
        else
        {
            int greaterThanIndex = 0;

            //Keep going through the array until you find an entry
            //that is greater than the input
            while((entriesArray[greaterThanIndex] < input) && (greaterThanIndex != (numberOfEntries - 1)))
            {
                greaterThanIndex += 1;
            }

            //If after going through the loop and input is the biggest entry for the array
            if(greaterThanIndex == numberOfEntries - 1)
            {
                entriesArray[numberOfEntries] = input;
                numberOfEntries++;
                added = true;
            }
            else
            {
                //This saves the last entry in the list so it isn't deleted
                Person temp = entriesArray[numberOfEntries - 1];

                //Need to move all the elements down in the array to make space for input
                for(int i = greaterThanIndex; i < numberOfEntries - 2; i++)
                {
                    //Move entry at index i over one to the right
                    entriesArray[(i+1)] = entriesArray[i];
                }

                //Puts the last entry at the end of the array
                entriesArray[numberOfEntries] = temp;
                numberOfEntries++;

                //This puts the input in its rightful place
                entriesArray[greaterThanIndex] = input;

                added = true;
            }
        }
    }
    else
    {
        cout << "Can't add anymore! Dictionary is full!\n";
    }
    
    return added;
}

//This removes the first occurence of input in the Dictionary, if it exists
bool Dictionary::removeEntry(Person input)
{
    int index = 0;
    Person target = entriesArray[index];
    while(target != input && index != (getNumberOfEntries() - 1)) //need to make sure you update target every iteration
    {
        index++;
        target = entriesArray[index];
    }
    if(entriesArray[index] == input)
    {
        //Shift over each element by 1, overwriting the entriesArray[index]
        //and "deleting it"
        for(int i = index; i < getNumberOfEntries()-1; i++) //Dont want num - 2 because it doesn't change element 1!
        {
            entriesArray[i] = entriesArray[(i + 1)];
        }
        numberOfEntries--;
        return true;
    }
    else
    {
        cout << input.getName() << " isn't in the dictionary!\n";
        return false;
    }
}

bool Dictionary::searchName(string name)
{
    int index = binarySearch(entriesArray, 0, numberOfEntries - 1, name);
    if(index == -1)
    {
        cout << name << " is not in the dictionary!\n";
        return false;
    }
    else
    {
        cout << name << " has a birthday on " << 
             entriesArray[index].getBirthday() << endl;
        return true;
    }
}

//Display everyone in the dictionary who was born in a given month
void Dictionary::searchForMonth(string month)
{
    for(int i = 0; i < numberOfEntries; i++)
    {
        if(entriesArray[i].getBirthdayMonth() == month)
        {
            cout << entriesArray[i].getName() << " has a birthday in "
                 << month << "!\n";
        }
    }
}

//Watch the off by one error in for loop!
void Dictionary::displayEveryone()
{
    for(int i = 0; i < numberOfEntries; i++)
    {
        cout << entriesArray[i].getName() << " has a birthday on "
             << entriesArray[i].getBirthday() << endl;
    }
}

int Dictionary::binarySearch(Person array[], int start, int end, string name)
{
    if (end >= start) 
    { 
        int mid = start + (end - start) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (array[mid].getName() == name) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (array[mid].getName() > name) 
            return binarySearch(array, start, mid - 1, name); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(array, mid + 1, end, name); 
    } 
    // We reach here when element is not 
    // present in array 
    return -1;
}