/* 
 ===================================================================
   Name: Alex Sims
   Date: October 14, 2016
   Class: CSC-2710
   Location: ~/csc2710/projects/p4_binary/opt.cpp
   Comment: Program reads in a list of unique words provided by the input
   file also with associated probabilities, words will be in ascending order
   Using the optimal binary search tree and outputting the words in pre/in/post
   order. Also display/output the average seek time.

   Format of Input:
   - number of words
   - the words seperate by a space
   - the probabilities

   Format of Output: (each like will be seperated by a line)
   - First line is the Average Seek Time, then the words are output in 
     sequences of preorder, inorder, and postorder.

   To Compile: g++ -Wall opt.cpp -o opt

   - We are assuming the input data is stored in a file named "input", to 
     execute 
   - The program using I/O redirection where the output goes to the display.

       ./opt < input

   - Executing the program using I/O redirection, the output is captued in other 
     file

       ./opt < input > results
    
   - To see the output either edit or cat the file.

       vi results 
     or 
       cat results
 ===================================================================
 */
// headers
#include "binary.h"
#include "stdlib.h"  // standard libraries
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators
#include <algorithm> // std::min
#include <climits>   // macro defines min & max values for int
//#include "Queue_Prototype.h"
#include <vector>

using namespace std; // container

#define max 1000  // define space

// Prototypes
void optsearch(int&, const float [max], float&, int [][max]);
BinaryTree<string> tree(int, int, string [max], int [][max]);
void load(int&, string [max], float [max]);      
float sum (const float [max], int, int);

struct Node
{ 
    int data;
    Node * left;
    Node * right;
};
  
int main(void) // main
{  
   BinaryTree<string> a;
   string var[max];
   int n, R[max][max];
   float p[max], minavg;
   //queue<BinaryTree<string> >;

   cin >> n;
   load(n, var, p);
   cout << "\n Avg Seek Time: ";
   optsearch(n, p, minavg, R);
   cout << " " << minavg << endl;
   a = tree(1, n, var, R);
   cout << "\n Preorder - ";
   a.PreOutput();
   cout << "\n Inorder - ";
   a.InOutput();
   cout << endl;
   cout << " Postorder - ";
   a.PostOutput();
   cout << endl;

   return 0;
} // exit main


// Function: Load - reads in all data from file using I/O redirection 
// Pre-condition: $keys = number of unique words
//                p = the probabilities         
// Post-condition: Loaded with word w/ associated probability
void load(int& n, string keys[max], float p[max])
{
   for (int m=1; m<=n; m++) {
      cin >> keys[m];
   } 
   for (int k=1; k<=n; k++) {
      cin >> p[k];
   }
} // exit load


// Function: optsearch - Determines an optimal binary search tree for a set
//      of keys, each with associated probabilities of being the search key.
// Pre-condition: Holds number of keys, array of real numbers of p indexed
//      from 1 to n, p[i] -> probability of search for the ith key
// Post-condition: Produces the minavg search time for optimal binary search
//      tree, two-dim array R, R[i][j] is key in root of optimal tree
void optsearch(int& n, const float p[max], float& minavg, int R[][max])
{
   int i=1, j, c, ct, diagonal, var;
   float A[n+1][n], content=0.0, min=INT_MAX; 
   
   for (c=1; c<=n; c++) {
      for (ct=1; ct<=n; ct++) {
         A[c][ct] = 0.0;
         R[c][ct] = 0;
      }
   }
   while (i<=n) {
      A[i][i-1]=0; 
      A[i][i]=p[i];
      R[i][i]=i;
      R[i][i-1]=0;
      i++;
   }
   for (diagonal=1; diagonal<=n-1; diagonal++) 
      for (i=1; i<=n-diagonal; i++) {
          j=i+diagonal; 
          min=INT_MAX;
          for (int k=i; k<=j; k++) {
             content = (A[i][k-1] + A[k+1][j]);
             if (content<min) { 
                min=content;
                var=k;
             }
          }  
          A[i][j] = min+sum(p,i,j);
          R[i][j] = var;
      }
      minavg=A[1][n];
} // exit optsearch


// Function: tree - Builds an optimal binary search tree.
// Pre-condition: Holds an array key with n keys in order and number of keys
// Post-condition: Outputs a pointer tree to an optimal binary search tree 
//      containing the n keys
BinaryTree<string> tree(int i, int j, string keys[max], int R[][max])
{
   int k = R[i][j];
   BinaryTree<string>p;
   string temp;
    
   if (k==0)
      return p;
   else {
      temp = keys[k];
      BinaryTree<string>left = tree(i, k-1, keys, R);
      BinaryTree<string>right = tree(k+1, j, keys, R);
      p.MakeTree(temp, left, right);
      return p;	
   }
} // exit tree


// Function: sum - Computes the sum of all values for probabilities
// Pre-condition: Computes the sum of floats at a time
// Post-condition: Stores the floats in the given argument of sum 
//      as well as returning the sum
float sum (const float p[max], int i, int j)
{
   float count=0.0;
   for (int k=i; k<=j; k++) {
      count+=p[k];
   }
   return count;
} // exit sum


// ------------------------ End of Program ------------------------------>
