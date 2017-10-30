/***************************************************************
 * IntListNode.h
 *
 * header file for IntList.cpp--defines the IntList class, which
 * represents a single node in a list of integers
 ***************************************************************/
#ifndef INTLISTNODE_H
#define INTLISTNODE_H

#include <iostream>
#include <climits>

class IntListNode {

private:
  // instance variables
  int data; // our node's data
  IntListNode *next; // next-pointer
  int refCount; // reference count
    
public:

  // constructor
  IntListNode(int num, IntListNode *next);

  // destructor
  ~IntListNode();

  // allow the IntList class access to our state
  friend class IntList;
};

#endif // INTLISTNODE_H
