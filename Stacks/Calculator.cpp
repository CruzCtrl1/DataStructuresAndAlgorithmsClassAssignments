#include "Calculator.h"  // Header file
#include <iostream>
using namespace std;

Calculator::Calculator()
{
    top = -1;
}

Calculator::Calculator(const int numElem)
{
    top = -1;
    max_stack = numElem;
}

bool Calculator::isEmpty() const
{
    return itemCount == 0;
}

bool Calculator::push(const char entry)
{
    bool success = false;
    if(itemCount == max_stack)
    {
        cout << "Error: Stack is full.\n";
        return success;
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
   
bool Calculator::pop()
{
    bool success = false;
    if(isEmpty())
    {
        cout << "Stack is already empty.\n";
        return success;
    }
    else
    {
        top--;
        success = true;
        itemCount--;
        return success;
    }
    
}

char Calculator::peek() const
{
    return stack[top];
    
}
