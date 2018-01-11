/*
 * Name: Alex Sims
 * Date: September 5, 2016
 * Class: CSC-2710 - Algorithms
 * Location: ~/csc2710/projects/p1_quicksort/sort.cpp
 *
 * Comment: Program #1, loads the first, last names and ages with 
 * seperated spaces into an array, which sorts in ascending order; 
 * then finally prints them out in a neat format.
 *        first - A first name, first letter uppercase 
 *        last  - A Last name, first letter uppercase
 *        age   - The persons age, any number
 *        (spaces in between each element: "example: Alex Sims 34")
 *
 * To Compile:
 *   
 *       g++ sort.cpp -0 sort
 *
 * To execute the program using I/O redirection where the output
 * goes to the display
 *
 *       sort < data
 *
 * To execute the program using I/O redirection where the output
 * is captured in another file:
 *
 *       sort < data > results
 *
 * To see the output either edit or cat the file
 *
 *       vi results
 * or
 *       cat results
 */
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators

using namespace std; // container

// struct definition for nameType
typedef struct nameType 
{
      string first;
      string last;  
      int age;
} *ptr;
// // changing the data to be a pointer to nameType

// Prototypes
void load(ptr [], int &, int SET);
void print(ptr [], int);
void partition (ptr [], int low, int high, int&);
void quicksort(ptr [], int low, int high);
void exchange(ptr &a, ptr &b);

int main(void) // main
{
   ptr name[100000];  // space
   int n;

   cout << "==============================\n";
   cout << "[:> "; // color formatting
   cout << "\033[35m" << "L" << "\033[0m" << "\033[34m" << "O" << "\033[0m"
        << "\033[33m" << "A" << "\033[0m" << "\033[32m" << "D" << "\033[0m"
        << "\033[31m" << "I" << "\033[0m" << "\033[37m" << "N" << "\033[0m"
        << "\033[33m" << "G" << "\033[0m" << " "
        << "\033[34m" << "T" << "\033[0m" << "\033[35m" << "H" << "\033[0m"
        << "\033[36m" << "E" << "\033[0m" << " "
        << "\033[34m" << "D" << "\033[0m" << "\033[31m" << "A" << "\033[0m"
        << "\033[32m" << "T" << "\033[0m" << "\033[36m" << "A" << "\033[0m\n"; 
   cout << "==============================\n\n";

   load(name, n, 100000);
   quicksort(name, 0, n-1);
   print(name, n);

   if (name != 0)
     cout << "[:> Exit Program..." << "\033[32m" <<" ok "<< "\033[0m" << endl;
   else 
     cout << "\033[31m" <<"[:> FAILED "<< "\033[0m" << endl;

   return 0; 
}  // exit main

// Function: load - reads in all data from file using I/O redirection
// Pre-condition: names[] - array of pointers.
//                SET - max number of first, last, and ages to be stored. 
//                No pointers stored in the array
//                n - starts unknown
//
// Post-condition: names[] - loaded with pointers of all first, last, and 
//                 ages info.
//                 n <= SET - this will be set to known names processed. 
//                 
void load(ptr names[], int &n, int SET)
{
   n = 0;             
   int age;
   string first, last;  // names in the array to be stored

   while(n < SET and cin >> first) {
      // if first can be read we will assume the first, last
      // and age are available
      cin >> last >> age;
      // reads in last and age
      names[n] = new nameType; // allocation
      names[n]->first = first;
      names[n]->last = last;
      names[n]->age = age;
      n++;
   }
}

// Function: print - outputs to screen of all first, last names and ages,
// output to a file is obtained Using file using I/O redirection.
// Pre-condition: names[] is loaded with n pointers to first and last info
//
// Post-condition: Nothing to be returned
//
void print(ptr names[], int n)
{
   for(int i = 0; i < n; i++)
      cout << "    " << names[i]->last << "" << ", " // three spaces
           << names[i]->first << " " << "- "
           << names[i]->age << " " << endl;
    cout << endl;
}

// Function: partition - Partitions the array of names for quicksort
// Pre-condition: checks and re-arranges elements in the array first to last
//
// Post-condition: elements move to the left is lower than pivot, assign
//                 sorts names based on last names, if last names line up the same
//                 it looks at the first names and sorts in ascending order
//                 exchanges elements in the array
//
void partition (ptr names[], int low, int high, int& pivotpoint)
{
   int i, j;
   string partition;   
   partition = names[low]->last;
   j = low;

   for (i = low + 1; i <= high; i++)
      if (names[i]->last == partition and names[i]->first < names[low]->first) {
         j++;
         exchange(names[j], names[i]);
      }
      else if (names[i]->last < partition) {
         j++;
         exchange(names[i], names[j]);
      }
   pivotpoint = j;
   exchange(names[low], names[pivotpoint]);
   // moves pivotpoint to low by swaping them
}

// Function: quicksort - Sorts n pointers in nondecreasing order.
// Pre-condition: if high is more than low
//
// Post-condition: calls in partition if statement is true
//                 calls a recursive function of quicksort 
//
void quicksort(ptr names[], int low, int high)
{
   int pivot;
   if (high > low) {
      partition(names, low, high, pivot);
      quicksort(names, low, pivot - 1);
      quicksort(names, pivot + 1, high);
   }
}

// Function: exchange - exchange two ptr pointers
// Pre-condition: References to two pointer type are provided
//                currently are references to array elements
//
// Post-condition: values of the two pointers are being exchanged 
//
void exchange(ptr &a, ptr &b)
{
   ptr tmp;
   tmp = a;
   a = b;
   b = tmp;
}
