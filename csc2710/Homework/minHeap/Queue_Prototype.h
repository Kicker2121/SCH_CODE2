template <class T>
class Queue
{
   class Node {
      public:
         T data;
         Node * next;
   };
   private:
      Node * frontNodePtr;
      Node * rearNodePtr;
      int len;  //keep up with the number of elements in the queue.
   public:
      //constructor
      Queue()
    
      //destructor-must clean up dynamic stuff
      ~Queue();

      //add an element between the dummy header and the first real node in the queue
      bool enqueue(const T & item)

      //remove the item immediately after the dummy header unless empty
      bool dequeue();

      //is the "item" in the front of the queue?
      const T& peekFront();

      //is the "item" in the rear of the queue?
      const T& peekRear();

      //print all of the items.
      void print() const;

      //is the queue full? i.e. out of memory
      inline bool isFull() const;

      //is the queue empty?
      inline bool isEmpty() const;

      //How many elements in the queue?  len keeps track of the number of
      //elements.  When an element is added, len++.  When an element is
      //removed, len--.
      inline int length() const;

   // Here is my custom iterator.  The only kind of iterator this data
   // structure can reasonably support is a forward iterator, so that's
   // what I provide.  I embedded the definition of the iterator within
   // the class it will iterate through for convenience.
   class Iterator :
      public std::iterator<std::forward_iterator_tag, T> {

      private:
         Node* curptr;
      public:
      Iterator(Node* p) : curptr(p) {}
      ~Iterator() {}

      // The assignment and relational operators are straightforward
      Iterator& operator=(const Iterator& other);
   
      bool operator==(const Iterator& other);

      bool operator!=(const Iterator& other);

      // Update my state such that I refer to the next element in the
      Iterator& operator++();

      Iterator& operator++(int);

      // Return a reference to the value in the node.  I do this instead
      // of returning by value so a caller can update the value in the
      // node directly.
      T& operator*();

      T* operator->();

   };

   Iterator begin();
   
   Iterator end();
};