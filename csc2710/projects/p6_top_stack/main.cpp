/*
 Name: Alexander Sims
 Date: November 18, 2016
 Class: CSC2710-01
 Location: ~/asims/csc2710/projects/p6_top_stack/main.cpp
 Comment: Program is designed and implemented that prints out vertices
  of a directed graph in a topological order. 
 Format of Input: 
  - How many sets of data is needed
  - List of ordered pairs of characters
  - First line tells you the number of edges and vertices
 Format of Output:
  - Displays the vertices in a Topological Order.
 To Compile: g++ -Wall main.cpp -o start
  - We are assuming the input data is stored in a file named "input", to
    execute.
  - The program using I/O redirection where the output goes to the display.
       ./start < input
  - Executing the program using I/O redirection, the output is captued in other 
    file
       ./start < input > results
  - To see the output either edit or cat the file.
       vi results 
    or 
       cat results
===============================================================================
 */
//headers
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators
#include <climits>   // macro defines min & max values for int
#include "graph.h"   // stack
using namespace std; // container

int main (void) // main
{
   int sets,ecnt,ncnt;
   char from,to;

   cin>>sets;   // how many sets
   for (int key=0; key<sets; key++) {
      cin>>ecnt>>ncnt;
      Graph<char> F(ncnt); 
      // amount of verticies in F
      for (int i=0; i<ecnt; i++) {
         cin>>from>>to;
         F.AddEdge(from,to);
      }
      cout<<"\nTopologicalOrder: "<<endl;
      F.TopologicalOrder();
      // outputs topological order
   }  // if more than 1 set
   return 0;
}  // exit main

//==================== End of Program =================================>
