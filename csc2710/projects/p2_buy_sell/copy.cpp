/*
 * Name: Alex Sims
 * Date: September 28, 2016
 * Class: CSC-2710 - Algorithms
 * Location: ~/csc2710/projects/p2_buy_sell/stock.cpp
 *
 * Comment: Program #2 - loads in an inputed letter from a file that determines 
 * whether the program runs through a brute force algorithm or a divide and conquer 
 * algorithm, it then loads in the number of days, and the prices that go with
 * each day, outputs the change presented by the price & day, then outputs the
 * starting location and the ending location with the added up values that are 
 * contiguous between the start and end. Then initiates the brute force or divide 
 * and conquer. 
 *
 * Format of Input:
 * [letter of b or d] - determines the brute or/ divide - algo
 * [#]                - the n days, such as the number of days
 * [Here and Below]   - these will be price numbers between 0 and the max data set 
 * 
 * Format of Output:
 * First line is a character, second line is a int number, and the rest is the 
 * price determined by how many days. There is a maximum of 100,000,000 in the file.
 *
 * To Compile:
 *    
 *    g++ stock.cpp -o stock
 *    
 * We are assuming the input data is stored in a file named "num", to execute the 
 * program using I/O redirection where the output goes to the display.
 *    
 *    ./stock < num
 *    
 * Executing the program using I/O redirection, the output is captued in other file
 *    
 *    ./stock < num > results
 *    
 * To see the output either edit or cat the file.
 *    
 *    vi results 
 * or 
 *    cat results
 */
// headers
#include <iostream>  // defines standard input/output stream objects
#include <iomanip>   // provides parametric manipulators
#include <climits>   // macro defines min & max values for int

using namespace std; // container

// Struct definition for buyType
typedef struct buyType
{
   int price, change;
} *ptr;
// Change data to be a pointer

// Prototypes
void load (ptr [], int&, int);  
void change (ptr [], int&);
int find_sum (ptr [], int, int);
void bruteF (ptr [], int, int&);
void max_value (ptr [], int, int, int&, int&, int&);
void cross_sum (ptr [], int, int, int&, int&, int&);
void print_d (ptr [], int&, int&, int&);

#define FULL 100000 // defines space

int main(void) // main
{
   ptr buy[FULL];       // provides space for ptr
   int n, max = INT_MIN, s_loc=0, e_loc=0;
   char letter = ' ';
   cin >> letter >> n;  // reads letter and reads n for # of days
   load(buy, n, FULL);
   change(buy, n);
   if (letter == 'b') {
      bruteF(buy, n, max);
   } else if (letter == 'd') {
      max_value(buy, 1, n, max, s_loc, e_loc);
      print_d(buy, max, s_loc, e_loc);
   } else if ((letter != 'b' or letter != 'd') and (letter == ' ' or letter > 0)) {
      cout << setw(4) << "\033[31;1m" << "  [ ERROR ]\n" << "\033[0m"
         << "  Here is your letter: " << "\033[2;34m" << letter << "\033[0m"
         << endl << "  Here is your # of Days: " << n <<
         "\n  Please have the correct letter in your input file! - [b] or [d]";
      cin >> letter;
   }  cout << endl;
   return 0;
} // exit main

// Function: Load - reads in all data from file using I/O redirection
// Pre-condition:  stocks[] - array of pointers
//                 max = max number of prices
//                 n - holds days read in by file
//              
// Post-condition: stocks[] - loaded with pointers of all prices
//
void load(ptr stocks[], int &n, int max)
{
   int price;
   for (int i = 0; i <= n; i++) {  
      cin >> price;               // reads in prices
      stocks[i] = new buyType;    // allocation
      stocks[i]->price = price;
   }
} // exit load

// Function: change - calculates the difference between the right and left #'s
// Pre-condition: Holds the number of days
//
// Post-condition: Nothing to be returned
//                 stores prices to the left and the right in proper variables
//                 takes the right price minus by the left to get the change
//
void change(ptr stocks[], int& n)
{
   for (int i = 0; i < n; i++) {
      if (i != n) {
         int left = stocks[i]->price;
         int right = stocks[i+1]->price;
         stocks[i+1]->change = right - left;
      }
   }
} // exit change

// Function: find_sum - Computes the sum of all values for change
// Pre-condition: Computes the sum of integers at a time
//
// Post-condition: Stores the integers in the given argument of sum 
//                 as well as returning the sum
int find_sum(ptr stocks[], int i, int j)
{
   int sum=0;
   for (int s = i; s <= j; s++) {
      sum += stocks[s]->change;
   }
   return sum;
} // exit find_sum

