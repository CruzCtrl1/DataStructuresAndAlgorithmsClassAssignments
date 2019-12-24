#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

class StackInterface
{
    //Don't need parenthesis for public!
    public:
        virtual bool isEmpty() const = 0;
        virtual bool push(const char entry) = 0;
        virtual bool pop() = 0;
        virtual char peek() const= 0;
};

#endif