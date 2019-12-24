//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>


template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{
   headPtr = nullptr;
   tailPtr = nullptr;
   itemCount = 0;
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr); 
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

//insert(): modify it to update prev pointers as well as next pointers.  Suggestion: handle the special cases first (inserting to empty list, 
//inserting to start of list, inserting to end of list), then handle the generic case (adding to middle of list).

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  

      if(getLength() == 0) //Don't need object for getLength() unless in main!
      {
         headPtr = newNodePtr;
         tailPtr = newNodePtr;
      }

      //If user wants to insert at the start of the list
      else if(newPosition == 1)
      {
         newNodePtr->setNext(headPtr);
         headPtr->setPrev(newNodePtr);
         headPtr = newNodePtr;

      }
      else if(newPosition == (itemCount + 1)) //If user wants to place the new node at the end
                                              //Need itemCount + 1 because in ADT format
      {
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
         prevPtr->setNext(newNodePtr);
         newNodePtr->setPrev(prevPtr);
         tailPtr = newNodePtr; //Sets the prevPtr to newNodePtr's previous pointer
      }
      else
      {
         //Adding to the middle of the list
         
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1); //Points at node before newPosition
         newNodePtr->setNext(getNodeAt(newPosition));  
         prevPtr->setNext(newNodePtr);

         newNodePtr->setPrev(prevPtr);
         Node<ItemType>* nextPtr = getNodeAt(newPosition + 1); //Point to node after newPosition
         nextPtr->setPrev(newNodePtr);
         //Last node doesnt point to anything
         //MAKE A THIRD CASE FOR IF NODE IS LAST POSITION!
            //Also can do a catch all
      }
      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

/*
remove(): modify to update prev pointers as well as next pointers.
*/

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();

         curPtr = headPtr;
         headPtr->setPrev(nullptr); //Sets the new headPtr's prev ptr
                                   //to NULL to signal the end of the prev chain
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         // Get node after the one to delete. Will use for updating the prevPtr
         Node<ItemType>* followingPtr = getNodeAt(position + 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());

         // Connects the following node with the one before the indicated node
         followingPtr->setPrev(curPtr->getPrev());

      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position."; 
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAtRecursive(int position, Node<ItemType>* curPtr) const
{
   //For recursion, need a base case and recursive case
   if(position == 1)
   {
      return curPtr;
   }
   else
   {
      return curPtr = getNodeAtRecursive(position - 1, curPtr->getNext());
   }
}

template<class ItemType>
void LinkedList<ItemType>::reverse()
{
   Node<ItemType>* currentPtr = getNodeAt(1);
   Node<ItemType>* followingPtr = currentPtr->getNext();
   
   //Switch currentPtr's next and prevPtr
   for(int i = 0; i < itemCount; i++)
   {
      currentPtr->setNext(currentPtr->getPrev()); //Loses prev after this
      currentPtr->setPrev(followingPtr);
      currentPtr = followingPtr;
      if((followingPtr->getNext()) != NULL) //To ensure this doesn't go out of bounds
      {
         followingPtr = followingPtr->getNext();
      }  
   }
    
   //Switch the headPtr and tailPtr
   followingPtr = headPtr;
   headPtr = tailPtr;
   tailPtr = followingPtr;
   
   //Don't need to delete the pointers before the end of this array because still need 
   //these pointers. Also, not removing any pointers, just reversing the array
}

/*
This doesn't work

template<class ItemType>
void LinkedList<ItemType>::reverse()
{
   Node<ItemType>* tempPtr = nullptr;
   
   //Switch each nodes' next and prevPtr
   for(int i = 1; i <= itemCount; i++)
   {
      tempPtr = getNodeAt(i); //Doesnt work after the first time because chain is broken
      
      if(i == 1) // Beginning of the list
      {
         tempPtr->setNext(nullptr); //Sets it as end of next chain
         tempPtr->setPrev(getNodeAt(i+1));
      }
      else if(i == itemCount) //For at the end of the list
      {
         tempPtr->setPrev(nullptr); //Sets it as end of prev chain
         tempPtr->setNext(getNodeAt(i-1));
      }
      else
      {
         tempPtr->setPrev(getNodeAt(i + 1));
         tempPtr->setNext(getNodeAt(i - 1));
      }
      
   }
   //Switch the headPtr and tailPtr
   tempPtr = headPtr;
   headPtr = tailPtr;
   tailPtr = tempPtr;

   // Return node to system
   delete tempPtr;
   tempPtr = nullptr;
}
*/

// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;
