/***************************************************************
 * main.cpp
 *
 * creates, modifies, and prints some lists
 ***************************************************************/

#include <iostream>
#include "IntList.h"
#include "debug.h"

using namespace std;

// Function to print an IntList. Intentionally uses a value parameter
// as opposed to a reference, so that we can see copy constructor in
// action.
//
// Parameters:
// - list: the list to print
// - os: the output stream to print to; defaults to standard output
void printList(IntList list, ostream& os=std::cout) {
  os << list;
}

// Main program. Creates 5 lists and prints them
//
// Returns:
//  The return status of the program
int main() {
  // declare first two integer lists
  IntList list1; // empty list
  IntList list2(4); // list with single element, 4

  // debug-print list-addresses
  print2("list1: ", &list1);
  print2("list2: ", &list2);

  // print list2's first element
  cout << "list2, first: " << list2.getFirstElement() << endl;

  // add a 56 to the front of list2; print first element
  list2.addToFront(56);
  cout << "list2, first: " << list2.getFirstElement() << endl;

  // remove front element from list2; print first element and length
  cout << "result of removeFromFront: " << list2.removeFromFront() << endl;
  cout << "list2, first: " << list2.getFirstElement() << endl;
  cout << "list2, length: " << list2.length() << endl;

  // create a third list, with a total of 4 elements
  IntList list3(45);
  list3.addToFront(37);
  list3.addToFront(101);
  list3.addToFront(222);

  // create a fourth list with one element
  IntList list4(35);

  // overwrite the fourth list so that it is the same as the third
  list4 = list3;

  // loop through and do some removals and
  print1("begin mod loop for list4");
  for (int i = 0; i < 3; i++) {
    int a = list4.removeFromFront();
    int b = list4.removeFromFront();
    list4.addToFront(i);
    list4.addToFront(b);
  }
  print1("end mod loop for list4");

  // create a fifth list object on the heap, a copy of list2
  IntList* ptr5 = new IntList(list3);

  // remove an element from the front of the fifth list
  ptr5->removeFromFront();

  // print the lists
  cout << "list1: " << list1 << endl;
  cout << "list2: " << list2 << endl;
  cout << "list3: " << list3 << endl;
  cout << "list4: "; printList(list4); cout << endl; // value-parameter
  cout << "*ptr5 (fifth list): " << *ptr5 << endl;

  // deallocate the heap-allocated list
  print1("deallocating ptr5");
  delete ptr5;

  // exit
  print1("exit 'main'");
  return 0;
}
