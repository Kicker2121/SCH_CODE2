/*
 * Name: Alex Sims
 * Date: October 23, 2016
 */

#ifndef QUEUE
#define QUEUE

#include <ostream>
#include <iostream>
#include <queue>

using namespace std;

template <class T>
class Queue
{
      Queue *frontNodePtr;
      Queue *rearNodePtr;
      Queue *left, *right, *next;
   private:
      int len;  //keep up with the number of elements in the queue.
      int count;
      const int size;
   public:
      //constructor
      Queue();
    
      //destructor-must clean up dynamic stuff
      ~Queue();

      //add an element between the dummy header and the first real node in the queue
      bool enqueue(const T & item);

      //remove the item immediately after the dummy header unless empty
      bool dequeue();

      //is the "item" in the front of the queue?
      const T& peekFront();

      //is the "item" in the rear of the queue?
      const T& peekRear();

      //print all of the items.
      void print() const;

      //is the queue full? i.e. out of memory
      bool isFull() const;

      //is the queue empty?
      bool isEmpty() const;

      //add newItem to the queue
      void push(const Type& newItem);

      //to remove the top element of the queue
      void pop();

      //counts the items
      int queuecount() const;
      
      //produces level order sequence
      void levelOrder();

      //changes tree to queue
      void traverseTree ();

};

template <class T>
Queue<T>::Queue()
{
   root = NULL;
}

template <class T>
Queue<T>::~Queue()
{
   Queue *temp;
   temp = frontNodePtr;
   frontNodePtr = frontNodePtr->next;       
   delete temp;               
}     

template <class T>
bool Queue<T>::isFull () const 
{
   return false;
}

template <class T>
bool Queue<T>::isEmpty() const 
{
   return (root = 0);
}

template <class T>
int Queue<T>::queuecount() const
{
   return count;
}      

template <class T>
bool Queue<T>::enqueue(const T & item)
{
   //if (isFull())
}

template <class T>
bool Queue<T>::dequeue()
{


}

template <class T>
void Queue<T>::print() const 
{


}

template <class T>
void Queue<T>::push(const Queue& newItem)
{
   Queue<T> *newNode;
   newNode = new Queue<T>;

   newNode->frontNodePtr = newItem;
   newNode->rearNodePtr = root;
   root = newNode;
}

template <class T>
void Queue<T>::pop()
{
   Queue<T> *newNode;

   //if(root != NULL) {
      //newNode = root;
      //root = root->data;
      //delete root;
   //} else {
      cout << "Cannot remove from an empty queue." << endl;
   //}
}

//template <class T>
// Queue<T>::void LevelOrder(Node* p)
// {
//    Queue<Node*> q;

//    while(!q.isEmpty()) {
//       Node* var = frontNodePtr;
//       v->key();
//       if(v->left() != NULL) 

//    }
// }

// template <class T>
// void Queue<T>::traverseTree ()
// {
//    queue<BinaryTreeNode<T> > Levelqueue;

//    QUEUE<T> *queue;
//    queue *trans;

//    if(p->root == NULL)
//       return;

//    while(!p.isEmpty(queue))
//       trans = dequeue(queue);
//    if (trans->left != NULL)
   
//    if (trans->right != NULL)      
// }


#endif