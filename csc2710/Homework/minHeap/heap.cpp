/*
 * Name: Alexander Sims
 */
#include <iomanip>
#include <iostream> 
#include <climits>
//#include <interator>
using namespace std; // container

// template class
template <class T>
class minHeap
{
public:
   int parent(int curIndex);
   int leftChild(int curIndex);
   int rightChild(int curIndex);
   T& peek(void);
   T extractMin(void);
   void exchange(T &a, T &b);
   void heapify(int curIndex); 
   void increaseKey(int curIndex, T& key); 
   void insert (T & key); 
   minHeap();
      // constructor
   ~minHeap();
      // deconstructor
private:
    int MaxSize;    // max size of heap
    int heapSize;   // size of heap
    int minHeap;    // minHeap variable
    int *HeapArray; // heap array
};

int main(void) // main
{
   
   return 0;
} // exit main


template <class T>
minHeap<T>::minHeap()
{
   heapSize = 0;
   MaxSize = new int[heapSize];
} // exit constructor


template <class T>
minHeap<T>::~minHeap()
{
	delete []MaxSize;
} // exit deconstructor


template <class T>
int minHeap<T>::parent(int curIndex)
{
   int pair = (curIndex-1)/2;
   if (curIndex == 0)
      return -1;
   else
   	  return pair;
}  // exit parent


template <class T>
int minHeap<T>::leftChild(int curIndex)
{
   int left = 2 * curIndex+1;
   if (left < heapSize)
      return left;
   else
   	  return -1;
}  // exit leftChild


template <class T>
int minHeap<T>::rightChild(int curIndex)
{
   int right = 2 * curIndex+2;
   if (right < heapSize)
      return right;
   else
   	  return -1;
}  // exit rightChild


template <class T>
T& minHeap<T>::peek(void)
{
 
}  // exit peek


template <class T>
T minHeap<T>::extractMin(void)
{
   if(heapSize < 1)
      cerr<<"Heap is empty"<<endl; // throw exception????
   T min = HeapArray[1];
   HeapArray[1] = HeapArray[heapSize];
   heapSize--;
   heapify(1);
   return min;
}  // exit extractMin


template <class T>
void minHeap<T>::exchange(T &a, T &b)
{
   int tmp;
   tmp = a, a = b, b = tmp;
}  // exit exchange


template <class T>
void minHeap<T>::heapify(int curIndex)
{  
   int lfIndx = leftChild(curIndex);
   int rtIndx = rightChild(curIndex);
   int mdIndx;
   if (lfIndx <= heapSize and HeapArray[lfIndx] < HeapArray[curIndex])
      mdIndx = lfIndx;
   else
   	  mdIndx = curIndex;

   if (rtIndx <= heapSize and HeapArray[rtIndx] < HeapArray[mdIndx])
   	  mdIndx = rtIndx;
   if (mdIndx != curIndex) {
      exchange(HeapArray[mdIndx], HeapArray[curIndex]);
      heapify(mdIndx);
   }
}  // exit heapify


template <class T>
void minHeap<T>::increaseKey(int curIndex, T& key)
{  
   HeapArray[curIndex] = key;
   while(curIndex > 0 and 
   	     HeapArray[parent(curIndex)] > HeapArray[curIndex])
      exchange(HeapArray[parent(curIndex)], HeapArray[curIndex]);
      curIndex = parent(curIndex);
}  // exit increaseKey


template <class T>
void minHeap<T>::insert(T & key)
{
	MaxSize = INT_MAX;
	increaseKey(MaxSize-1, key);
}  // exit insert

void topological ()





