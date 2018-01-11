// bst.h
// unbalanced binary search trees
#ifndef BSTree_
#define BSTree_

#include "binary.h"

template<class T>
class BSTree:public BinaryTree<T> {
   public:
      BinaryTreeNode<T>* Search( T &e) const;
      BSTree<T>& Insert(const T& e);
      BSTree<T>& Delete(T& e);
      //BSTree<T>& optsearch(T& e) const;
};

template<class T>
BinaryTreeNode<T>* BSTree<T>::Search( T &e) const
{ 
   // Search for element that matches e.
   // pointer p starts at the root and moves through
   // the tree looking for element e
   BinaryTreeNode<T> *p = this->root;
   while (p) // examine p->data
      if (e < p->data) 
         p = p->lchildptr;
      else if (e > p->data) 
         p = p->rchildptr;
      else {
         return *this;
      }
   return NULL;
}

template<class T>
BSTree<T>& BSTree<T>::Insert(const T& e)
{
   // Insert e if not duplicate.
   BinaryTreeNode<T> *p = this->root,  // search pointer
                     *pp = 0;    // parent of p
   // find place to insert
   while (p) {
      // examine p->data
      pp = p;
      // move p to a child
      if (e < p->data) 
         p = p->lchildptr;
      else if (e > p->data) 
         p = p->rchildptr;
      else {
         cerr<<"Error: Tlement already in tree"<<endl;
         return *this;
      }
   }

   // get a node for e and attach to pp
   BinaryTreeNode<T> *r = new BinaryTreeNode<T> (e);
   if (this->root) {
      // tree not empty
      if (e < pp->data) 
         pp->lchildptr = r;
      else 
         pp->rchildptr = r;
   } else 
      // insertion into empty tree
      this->root = r;

   return *this;
}

template<class T>
BSTree<T>& BSTree<T>::Delete( T& e)
{  
   // Delete element e if in the tree 

   BinaryTreeNode<T> *p = this->root, // search pointer
                     *pp = 0;   // parent of p
   //move p down the tree until you find e or 
   //run out of elements.  
   //let pp trail behind, i.e. pp is the parent of p
   //
   //code it....
   

   //at this point, get out if you did not find e
   //code it....

   //at this point, p should point to a node containing e so
   //the next line might be a mute point but it's in here 
   //so leave it....
   e = p->data;  // save element to delete

   // restructure tree
   // handle case when p has two children
   // i.e. convert it to a tree that has only one or zero children
   // see notes on more info and examples.
   // code it....

   // now, p has at most one child
   // save child pointer in c
   // code it...

   // before you delete p
   // you have to tie in c to the correct side of pp
   // if p is to the left of pp then pp's leftchild gets c
   // otherwise pp's rightchild gets c
   // watch out if p is root
   // code it....
   
  
   // at this point, p can be deleted. 
   delete p;

   //return *this so you can chain the deletes together.
   return *this;
}

#endif