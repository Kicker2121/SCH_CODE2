//Header File: linkedStack.h 

#ifndef H_LinkedStackType
#define H_LinkedStackType
 
#include <iostream>
#include <cassert> 

#include "stackADT.h"

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedStackType: public stackADT<Type>
{
public:
    const linkedStackType<Type>& operator=
                              (const linkedStackType<Type>&);
      //Overload the assignment operator.

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty;
      //               otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns false.

    void initializeStack();
      //Function to initialize the stack to an empty state. 
      //Postcondition: The stack elements are removed; 
      //               stackTop = NULL;

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top 
      //               element of the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //               element is removed from the stack.

    //void pop (const Type& newItem) const;
      //Function to overload original pop function, 
      //takes the number of elements to pop in both
      //stack classes
      //

    int inspect(const Type& newItem);
      // Function takes an element of whatever type the stack
      // contains and returns that elements depth from the top
      // of the stack; consider stack depth = 0.

    void reverseStack(linkedStackType<Type> &otherStack);
      // Copies elements of this stack into otherStack in reverse order
      // In other words this stack top becomes otherStack's bottom
      // and its bottom becomes otherStack's top.  This stack is unchanged

    linkedStackType(); 
      //Default constructor
      //Postcondition: stackTop = NULL;

    linkedStackType(const linkedStackType<Type>& otherStack); 
      //Copy constructor

    ~linkedStackType();
      //Destructor
      //Postcondition: All the elements of the stack are 
      //               removed from the stack.

private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};


    //Default constructor
template <class Type> 
linkedStackType<Type>::linkedStackType()
{
    stackTop = NULL;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == NULL);
} //end isEmptyStack

template <class Type>
bool linkedStackType<Type>:: isFullStack() const
{
    return false;
} //end isFullStack

template <class Type>
void linkedStackType<Type>:: initializeStack()
{
    nodeType<Type> *temp; //pointer to delete the node

    while (stackTop != NULL)  //while there are elements in 
                              //the stack
    {
        temp = stackTop;    //set temp to point to the 
                            //current node
        stackTop = stackTop->link;  //advance stackTop to the
                                    //next node
        delete temp;    //deallocate memory occupied by temp
    }
} //end initializeStack


template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;  //pointer to create the new node

    newNode = new nodeType<Type>; //create the node

    newNode->info = newElement; //store newElement in the node
    newNode->link = stackTop; //insert newNode before stackTop
    stackTop = newNode;       //set stackTop to point to the 
                              //top node
} //end push


template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != NULL); //if stack is empty,
                              //terminate the program
    return stackTop->info;    //return the top element 
}//end top

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;   //pointer to deallocate memory

    if (stackTop != NULL)
    {
        temp = stackTop;  //set temp to point to the top node

        stackTop = stackTop->link;  //advance stackTop to the 
                                    //next node
        delete temp;    //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

// template <class Type>
// void linkedStackType<Type>::pop (const Type& newItem, Type& nextItem) const
// {
//    if (int i == 0)   // if stack is empty
//      cerr << "Cannot remove from an empty stack." << endl;
//    else
//      i--;                 // decrement to previous stack
//      newItem[i] = NULL;   // assign stack to null
   
//    int a;
//    for (a = 0; a < nextItem; a++)
//    {
//       newItem[a] = newItem[i];
//       a--;
//    }
// }

template <class Type>
int linkedStackType<Type>::inspect(const Type &newItem)
{
   int count = 0;                // count is equal to 0
   bool found = false;           // found is assigned false
  
   nodeType<Type> *current;      // declare nodeType current
   current =this-> stackTop;     // current node is pointer to stackTop

   while(current!=NULL && found!=true)    // current not equal to NULL
   {                                      // if found is false
      if(current->info == newItem)
      {
          return count;                   // return 0 (count) variable
      
      } else {
          current = current->link;        // current pointer to link
          count++;                        // increment count
      }
  
  } // exits function
  return -1;
} // ends inspect

template <class Type> 
void linkedStackType<Type>::copyStack
                     (const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack 
        stackTop = new nodeType<Type>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = NULL;  //set the link field of the
                                //node to NULL
        last = stackTop;        //set last to point to the node
        current = current->link;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != NULL)
        {
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

template <class Type>
void linkedStackType<Type>::reverseStack(linkedStackType<Type>& otherStack)
{
  nodeType<Type> *current;             // declare a nodeType

  current = stackTop;                  // pointer to point to current stack top
  while(current != NULL)               // if current is not NULL
  {
     otherStack.push(current->info);   // push current info
     current = current->link;          // current equal to pointer link

  }
}//end reverseStack

    //copy constructor
template <class Type>   
linkedStackType<Type>::linkedStackType(
                      const linkedStackType<Type>& otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}//end copy constructor

    //destructor
template <class Type> 
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}//end destructor

    //overloading the assignment operator
template <class Type>   
const linkedStackType<Type>& linkedStackType<Type>::operator=
    			  (const linkedStackType<Type>& otherStack)
{ 
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this; 
}//end operator=

#endif
