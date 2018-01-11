#include"List.h"

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
   try {
      List<string> L;

      L.add("Horse");
      L.add("Dog");
      L.remove("Horse");
      L.add("cat");
      L.add("Zebra");
      L.add("Bird");
      L.add("Deer");
      cout<<"================================="<<endl;
      cout<<"The list contains "<<L.length()<<" elements"<<endl;
      cout<<"Here are the elements in the list"<<endl;
      L.print();

      cout<<"================================="<<endl;
      cout<<"Here are the elements using the iterator"<<endl;
   
      List<string>::Iterator li = L.begin();
      while(li != L.end()) {
         cout<<*li<<endl;
         ++li;
      }
   } catch(const char * str) {
      cout<<"Exception: "<<str<<endl;
      exit(1);
   }
   return 0;
}