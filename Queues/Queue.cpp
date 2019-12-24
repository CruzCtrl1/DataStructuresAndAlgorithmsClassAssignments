/*
Implement a circular array-based queue of char entries in C++ based on the following
class definition. Enqueue/dequeue should use count to return false if the queue is
full/empty respectively

    private:
        char entries[MAX_QUEUE];

        int front;
        int back;
        int count;
    private:
        Queue()
            {front = 0; back = MAX_QUEUE - 1; count = 0;};
        bool enqueue(char newEntry);
        bool dequeue();
        char peek();
        bool isEmpty();   
*/

#include "Queue.h"
#include "PrecondViolatedExcep.h"

#include <iostream>
using namespace std;

bool Queue::enqueue(char newEntry)
{
    if(count == maxQueue)
    {
        throw PrecondViolatedExcep("Enqueue() called with a full queue.");
    }
    else
    {
        back = (back + 1) % maxQueue;
        entries[back] = newEntry;
        count++;
        return true;
    }
}

bool Queue::dequeue()
{
    if(isEmpty())
    {
        throw PrecondViolatedExcep("dequeue() called with empty queue.");
    }
    front = front + 1 % maxQueue;
    count --;
    return true;
}

char Queue::peek()
{
    return entries[front];
}

bool Queue::isEmpty()
{
    return count == 0;
}