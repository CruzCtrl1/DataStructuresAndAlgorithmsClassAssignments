#include <iostream>
using namespace std;

void reverseNum(int n);
void writeBackward(string s);
void writeBackward2(string s);
int sumStartEnd(int start, int end);

int main()
{
    int input, reversed;
    string stringInput;

    cout << "Enter a number to reverse: ";
    cin >> input;
    reverseNum(input);
    cout << endl;

    cout << "Enter a word to reverse: ";
    cin >> stringInput;
    writeBackward(stringInput);
    writeBackward2(stringInput);
    cout << endl;

    cout << "Here is part 3: ";
    cout << sumStartEnd(3, 6);
    cout << endl;
    
    return 0;
}

void reverseNum(int n) //Recursive funtion that reverses the input
{
    int result;
    if(n == 0) //Once it has outputted the input in reverse, it does
               //nothing
    {
        return;
    }
    else
    {  
        cout << n % 10; //This gets the last digit in the input
        result = n / 10; //This gets the other digits
        reverseNum(result); //Puts the result of the division into the function,
                            //and makes a recursive call
    }
}

void writeBackward(string s)
{
    cout << "Enter writeBackward with string: " << s << endl;
    int length = s.length();
    if(length == 0) //If there are no more characters in the string object, returns nothing.
                    //This is the base case
    {
        return;
    }
    else
    {
        cout << "About to write the last character of string: " << s << endl;
        cout << s[length - 1]; //This writes the last character in the string
        cout << endl;
        writeBackward(s.substr(0, length - 1));
    }
    cout << "Leave writeBackward with string: " << s << endl;
}

void writeBackward2(string s)
{
    cout << "Enter writeBackward2 with string: " << s << endl;
    int length = s.length();
    if(length == 0)
    {
        return;
    }
    else
    {
        writeBackward2(s.substr(1, length - 1));
        cout << "About to write the first character in string: " << s 
             << endl;
        cout << s[0] << endl;
    }
    cout << "Leave writeBackward2 with string: " << s << endl;
}

int sumStartEnd(int start, int end)
{
    //base case
    if(start > end)
    {
        return 0;
    }
    else
    {
        return start + sumStartEnd(start + 1, end);
    }
}