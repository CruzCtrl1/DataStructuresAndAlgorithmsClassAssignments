#ifndef _CALCULATOR
#define _CALCULATOR

#include "StackInterface.h"

class Calculator: public StackInterface
{
    public:
        int itemCount;
        int max_stack;

        int top; //Starts at -1 index
        char stack[10]; //The stack that will hold all the operators

        Calculator();
        Calculator(const int numElem);
        bool isEmpty() const;
        bool push(const char entry);
        bool pop();
        char peek() const;
};

#endif