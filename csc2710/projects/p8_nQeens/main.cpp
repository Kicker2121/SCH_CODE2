/*
 Name: Alexander Sims
 Date: December 12, 2016
 Class: CSC2710-01
 Location: ~/asims/csc2710/projects/p8_queen/main.cpp
 Comment: Program outputs the first solution found by the NQueens proble. A
 Queen can be hidden behind barriers or a barrier unless more than one queen
 appears in the same row. Meaning that two queens have occupied the same col
 -umn or diagonal as long as there may be at the least one barrier between 
 them. Barriers cannot protect a queen in a row.  
 
 Format of Input:
   - First line contains the number of sets / solutions
   - Next line contains how large the board is by 4x4
   - Next lines are the number of test cases to follow
 
 Format of Output:
   - Outputs the board using characters
     [-] These outputs are using .(unused-space), #(barrier), and Q(queen).
   - Outputs a blank line between solutions

 To Compile: g++ -Wall main.cpp -o file
   - We are assuming the input data is stored in a file named "input", to 
     execute 
   - The program using I/O redirection where the output goes to the display.
 
 Executing the program using I/O redirection, the output is captured in screen
   ./file < input

 Executing the program using I/O redirection, the output is captured in other 
   file
 
   ./file < input > results
   
 To see the output either edit or cat the file.
 
    vi results 
  or 
    cat results
 ****************************************************************************/

// headers
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators
#include <stdlib.h>  // standard library std::
#include "Qgraph.h"  // graph clask
using namespace std; // constainer

int main (void) // main
{
   int sets,ncnt;
   int i=0;
   cout<<"\n";
   cin>>sets;        // # of solutions
   for (int k=0; k<sets; k++) {
      cin>>ncnt;
      Graph F(ncnt);
      F.load();
      F.nQueens(i); // ehh
      F.print();
   }
   return 0;
}  // exit main



//=========================== End of Program ===============================>