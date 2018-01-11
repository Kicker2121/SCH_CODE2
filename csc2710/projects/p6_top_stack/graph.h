/* 
 * Name: Alexander Sims
 * Date: November 18, 2016  
 * Class: CSC2710-01
 * Location: ~/asims/csc2710/projects/p6_top/graph.h
 */
// headers
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators
#include <climits>   // macro defines min & max values for int
#include <limits.h>
#include <stdlib.h>  // standard library std::
#include "List.h"    // List iterator
#include "linkedStack.h"
using namespace std; // container

enum colortype {white,gray,black};
#define NIL -1       // to use colors

// Template class Graph
template <class T>
class Graph
{
private:
   int n;
   int size;             // used in find_insert
   int *count;           // in-degree for headnodes      
   colortype *color;     // white - unexplored
                         // gray, black - discovered vertices. if (u,v) and
                         // vertex u is black, then vertex v is either gray or 
                         // black, that is all vertices adjacent to black 
                         // vertices have been discovered.  Gray vertices may 
                         // have some adjacent white vertices, they represent 
                         // the frontier between discovered and undiscovered 
   int *dist;            // vertices distance from sources to vertex u            
   int *pred;            // predecessor of u
   int *dt;              // discovery time
   int *ft;              // finished time
                         // u is white before dt[u],gray between dt[u] and ft[u]
                         // and black after ft[u].
   int time;             // time
   List<int> *headnodes; // List template pointer headnodes
   T *var;               // another array to store other variables
public:
   // Constructor
   Graph(const int vertices=0):n(vertices)
   {
      headnodes = new List<int>[n]; // holds graph
      var = new T[n];               // used for find_insert 
      count = new int[n];           // used for topological ordering
      color = new colortype[n];     // colorType
      dist = new int[n];            
      pred = new int[n];
      dt = new int[n];
      ft = new int[n];
      size = 0;                     // number of vertices 
      for(int i=0; i<n; i++)        //used in topological ordering
         count[i]=0;                //count is the in-degree for a vertex.
   }  // exit constructor
  
   // Deconstructor
   ~Graph()
   {
      delete []headnodes;
      delete []var;
      delete []count;
      delete []color;
      delete []dist;
      delete []pred;
      delete []dt;
      delete []ft;
   }  // exit deconstructor

   // Function: AddEdge - adds edge <i.j> to the graph
   // Pre-condition: count[j] is tracking the in-degree of vertex j.
   //                if there is a weight on the edge, 
   // Post-condition: Then you need to modify 
   //                the item your are adding, add a struct element 
   //                that contains j and the weight.
   bool AddEdge(T i, T j)
   {
      i = find_insert(i);
      j = find_insert(j);
      // tranverse method for i.j
      count[j]++;
      return headnodes[i].add(j);
   }  // exit AddEdge
   
   // Function: TopologicalOrder - Linear ordering of vertices
   // Pre-condition: Computes the in-degree for each vertex within the stack
   //                need to have an adjList
   // Post-condition: Finds whether there is a cycle or not
   void TopologicalOrder()
   {  // stack to hold elements
      linkedStackType<int> S;
      int v;
      for (int v=0; v<n; v++) {
         if (count[v]==0)
            S.push(v);
      }
      for (int i=0; i<n; i++) {
         if(S.isEmptyStack()) {
            cerr<<"Found a cycle = no topological ordering"<<endl;
            return; // go to the next 
         }
         int u = S.top(); 
         cout << var[u] << " ";  // output proper notation of letters
         S.pop();
         typename List<int>::Iterator li = headnodes[u].begin();
         for (v = v; li != headnodes[u].end(); ++li) {
            v = *li;
            count[v]--;
            if (count[v]==0)
               S.push(v);
         }
      }
      cout<<endl;
   }  // exit TopologicalOrder

   // Function: find_insert - used to keep track of unique vertices.  If 
   // index is in vertices, then return it's position otherwise, add index 
   // to the vertices array and return the position. NOTE: cnt is the number of 
   // elements in the zero based array. If we add index and increment cnt, 
   // cnt-1 will be the position of the vertname.
   // Pre-condition: vertices array contains array of vertex's
   //                   i is the position in question, 
   // Post-condition: if vertex is not in vertices then a vertex will be added
   //                   and size will be incremented.
   int find_insert (T v)
   {
      for(int i=0; i<size; i++)
         if(var[i] == v) 
            return i;
      var[size++] = v;
      return size-1;
   }  // exit find_insert
};
// end graph class

//=========================== End of Program ===============================>
