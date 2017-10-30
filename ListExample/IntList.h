/***************************************************************
 * IntList.h
 *
 * header file for IntList.cpp--defines the IntList class, which
 * represents a list of integers
 ***************************************************************/

#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include <climits>
#include "IntListNode.h"

class IntList {
  
 private:
  
  // instance variable: pointer to first list node
  IntListNode *first;
  
  // helper methods for use by the '<<' method:
  // - get next node
  // - get data from first node
  IntListNode* getNextNode(IntListNode* p) const;
  int getData(IntListNode* p) const;
  
 public:
  // constructor: creates empty list
  IntList();

  // constructor: creates singleton list
  IntList(int num);

  // copy constructor
  IntList(const IntList& orig);

  // destructor
  ~IntList();
  
  // assignment operator
  IntList operator=(IntList const& src);

  // get the first element
  int getFirstElement() const;

  // add element to front of list
  void addToFront(int n);

  // remove element from front of list, returning removed element
  int removeFromFront();

  // length of list
  int length() const;
  
  // declare output operator function as a friend
  friend std::ostream& operator<<(std::ostream& os, IntList const& lst);

};

#endif // INTLIST_H
