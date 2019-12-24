#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap()
{
     numberOfNodes = 0;
}

bool Heap::add(string newData)
{
     if(numberOfNodes == 20)
     {
          cout << "Heap is already full!\n";
          return false;
     }

     patients[numberOfNodes] = newData;

     int newDataIndex = numberOfNodes;
     bool inPlace = false;

     while((newDataIndex > 0) && !inPlace) 
     //Don't have newDataIndex >= 0. Won't stop loop!
     {
          int parentIndex = (newDataIndex - 1) / 2;
          if(patients[newDataIndex] < patients[parentIndex])
          {
               inPlace = true;
          }
          else
          {
               swap(patients[newDataIndex], patients[parentIndex]);
               newDataIndex = parentIndex;     
          }
     }
     numberOfNodes++;
     return true;
}

//Return the root
string Heap::peekTop()
{
     return patients[0].getName();
}

void Heap::heapRebuild(int root, int itemCount)
{
     //Recursively trickle the item at index root down to its proper pos
     //by swapping it with its larger child, if child is larger than the
     //item. If the item is a leaf, nothing needs to be done

     if((2 * root + 1) < itemCount) //If the root is not a leaf
     {
          //Root must have a left child. Assume it is the larger child
          int largerChildIndex = 2 * root + 1; //left child index

          if(2 * root + 2 < itemCount) //if root has a right child
          {
               int rightChildIndex = largerChildIndex + 1;
               
               if(items[rightChildIndex] > items[largerChildIndex])
               {
                    largerChildIndex = rightChildIndex;
               }
          }

          //If the item in the root is smaller than the item in the larger
          //child, swap items
          
          if(items[root] < items[largerChildIndex])
          {
               swap(items[root], items[largerChildIndex]);

               //Transform the semiheap rooted at largerChildHeap into a heap
               heapRebuild(largerChildIndex, itemCount);
          }
     }
} //else root is a leaf, so we are done


//Removes the root, then rebuilds the heap
bool Heap::remove()
{
     if(!isEmpty())
     {
          //Copy the item from the last node into the root
          items[0] = items[numberOfNodes - 1];

          //Remove the last node
          numberOfNodes--;

          //Transform the semiheap back into a heap  
          heapRebuild(0, numberOfNodes);
          return true;
     }
     else
     {
          return false;
     }
     
}