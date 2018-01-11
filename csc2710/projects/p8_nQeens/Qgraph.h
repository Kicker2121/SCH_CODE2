/* 
 * Name: Alexander Sims
 * Date: December 12, 2016  
 * Class: CSC2710-01
 * Location: ~/asims/csc2710/projects/p8_queens/Qgraph.h
 */
// headers
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators
#include <limits.h>
#include <climits>   // macro defines min & max values for int
#include <cmath>     // math stuff
#include <cstdlib>
using namespace std; // container

#ifndef GRAPH
#define GRAPH

// class Graph
class Graph 
{
private:
   int n;         // dimensions
   int max;       // max value
   int value;     // current value being set
   int *q;        // check for col
   char **spaces; // stores the board
public:
   // constructor
   Graph(const int newl=0):n(newl)
   {  // memory allocation
      spaces = new char*[n];
      for (int i=0; i<n; i++) {
         q = new int[n];
         spaces[i] = new char[n];

         for (int j=0; j<n; j++) {
            q[i]=0;
            spaces[i][j]=0;
         }
      }
   }  // exit constructor


   // deconstructor
   ~Graph()
   {  
      delete []q;
      delete []spaces;
   }  // exit deconstructor


   // Function: loads the board with the input
   // Pre-condition:  loads the board
   // Post-condition: returns nothing
   //
   void load(void)
   {
      for (int i=0; i<n; i++) 
         for (int j=0; j<n; j++)
            cin>>spaces[i][j];   // loading the board
   }  // exit load


   // Loads the columns with information
   void load_columns(void)
   {
      for (int i=0; i<n; i++)
         for (int j=0; j<n; j++)
            q[i+1] = spaces[i][j];
   }  // exit load_columns


   // Function: print - displays board with unused space, queens and barriers
   // Pre-condition: displays where queens and barriers go
   // Post-condition: returns nothing
   //
   void print()
   {
      static int count=0;
      count++;
      cout<<"\nSolution: "<<count<<endl;
      for (int i=0; i<n; i++) {      	 
         spaces[q[i]][i]='Q';
      }
      for(int i=0; i<n; i++) {
         for(int j=0; j<n; j++)
            cout<<spaces[i][j];
         cout<<endl;
      }
      cout<<endl; 
   }  // exit print


   // Function: nQueens - Position n queens on a chessboard for that no two
   //           are in the same row, column, or diagonal.
   // Pre-condition: Positive integer n
   // Post-condition: All possible ways n queens can be placed on a n by n
   //            chessboard so that no two queens threaten each other. Each
   //            output consists of an array of integers col indexed from 1
   //            to n, where col[i] is the column where the queen in the ith
   //            row is placed
   //
   int nQueens(int col)
   {
      //continue only if columns 0 through i are promising
      bool flag=false;
      int i,j;
      if (col >= n) {
         flag = true;
         for (i=0; i<n; i++) {
            if(isSafe(i, col) == true) {
               spaces[i][col] = 'Q';         // add queen
               flag = true;
               q[i+1]=j;
               nQueens(i+1);
               spaces[i][col] = '.';        // delete queen
            }
         }
      } else {
            // if all queens cannot be positioned
            cout<<"no solution"<<endl;   
            flag = false;
      }
      return flag;
   }  // exit queens


   // Function: promising - Checks where queen can be placed 
   // Pre-condition: checks if the situation is true and if queen can be placed
   //                in certain areas that are no connected to another or prev.
   // Post-condition: returns check for queen function
   //
   bool promising(int row, int col)
   {  
      // check if any queen threatens
      // queen in the ith row.
      int i,j;
      for (i=0; i<n; i++) { // check for column and row being safe
         if (spaces[i][col] and spaces[row][i])
            return false;   // threatens, fail   
      }
      for (i=row,j=col; i>=0 and j>=0; i--,j--) {
         if(spaces[i][j])        
            return false;   // threatens, fail
      }
      for (i=row,j=col; i<n and j>=0; i++,j--) {
         if(spaces[i][j])
            return false;   // threatens, fail
      }                     // doesn't threaten, approve true
      return true;          // returns failed/approve promising
   }  // exit promising

   
   // Function: isSafe - returns when checks are true
   bool isSafe(int row, int col) 
   {
      bool AllSafe = promising(row,col);
      return AllSafe;
   }  // exit isSafe
};

#endif
//=========================== End of Program ===============================>
