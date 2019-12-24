#ifndef _HEAP
#define _HEAP

#include "Patient.h"

#include <iostream> //Need in order to use string as a parameter
using namespace std; //Need in order to use string as a parameter

class Heap
{
    private:
        Patient *patients = new string[20];

        int numberOfNodes;

    public:
        Heap();
        bool isEmpty()
        {return numberOfNodes == 0;};

        int getNumberOfNodes()
        {return numberOfNodes;};

        bool add(string newData);

        string peekTop();

        void heapRebuild(int root, int itemCount);

        bool remove();

};

#endif