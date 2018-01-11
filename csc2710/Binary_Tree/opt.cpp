#ifndef BSTree_
#define BSTree_

#include "binary.h"
#include <iostream>

using namespace std;

// globals
int count = 0;

template<class T>
class BSTree:public BinaryTree<T> {
   BSTree<T>& optsearch(T& e) const;
};

int main(void)
{
	extern int count;
	BinaryTree<int> a,x,y,z;

    //Input
    y.MakeTree(1,a,a);
    z.MakeTree(2,a,a);
    x.MakeTree(3,y,z);
    y.MakeTree(4,x,a);

	cout << "Pre-order sequence is: ";
	// Output pre-order

	cout << "Level order sequence is: ";
	// Output level-order

   return 0;
}

template<class T>
BSTree<T>& BSTree<T>::optsearch(T& e) const
{
   int i, j, k, diagnal;
   float A[n+1][n];

   while (i<=n) {
      A[i][i-1] = 0; 
      A[i][i] = p[i];
      R[i][i] = i;
      R[i][i-1] = 0;
      i++;
   }
   A[n+1][n] = 0;
   R[n+1][n] = 0;

   for (diagnal=1; diagnal<=n-1; diagnal++) 
      for (i=1; i<=n-diagnal; i++) {
         j=i+diagnal;
         A[i][j] = minimum(A[i][k-1] + A[k+1][j]) + p[i];
         R[i][j] = k; //the return values for minimum value from tree
         // k => the index change
      }
      minavg = A[1][n];
}

template<class T>
BSTree<T>& BSTree<T>::tree(T& i, BSTree<T>& j)
{
	int k;
	node_pointer p;
    
	k = R[i][j];
	if (k==0)
		return NULL;
	else {
		p = new nodetype;
		p-> key = key[k];
		p-> left = tree(i, k-1);
		p-> right = tree(k+1, j);
		return p;
	}
}

#endif