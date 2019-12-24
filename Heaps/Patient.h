#ifndef _PATIENT
#define _PATIENT

#include "Heap.h"

#include <iostream>
using namespace std;

class Patient
{
    private:
        int priority;
        string name;

    public:
        Patient()
            {numberOfNodes = 0, name = "", priority = 0;};

        Patient(int createPriority, string createName)
            {priority = createPriority, name = createName;};

        bool isEmpty()
            {return numberOfNodes == 0;};

        bool add(string newData);

        string peekTop();

        void heapRebuild(int root, int itemCount);

        bool remove();

        string getName()
            {return name;};

        bool operator>(const Patient &);

        bool operator<(const Patient &);
};

#endif