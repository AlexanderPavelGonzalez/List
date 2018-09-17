//Author: Alexander Gonzalez 
//Date: 09/20/17
//Purpose: Adding a swap,isSorted, reverse, and merge methods to the code. 

#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

#include "list.h"

//--------------------------------------------------------
// alist.h
//----------------------------------------------------------

template <typename E> // Array-based list implementation
class AList : public List<E> {
private:
  int maxSize;        // Maximum size of list
  int listSize;       // Number of list items now
  int curr;           // Position of current element
  E* listArray;    // Array holding list elements

public:
  AList(int size=100) { // Constructor
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize];
  }

  ~AList() { delete [] listArray; } // Destructor

  void clear() {                    // Reinitialize the list
    delete [] listArray;            // Remove the array
    listSize = curr = 0;            // Reset the size
    listArray = new E[maxSize];  // Recreate array
  }

  // Insert "it" at current position
  void insert(const E& it) {
    assert(listSize < maxSize);
    for(int i=listSize; i>curr; i--)  // Shift elements up
      listArray[i] = listArray[i-1];  //   to make room
    listArray[curr] = it;
    listSize++;                       // Increment list size
  }

  void append(const E& it) {       // Append "it"
    assert(listSize < maxSize);
    listArray[listSize] = it;
    listSize++;
  }

  // Remove and return the current element.
  E remove() {
    assert((curr>=0) && (curr < listSize));
    E it = listArray[curr];           // Copy the element
    for(int i=curr; i<listSize-1; i++)  // Shift them down
      listArray[i] = listArray[i+1];
    listSize--;                          // Decrement size
    return it;
  }
  
  void moveToStart() { curr = 0; }        // Reset position
  void moveToEnd() { curr = listSize; }     // Set at end
  void prev() { if (curr != 0) curr--; }       // Back up
  void next() { if (curr < listSize) curr++; } // Next

  // Return list size
  int length() const  { return listSize; }

  // Return current position
  int currPos() const { return curr; }

  // Set current list position to "pos"
  void moveToPos(int pos) {
    assert ((pos>=0)&&(pos<=listSize));
    curr = pos;
  }

  const E& getValue() const { // Return current element
    assert((curr>=0)&&(curr<listSize));
    return listArray[curr];
  }
  //swap current item with the following item in the list
  void swap(){
    int temp=listArray[curr+1];
    listArray[curr+1]=listArray[curr];
    listArray[curr]=temp;  
  }
  bool isSorted(){
    curr=0;
    while (curr<listSize-1){
      if(listArray[curr+1]<listArray[curr]){
	return false;     
    }    
      curr++;
    }
    return true;
  }
  void reverse(){
    int temp;
    for(int i=0;i<listSize/2;i++){
      temp=listArray[i];
      listArray[i]= listArray[(listSize-1)-i];
      listArray[(listSize-1)-i]=temp;
    } 
   }
  void merge(AList<int>& arrayA, AList<int>& arrayB, AList<int>& arrayC){
  
   
    
    if(arrayA.isSorted()==true){
      for(int i=0;i<arrayA.listSize; i++){    
        arrayC.insert(arrayA.listArray[i]);
      }
    }
     if(arrayB.isSorted()==true){
      for(int i=0;i<arrayB.listSize; i++){
        arrayC.insert(arrayB.listArray[i]);
      }
    }
        
    arrayC.moveToStart();
    for(int curr=0; curr<arrayC.listSize;curr++){
        cout<<arrayC.getValue()<<endl;
        arrayC.next();
      }
    
    
    }
    
};


//--------------------------------------------------------



