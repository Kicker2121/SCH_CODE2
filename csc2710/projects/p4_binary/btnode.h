#ifndef BTNODE
#define BTNODE

template <class T> class BinaryTree;
template <class T> class BSTree;

template <class T>
class BinaryTreeNode {
   friend class BinaryTree<T>;
   friend class BSTree<T>;
   public:
      BinaryTreeNode() 
      {
         lchildptr = rchildptr = 0;
      }
      BinaryTreeNode(const T& e) {
         data = e;
         lchildptr = rchildptr = 0;
      }
      BinaryTreeNode(const T& e, BinaryTreeNode *l,
                     BinaryTreeNode *r)
      {
         data = e;
         lchildptr = l;
         rchildptr = r;
      }
   private:  
      T data;
      BinaryTreeNode<T> *lchildptr,   // left subtree
                        *rchildptr;  // right subtree
};

#endif