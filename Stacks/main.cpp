#include "Calculator.h"  // Header file
#include <iostream>
using namespace std;



int main()
{
    Calculator stack(5);
    Calculator postFixExp(10);

    string toCalculate = "(2+3)-4";
    
    //To put the string into postfix format
    for(int i = 0; i < toCalculate.size(); i++)
    {
        cout << "begin for loop iteration " << i + 1 << endl;
        char entry = toCalculate[i];
        if(isdigit(entry))
        {
            postFixExp.top++;
            postFixExp.push(entry);
        }
        //If you encounter '('
        else if (entry == '(')
        {
            stack.top++;
            stack.push(entry);
        }
        //If you encounter an operator
        else if(entry == '+' || entry == '-' || entry == '*' || entry == '/')
        {
            //If the stack is empty
            if(stack.itemCount == 0)
            {
                stack.top++;
                stack.push(entry);
            }
            else
            {
                if((stack.peek() == '+' || stack.peek() == '-' || stack.peek() == '*' || 
                    stack.peek() == '/') && stack.peek() >= entry)
                {
                    postFixExp.top++;
                    postFixExp.push(stack.peek()); //Appends the operator to end of stack
                    stack.pop(); //Essentially "pops" the operator from stack
        
                    while(stack.peek() != '(' || (!(stack.peek() < entry) && 
                    (stack.peek() == '+' || stack.peek() == '-' || stack.peek() == '*'
                    || stack.peek() == '/')))
                    {
                        postFixExp.top++;
                        postFixExp.push(stack.peek()); //Appends the operator to end of stack
                        stack.pop(); //Essentially "pops" the operator from stack
                    }
                }
                else
                {
                    stack.top++;
                    stack.push(entry);                   
                }
                
            }      
        }
        else if(entry == ')')
        {
            //cout << "Entering if entry == )" << endl;
            //int i = 1;

            while(stack.peek() != '(')
            {  
                        //cout << "Iteration " << i << endl;
                        postFixExp.top++;
                        //cout << "This is being put into postFix " << stack.peek() << endl;
                        postFixExp.push(stack.peek()); //Appends the operator to end of stack
                        stack.pop(); //Essentially "pops" the operator from stack     
                        //i++;
            }
            stack.pop(); //To pop off the '('
        }
        else //If we encounter the end of the string
        {
            for(int i = 0; i < stack.top; i++)
            {
                postFixExp.top++;
                postFixExp.push(stack.peek()); //Appends the operator to end of stack
                stack.pop(); //Essentially "pops" the operator from stack                   
            }
        }

        //To debug:
        /*
        cout << "This is iteration " << i + 1 << " of the for loop\n";
        cout << "Here is the top of the stack: " << stack.peek() << endl;
        cout << "Here is the top of the postfixexp: " << postFixExp.peek() << endl;
        cout << "Here is the stack itemCount: " << stack.itemCount << endl;
        cout << "Here is the postFix itemCount: " << postFixExp.itemCount << endl;
        */
    }

    //More debugging
    /*
    cout << "Here is my postFixExp: ";
    int postCount = postFixExp.itemCount;
    for(int i = 0; i < postCount; i++)
    {
        cout << postFixExp.peek();
        postFixExp.pop();
    }

    cout << "Here is my stack: ";
    int stackCount = stack.itemCount;
    for(int i = 0; i < stackCount; i++)
    {
        cout << stack.peek();
        stack.pop();
    }

    cout << endl;
    */

    return 0;
}


//Debugging:
//Print out everyting

//Rubber duck

//Problem with: combining my stack and postfix!