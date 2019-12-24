#ifndef _STACK
#define _STACK

#include "StackInterface.h"
#include "PrecondViolatedExcep.h"

class Stack: public StackInterface
{
    private:
        char stack[100]; //The stack that will hold all the operators

        int itemCount;
        int max_stack;
        int top; //Starts at -1 index

    public:
        Stack()
            {top = -1;};
        Stack(const int numElem)
            {top = -1; itemCount = 0; max_stack = numElem;};
        bool isEmpty() const;
        bool push(const char entry);
        bool pop();
        char peek() const;
};

#endif