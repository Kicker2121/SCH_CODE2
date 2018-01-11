// test binary tree class

#include <iostream>
#include "bst.h"
using namespace std;
// globals

int main(void)
{
   BSTree<int> B;
   
   B.Insert(10);
   B.Insert(5);
   B.Insert(20);
   B.Insert(18);
   B.Insert(4);
   B.Insert(9);
   B.Insert(14);
   B.Insert(3);

   cout << "Postorder sequence is ";

   B.PostOutput();

   //  cout << "Level order sequence is ";
   //  y.LevelOutput();

   cout << "Number of nodes = ";
   cout << B.Size() << endl;

   cout << "Height = ";
   cout << B.Height() << endl;

   return 0;
}