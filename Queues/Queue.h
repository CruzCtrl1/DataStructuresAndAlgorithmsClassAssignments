#ifndef _QUEUE
#define _QUEUE


class Queue
{
    private:
        char entries[100];

        int front;
        int back;
        int count;
        int maxQueue;
    public:
        Queue()
            {front = 0; back = 0; count = 0;};
        Queue(const int numElem)
            {front = 0; maxQueue = numElem; back = maxQueue - 1; 
            count = 0;}
            //Had maxQueue last. Made dequeue not work
        bool enqueue(char newEntry);
        bool dequeue();
        char peek();
        bool isEmpty();
};

#endif