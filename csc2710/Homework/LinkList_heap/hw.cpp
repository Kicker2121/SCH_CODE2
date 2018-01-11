/* 
 * Name: Alexander Sims
 * Date: November 2, 2016
 * Location: ~/asims/csc2710/Homework/hw.cpp
 * Comment:
 */
// headers
#include <iomanip>
#include <iostream> 
#include <climits>
using namespace std; // container

// struct
typedef struct nodeType
{
    string first, next; 
    int n;
    bool used;
}*ptr;

// Class
class linkedList
{
public:
    bool isEmptyList() const;
    bool isFullList() const;
    void initializeList();
    void push();
    void pop();
    linkedList(int n=100);  
       // constructor
    ~linkedList();
       // deconstructor
private:
    nodeType *ptr; // pointer of class
    int heapSize;
    int minHeap;
};

// Prototypes
void load (ptr [], int &, int);
void print (ptr [], int &);
int equivClassOutput(ptr [], int*, int &);
void processed (ptr [], int &);


int main(void) // main
{
   ptr node[1000];
   string first;
   int n;

   load (node, n, 1000);
   //processed (node, n);
   print (node, n);

   return 0;
} // exit main


void load (ptr nodes[], int &n, int MAX)
{
   n=0;
   string first, next;
   nodeType *var;
   while (n<MAX and cin>>first) {
      cin>>next;
      nodes[n] = new nodeType;
      nodes[n]->first = first;
      nodes[n]->next = next;
      var->used = true;
      n++;
   }
} // exit load


void print (ptr nodes[], int &n)
{
   for (int i=0; i<n; i++)
      cout<<nodes[i]->first<<" ~ "<<nodes[i]->next<<endl;
} // exit print


void processed (ptr nodes[], int &n)
{
  nodeType *var;
  for (int i=0; i<n; i++)
     if (nodes[i]->first < nodes[i]->next)
        var->used = true;
} // exit processed


