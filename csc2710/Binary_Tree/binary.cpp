// test binary tree class

#include <iostream>
#include "binary.h"
using namespace std;
// globals

int count = 0;

template<class T>
void ct(BinaryTreeNode<T> *t) 
{
   extern int count;
   count++;
}

int main(void)
{
   extern int count;
   BinaryTree<int> a,x,y,z;

   y.MakeTree(1,a,a);
   z.MakeTree(2,a,a);
   x.MakeTree(3,y,z);
   y.MakeTree(4,x,a);

   cout << "Postorder sequence is ";
   y.PostOutput();

   //  cout << "Level order sequence is ";
   //  y.LevelOutput();

   cout << "Number of nodes = ";
   cout << y.Size() << endl;
   cout << "Height = ";
   cout << y.Height() << endl;
   y.PostOrder(ct);
   
   cout << "Count of nodes is " << count << endl;

   return 0;
}