// Function: bruteF - (brute force algorithm), finding all of the possible subarrays
//           by comparing their maxes into finding the maximum sum subarray
// Pre-condition: Stores sum called by the find_sum function which stores the 
//                integers if the added sum is greater than the max then max, start 
//                & ending subscripts are stored
// Post-condition: Nothing is returned, but the starting & ending subscripts & max 
//                 values are outputted to the screen using I/O redirection
//
void bruteF(ptr stocks[], int n, int& max)
{  
   int sum=0, i, j, start_loc=0, end_loc=0;
   max=0;
   for (i = 1; i < n+1; i++) {
      for (j = i; j < n+1; j++) {
         sum = find_sum(stocks, i, j);
         if (sum > max) {
            max = sum;
            start_loc = i;
            end_loc = j;      
         }
      }
   } // prints starting and ending subscripts for brute force
   cout << "\n  Left Subscript: " << "\033[35;1m" << setw(3) << start_loc  
        << "\033[0m" << "\n  Right Subscript: " << "\033[35;1m" 
        << setw(2) << end_loc << "\033[0m" << "\n  Max Value: "
        << "\033[35;1m" << setw(8) << max << "\033[0m" << endl;
} // exit bruteF
   
// Function: max_value - finds the maximum subarray, divides the array in half
//           with recursive calling, by finding the maximum integer in array
// Pre-condition: Stores the left, right, max, mid, cross, and subscripts
//                aslo holding the l_max, r_max and cross into max
// Post-condition: returns max values of integers for left and right maxes
//
void max_value(ptr stocks[], int left, int right, int& max, int& s_loc, int& e_loc)
{
   int l_max, r_max, c_max, sl_max, el_max, sr_max, er_max, sc_max, ec_max; 
   if (left < right) {
      int mid = (left+right)/2; // determines the mid point
      max_value(stocks, left, mid, l_max, sl_max, el_max);
      max_value(stocks, mid+1, right, r_max, sr_max, er_max);
      cross_sum(stocks, left, right, c_max, sc_max, ec_max); 
      max = l_max, s_loc = sl_max, e_loc = el_max;

      if (r_max > max) {
         max = r_max;
         s_loc = sr_max;
         e_loc = er_max;
      }
      if (c_max > max) {
         max = c_max;
         s_loc = sc_max;
         e_loc = ec_max;
      } 
   } else {
      max = stocks[left]->change;
      s_loc = e_loc = left;
   }
} // exit max_value

// Function: cross_sum - (divide and conquer algorithm), finds max sum subarray
// Pre-condition: Holds from the mid to the left and to the right across the mid pt
//                stores in sum of the change then equals left & right sum to sum
//                the starting and ending subscripts
// Post-condition: Returns the sum of the left and right 
//                     
void cross_sum(ptr stocks[], int left, int right, 
                             int& c_max, int& sc_max, int& ec_max)
{                            // had to shorten to print on paper               
   int left_sum = INT_MIN, right_sum = INT_MIN, sum=0;
   int mid = (left+right)/2;
   c_max=0;
   for (int i = mid; i >= left; i--) {       // moves to the left
      sum += stocks[i]->change;
      if (sum > left_sum) {
         left_sum = sum;
         sc_max = i;        
      } 
   }
   sum=0;
   for (int j = mid+1; j <= right; j++) {    // moves to the right
      sum += stocks[j]->change;       
      if (sum > right_sum) {
         right_sum = sum;
         ec_max = j;
      }
   }
   c_max = left_sum + right_sum;
} // exits cross_sum

// Function: print_d -outputs to screen the max value between the left and
// right maxes, the start & ending subscripts that are output to a file 
// is obtained using file using I/O redirection.
//
// Pre-condition: Stores the max value, the start and ending subscripts
//
// Post-condition: returns nothing
//
void print_d(ptr stocks[], int& max, int& s_loc, int& e_loc)
{
   cout << "\n  Start-subscript: " << setw(2) << s_loc;  // start subscript
   cout << "\n  End-subscript: "   << setw(4) << e_loc;    // end subscript
   cout << "\n  Max Value: ----> " << setw(2) << max;    // max value
   cout << endl;
} // exit print
//-------------------------->  "Ending of Program" <----------------------//
