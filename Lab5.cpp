// The word stack and array are used interchangeably. I'm aware of what a stack and what an array is. The array is being used to display the functionality of a stack.

#include <iostream> 
#include <string> 
#include <exception> 

using namespace std;

const int SIZE = 20;

class Stack
{
private:
    int top;                            // Keeps record of the top of the stack
    string data[SIZE];                  // The stack itself
public:
    Stack();                            // Constructor
    Stack(Stack* stack);
    void push(string newData);          // Add a stack frame
    void pop(string& oldData);          // Remove a stack frame
    bool isEmpty();                     // Will remove items from the stack until it's empty
    bool isFull();                      // Check to see if stack is full before entering new data
    void displayStack();                // Display contents of the stack
    void displayStackReverse();         // Displays the stack in reverse
    void displayN(int n);               // Displays the item on the Nth position
    int GetLength();                    // Return the length of the stack
    int countData(string searchString); // Counts the number of times a string has occurred
    int findtData(string searchString); // Finds a strings location
    bool allSame();                     // Checks to see if the contents of a stack are the same
    void copyStack(Stack* newStack);    // Copies the contents of one stack into another
};

// pushes data onto the stack, increments top. 
// input: string newData. The data to be pushed onto the top of the stack. 
void Stack::push(string newData)
{
    if (!isFull())
    {
        data[top] = newData;
        ++top;
    }
    else
    {
        cout << "stack full" << endl;
    }
}

// pops data from the stack, decrements top. 
// output: string &newData (reference parameter). The data to be popped from the top of the stack. 
void Stack::pop(string& oldData)
{
    if (!isEmpty())
    {
        --top;
        oldData = data[top];
    }
    else
    {
        cout << "stack empty" << endl;
        oldData = "";
    }
}

// Exercise 9: constructors - set up the stack. Set top of the stack to 0. 
Stack::Stack()
{
    top = 0;
}

// Exercise 11: starting thinking about copy constructors 
Stack::Stack(Stack* stack)
{
    // Complete at a later date
}

// Checks to see whether the array is full. 
// Returns: true if the array is full, false if the array is not full. 
bool Stack::isFull()
{
    if (top >= SIZE)
    {
        return true;
    }
    return false;
}

// Checks to see whether the array is empty. 
// Returns: true if the array is empty, false if the array is not empty. 
bool Stack::isEmpty()
{
    if (top <= 0)
    {
        return true;
    }
    return false;
}

// Displays all of the items currently on the stack in order from the bottom of the stack 
// to the top of the stack. 
void Stack::displayStack()
{
    for (int i = 0; i < top; ++i)
    {
        cout << data[i] << endl;
    }
}

// Exercise 2: write a getLength function - returns the top value
int Stack::GetLength()
{
    return top;
}

// Exercise 3: displaying the stack in reverse order - displays in order from the top to bottom 
void Stack::displayStackReverse()
{
    for (int i = top - 1; i >= 0; --i)
    {
        cout << data[i] << endl;
    }
}

// Exercise 4: countData - Counts the number times a given string can be found in the stack
int Stack::countData(string searchString)
{
    int result = 0;
    for (int i = 0; i < top; i++)
    {
        if (data[i] == searchString)
        {
            result++;
        }
    }
    return result;
}

// Exercise 5: findData - finds the first occurrence of a given string
int Stack::findtData(string searchString)
{
    int result = -1;
    bool found = false;
    int i = 0;
    while (i < top && !found)
    {
        if (data[i] == searchString)
        {
            found = true;
            result = i;
        }
        i++; // increment i 
    }
    return result;;
}

// Exercise 6: display nth element - Displays data at the Nth index
void Stack::displayN(int n)
{
    if (n >= 0 && n < top) cout << data[n];
    else                          cout << "Out of bounds" << endl;
}

// Exercise 8: all the same... - Returns true if all the items on the stack are the same
bool Stack::allSame()
{
    for (int i = 0; i < top - 1; i++)
    {
        if (data[i] != data[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Exercise 10: a copy function - makes a new stack the exact 
void Stack::copyStack(Stack* newStack)
{
    newStack = new Stack;
}

int main()
{
    Stack* myStack = new Stack;

    myStack->push("purple");
    myStack->push("purple");
    myStack->push("purple");
    myStack->push("purple");
    myStack->push("purple");
    myStack->push("purple");

    myStack->displayStack();
    cout << endl;

    myStack->displayStackReverse();
    cout << endl;

    cout << "Size of stack:" << myStack->GetLength() << endl;
    cout << "First Purple Occurrence:" << myStack->findtData("purple") << endl;
    cout << "Find Purple Instances: " << myStack->countData("purple") << endl;
    cout << "Data at position 3: ";

    myStack->displayN(3);
    cout << endl;

    if (myStack->allSame()) cout << "All elements are the same in the stack" << endl;
    else                    cout << "All elements not the same in the stack" << endl;
    cout << endl;

    string storedData; // First in last out 
    myStack->pop(storedData);
    cout << "popped: " << storedData << endl; // blue 
    myStack->pop(storedData);
    cout << "popped: " << storedData << endl; // green 
    myStack->pop(storedData);
    cout << "popped: " << storedData << endl; // red 
    cout << endl << "Size of stack:" << myStack->GetLength() << endl << endl;

    delete (myStack);
    system("pause");
}