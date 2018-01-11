/****************************************************************************** 
 * Name: Alexander Sims
 * Class: CSC-2710
 * Date: 10/27/2016
 * Location: ~/asims/csc2710/projects/proj5.cpp
 * Comment: Program utilizes Kruskal's Algorithm and Disjoint Sets. 
 *
 * Format of Input:
 * - number of lists to read in
 * - number of device pairs followed by number of devices
 * - [Rest of the Lines]: Contain two devices (cities), and cost to connect
 *   the two devices
 * - If another list, then information flows beneath, like 1st list
 *
 * Format of Output: (There is one blank line between customers)
 *  - Each Customer is labeled by "Customer #:" - where the # is a number
 *  based on the order they appear, if a solution, next lines represent the
 *  device pairs followed by number of devices. The remaining line contain
 *  two device(cities) and the cost to connect the two devices. Also outputs,
 *  minimal cost and device(city pairs) need for a cycle. If no solution,
 *  then the "No Solution" message appears to the screen
 *
 * To Compile: g++ -Wall proj5.cpp -o file
 *  - We are assuming the input data is stored in a file named "input", to 
 *    execute 
 *  - The program using I/O redirection where the output goes to the display.
 *
 *    ./file < input
 *
 * Executing the program using I/O redirection, the output is captued in other 
 *   file
 *
 *   ./file < input > results
 *  
 * To see the output either edit or cat the file.
 *
 *   vi results 
 * or 
 *   cat results
 *
 * ***************************************************************************/
// headers
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators
#include <string>    // string
#include <climits>   // macro defines min & max values for int
using namespace std; // container

// defined space
#define INF 999
#define MAX 1000
#define postConf 2

// Prototypes
void load (int **, string *, int, int);
int find_insert (string *, int&, string);
bool kruskal (int *, int, int, int);
void quicksort (int *, int, int);
void setupMatrix (int ***, int);
void deleteMatrix (int **, int);
void print (int **, int, string *, int *);
// Class Prototypes
int find (int);
void unionset (int, int);

// struct
struct edgeType 
{  int u, v;
   int weight;
   bool used; 
};

// DisjointSets Class
class DisjointSets {
private:
   int *rank, *rep;
   int n;
public:
   // Function: Find - Traverse all of the link list to find an element then
   //           you can return the index of the list as a rep
   // Pre-condition: First element in the set could be the representative, 
   // Post-condition: returns a reference to the set containing i, all elements
   //                  in the set has to return same reference
   int find (int i)
   {
      int r = i;         // assume i is the representation
      while (rep[r] != -1)
         r = rep[r];
      return r;
   } // exit find

   // Function: union - Finds sets that contain u and v, call it
   // Pre-condition: If u and v are not the same set then place u or v and 
   // Post-condition: Updates the representative of u or v, by using rep pointer
   void unionset (int u, int v)
   {  //merge by rank
      int x = find(u);  // find sets
      int y = find(v);
      if (rep[u] != rep[v]) {
         if (rep[x] > rep[y]) 
            rep[v] = u;
         else 
            rep[u] = v;
      }
   } // exit unionset

   // Constructor
   DisjointSets(int n=100)
   {  // default n=100
      rep = new int[n]; // allocation
      rank = new int[n];
      for (int i=0; i<n; i++) {
         rep[i] = i;   //      set all
         rank[i] = 0;
      }
   } // exit constructor

   // Deconstructor
   ~DisjointSets()
   {
      delete []rank;
      delete []rep;
   } // exit deconstructor

}; // exit DisjointSets class

int main (void) // main
{
   int *edges, EC, VC, **w, *close, SET, n, f=1;
   string *vertices;

   cin>>SET;                      // sets of input
   for (int key=0; key<SET; key++) {
      cin>>EC>>VC;                // edges & vertices
      cin.get();                  // preparation for getline use
      setupMatrix (&w, VC); 
      vertices = new string[VC];  // array to hold vertex names
      load (w, vertices, VC, EC);
      close = new int[VC];        // the results ...

      while (f<=SET) {
         cout<<"Customer "<<f<<": \n";
         if(kruskal(edges, n, EC, VC)) {
            print (w, VC, vertices, close);
         } else { 
            cout<<"No Solution"<<endl;
         }
         f++;
         cout<<endl;
      }
      delete []close, delete []vertices;
      deleteMatrix(w, VC);
   }  // clear system
   return 0;
}  // exit main


// Function: load - Read from std-in the edges in the graph. 
// Pre-condition: adjMatrix is a 2D matrix initialized for 
//                 a set of undirected edges.  
//                 vertexcnt is the size of the 2D matrix.
//                 vertices is a 1D array of vertex names
//                 edgecnt is the number of edges to process
//                 Each undirected edge consists of a
//                 from vertex, to vertex, and a weight
// Post-condition: adhMatrix is loaded with the undirected edges.
//                  vertices are loaded with the vertex names
void load (int **adjMatrix, string *vertices, int Vcount, int Ecount)
{
   string left, right; 
   int rFrom, rTo, weight, n=0; // n ~ tracks # of vertices found 
   // reads and stores weights into adjacency matrix
   for(int i=0; i<Ecount; i++) {
      getline(cin, left,',');
      cin.get();                // gets the space
      getline(cin,right,','), cin>>weight;
      cin.get();                // gets new line char

      rFrom = find_insert(vertices, n, left); 
      rTo = find_insert(vertices, n, right); 
      adjMatrix[rFrom][rTo] = weight;
      adjMatrix[rTo][rFrom] = weight;
   }
} // exit load


