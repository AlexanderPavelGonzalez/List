//Author: Alexander Gonzalez 
//Date: 09/20/17
//Purpose:Main for testing alist.h

#include "alist.h"

int main(){
  AList<int> testListA;
  testListA.insert(100);
  testListA.insert(99);
  testListA.insert(98);
  testListA.insert(97);
  
  testListA.moveToStart();
  for(int curr=0; curr<testListA.length();curr++){
     cout<<testListA.getValue()<<endl;
    testListA.next();
  }
  /*
  AList<int> testListB;
  testListB.insert(8);
  testListB.insert(7);
  testListB.insert(6);
  testListB.insert(5);

  AList<int> mergedList;

  mergedList.merge(testListA,testListB,mergedList);

   un-comment for swap(), isSorted(), and reverse() methods 
  AList<int> testList;
  testList.insert(3);
  testList.insert(2);
  testList.insert(1);

   testList.moveToStart();
   testList.reverse();
   testList.swap();
   cout<< testList.isSorted()<<endl;
      for(int curr=0; curr<testList.length();curr++){
     cout<<testList.getValue()<<endl;
    testList.next();   
    }
  */
}
