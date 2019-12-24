/*
How to implement:
Utilize an array to store each character in the string.

Read from back utilizing stack (peek)
peek the queue (front)
    Compare both. If same, continue till isEmpty
        If is empty, true
    If has a contradiction, break and return not palindrome.
*/

#include "PrecondViolatedExcep.h"
#include "Queue.h"
#include "Stack.h"

#include <iostream>
using namespace std;

bool palindrome();

int main ()
{
    if(palindrome())
    {
        cout << "Your input was a palindrome!\n";
    }
    else
    {
        cout << "Your input was not a palindrome!\n";
    }
    return 0;
}

bool palindrome()
{
    string input;
    cout << "Please enter a string to test if a palindrome: ";
    cin >> input;

    int inputSize = input.size();

    Queue queue(inputSize);
    Stack stack(inputSize);

    char queueStackCh; //For obtaining char for the stack and queue

    for(int i = 0; i < inputSize; i++)
    {
        char queueStackCh = input[i];
        queue.enqueue(queueStackCh);
        stack.push(queueStackCh);
        //When reading from stack, will read last entered
        //With queue, will read first entered. Therefore,
        //dont need extra char
    }

    bool isPalindrome = true;

    while(!stack.isEmpty() && !queue.isEmpty())
    {
        char queueCheck = queue.peek();

        if(queueCheck == stack.peek())
        {
            stack.pop();
            queue.dequeue();
            queueCheck = queue.peek();
        }
        else
        {
            isPalindrome = false;
            return isPalindrome;
        }
    }

    return isPalindrome;
}