// Function: find_insert - used to keep track of unique vertice names.  If 
// vertname is in vertices, then return it's position otherwise, add vertname 
// to the vertices array and return the position.  NOTE: cnt is the number of 
// elements in the zero based array.  If we add vertname and increment cnt, 
// cnt-1 will be the position of the vertname.
// Pre-condition: vertices array contains count names
//                  vertname is the name in question, 
// Post-condition: if vertname is not in vertices then vertname will be added
//                   and count will be incremented.
int find_insert (string *vertices, int &count, string Newname)
{
   for(int i=0; i<count; i++) 
      if(vertices[i] == Newname) 
         return i;
   vertices[count++] = Newname;
   return count-1;
} // exit find_insert


// Function: kruskal - Determines the minimum spanning tree
// Pre-condition: Sort the edges by cost/weight by selecting
//                 an min cost edge.
// Post-condition: A set of edges in a minimum spanning tree
//                 adds to solution if it creates a cycle
bool kruskal (int *edges, int n, int ne, int nv)
{
   int Edgecount=0, curEdge=0;
   DisjointSets var;
   edgeType *eptr;

   //edges = new int[ne];
   int F[] = {0}; // sets of edges in solution
   eptr->used = false;
   quicksort(edges, eptr->u, eptr->v); // sort elements
   while (Edgecount != (n-1) and curEdge < ne) { 
      if ((edges[ne]=var.find(eptr->u)) != (edges[nv]=var.find(eptr->v))) {   
         Edgecount++;
         var.unionset(eptr->u, eptr->v);
         eptr->used = true;
      }
      curEdge++;
   }
   if (Edgecount == (n-1)) {
      cout<<"Solution Found"<<endl;
      eptr->used = true;
   }
   return true;
} // exit kruskal


// Function: quicksort - Sorts rep pointers in nondecreasing order
// Pre-condition: checks and re-arranges elements in the array from 
//              first to last and checks if right is more than left
// Post-condition: Elements move to the left if lower than piv, and
//              sorts edges, and also exchanges elements in the array 
void quicksort (int *rank, int u, int v)
{
   int tmp, i=u, j=v, piv = rank[(u+v)/2];
   while (i<=j) {
      while (rank[i]<piv) 
         i++;
      while (rank[i]>piv)
         j--;
      if (i<=j) {
         tmp = rank[i];
         rank[i] = rank[j];
         rank[j] = tmp; // exchanger
         i++;
         j--;
      }
   }
   if (u<j) 
      quicksort(rank, u, piv-1);
   if (i<v) 
      quicksort(rank, piv+1, v);
} // exit quicksort


// Function: setupMatrix - Dynamically setup the adjaceny matrix for 
// graph problems.
// Pre-condition: adjMatrix is an undefined double pointer 
//                 needed to setup a 2D array.
//                 n is the number of nodes(or vertices)
// Post-condition: adjMatrix points to a 2D array initialized
//                  Zero's down diagonal to restrict loops on a node
//                  INF in all other connections between nodes to 
//                  indicate an impossible connection.
void setupMatrix (int ***adjMatrix, int n)
{
   *adjMatrix = new int *[n];
   for(int i=0;i<n;i++) {
      (*adjMatrix)[i] = new int[n];
      for(int j=0;j<n;j++)
         if (i!=j) 
            (*adjMatrix)[i][j] = 0;
         else 
            (*adjMatrix)[i][j] = INF;
   }
} // exit setupMatrix


// Function: deleteMatrix - Delete a 2D array of size n
// Pre-condition: adjMatrix is a 2D matrix of size n has been dynamically
//                 created, n is the size of the matrix
// Post-condition: All memory associated with adjMatrix has been deleted,
//      i.e. given back to the mem heap so that the memory can be rescued
void deleteMatrix (int **adjMatrix, int n)
{
   for(int i=0;i<n;i++) {
      delete []adjMatrix[i];
   }
   delete []adjMatrix;
} // exit setupMatrix


// Function: print - Output the vertices on the min Cost Spanning Tree 
// based on a solution found using Prim's algorith.
// Pre-condition: adjMatrix - a 2D matrix holding the weights
//                 n the number of vertices
//                 vertices - a 1D array of names of vertices
//                 closest - a 1D array found in Prims
// Post-contidion: No parameters are altered, all std-output.
void print (int **adjMatrix, int n, string *vertices, int *closest)
{
   int PFrom, PTo, weight=0, minW=0;
   for(int i=0; i<n; i++) {
      PFrom = i;
      PTo = closest[i];
      weight = adjMatrix[PFrom][PTo];
      minW += weight;
      cout<<"("<<vertices[PFrom]<<", "<<vertices[PTo]<<") "<<weight<<endl;
   }
   cout<<"Minimal Cost: "<<minW<<endl;
} // exit print


// ------------------------ End of Program #5 ------------------------------>
