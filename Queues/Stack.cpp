#include "Stack.h"  // Header file
#include <iostream>
using namespace std;

/*
Not needed because defined in header file!

Stack::Stack()
{
}//End default constructor

Stack::Stack(const int numElem)
{
}//End constructor

*/

bool Stack::isEmpty() const
{
    return itemCount == 0;
}

bool Stack::push(const char entry)
{
    bool success = false;
    if(itemCount == max_stack)
    {        
        throw PrecondViolatedExcep("Push() called with a full stack.");
    }
    else
    {
        top++;
        stack[top] = entry;
        itemCount++;
        success = true;
        return success;
    }
}
   
bool Stack::pop()
{
    bool success = false;
    if(isEmpty())
    {
        throw PrecondViolatedExcep("Pop() called with an empty stack.");
    }
    else
    {
        top--;
        success = true;
        itemCount--;
        return success;
    }
    
}

char Stack::peek() const
{
    return stack[top];
    
}
