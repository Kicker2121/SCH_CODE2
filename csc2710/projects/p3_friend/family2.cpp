/*
 * Name: Alexander Sims
 * Date: October 3, 2016
 * Class: CSC-2710 - Algorithms
 * Location: ~/csc2710/projects/p3_friend/family2.cpp
 *
 * Comment: Program #3: Loads in an inputed integer indicating how many collections 
 * to check, and another integer indicating a collection of friend relationships to 
 * display connected if collection forms a family and disconnected if they don't.
 * 
 * Format of Input:
 * [n]              - number of collections to check for
 * [m]              - how many names within the collection
 * [Here and Below] - the collection of names such as a name friends another name 
 * 
 * Format of Output:
 * First line is a integer for number of collections to check, second line is also
 * an integer for the number of names within the collection; max of 64 by 64 
 *
 * To Compile:
 *    
 *    g++ family2.cpp -o fam
 *    
 * We are assuming the input data is stored in a file named "num", to execute the 
 * program using I/O redirection where the output goes to the display.
 *    
 *    ./fam < collect
 *    
 * Executing the program using I/O redirection, the output is captued in other file
 *    
 *    ./fam < collect > results
 *    
 * To see the output either edit or cat the file.
 *    
 *    vi results 
 * or 
 *    cat results
 *********************************************************************************/
// headers
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators

using namespace std; // container

#define MAX 64       // defined space
#define INF 999

// Prototypes
void load(int, string, string, int [][MAX], int&);
void print(int&, int [][MAX]);
int seqSearch(int&, string, string [MAX]);
void floyd (int&, int [][MAX], int [][MAX]);

int main(void) // main
{
   int n, m, key, loc=0;
   int List[MAX][MAX]={INF}, D[MAX][MAX]={0};
   string name, name2;
   cin >> n; 
   for (key=0; key < n; key++) { // for more lists
      cin >> m;
      load(m, name, name2, List, loc);
      floyd(loc, List, D); 
      print(loc, D);  
   }
   return 0;
} // exit main

// Function: Load - reads in all data from file using I/O redirection 
// Pre-condition: n = number of collections to check
//                m = number of names in the collection
//                pos = return value for the position, if position is true
//                then adds name in list, increments location, stores list
// Post-condition: Loaded with first name friends second name
void load(int m, string name, string name2, int List[][MAX], int& loc)
{
   int check=0, sub=0, sub2=0, pos=0;
   string list[MAX], frnd;
   loc=0;
   for (int i=0; i<m; i++) {
      for (int j=0; j<m; j++) {
         if (i != j)
            List[i][j] = INF;
         else
            List[i][j] = 0;
      }
   }
   while (check < m) {
      cin >>name>>frnd>>name2;
      pos = seqSearch(loc, name, list);
      if (pos == -1) {
         list[loc]=name;
         sub=loc;
         loc++;     // increments
      } else {
         sub=pos;
      }  // position given to sub
      pos = seqSearch(loc, name2, list);
      if (pos == -1) {
         list[loc]=name2;
         sub2=loc;
         loc++;     // increments
      } else {
         sub2=pos;
      }  // position given to sub2
      List[sub][sub2]=1; // sets 1
      check++;
   }
} // exit load

// Function - seqSearch: checks the list to see if name is already there, 
// if found return name, else check another name
// Pre-condition:  Does not store, but checks for name in list
// Post-condition: if true, returns loc of string
//                 if false, returns the function 
int seqSearch(int& SIZE, string name, string list[MAX])
{
   bool check=false;
   int loc=0;
   while (loc < SIZE and !check) {
      if (list[loc]==name) {
         check = true;
      } else {
         loc++; // increments
      } 
   } 
   if (check==true) {
      return loc;
   } else {
      return -1;
   }
} // exit seqSearch

// Function - Floyd: to find the shortest path from a node to a node
// Pre-condition: Holds location/position and new matrix
// Post-condition: Nothing to be returned & copies matrix to another
void floyd (int& loc, int List[][MAX], int D[][MAX])
{
   for (int a=0; a < loc; a++) {
      for (int b=0; b < loc; b++) {
         D[a][b]=List[a][b];
      }  // copies matrix
   }
   for (int k=0; k < loc; k++) {
      for (int i=0; i < loc; i++) {
         for (int j=0; j < loc; j++) {
            if (D[i][k]+D[k][j]<D[i][j]) {
               D[i][j]=D[i][k]+D[k][j];
            }
         }
      }
   }
} // exit floyd

// Function - Print: Outputs to screen whether connected or disconnected 
// that are outputted to a file is obtained using file I/O redirection
// Pre-condition: Holds the location/position and check
// Post-condition: Displays connected or Disconnected based on bool check
//                 returns nothing
void print(int& loc, int List[][MAX])
{
   bool check=true;
   for (int i=0; i < loc and check; i++) {
      for (int j=0; j < loc and check; j++) {
         cout << " " << List[i][j];
         if (i != j and List[i][j] == INF) 
            check = false; 
      }
      cout << endl;	
   }
   if (check==false) {
      cout << " Disconnected\n";
   } else {
      cout << " Connected\n";
   }
} // exit print




// <----------------------- End of Program -------------------------->
