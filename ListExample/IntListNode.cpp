/***************************************************************
 * IntListNode.cpp
 *
 * method definitions for the IntNode class
 ***************************************************************/

#include <iostream>
#include "IntListNode.h"
#include "debug.h"

/*
 * constructor
 *
 * parameters:
 * - num: the data for the list node
 * - the next-pointer for the list node
 * Note: the reference count field is intialized to 0
 */
IntListNode::IntListNode(int num, IntListNode *next) {
  print2("create IntListNode ", this);

  // set the fields to their values
  data = num;
  this->next = next;
  refCount = 0;

  print4("relinking ", this, " to ", next);
}

/*
 * destructor
 */
IntListNode::~IntListNode() {
  print2("destroy IntListNode ", this);

  // If the next-field is non-null, decrement its ref-count, as we will no
  // longer be pointing to it. If the ref-count has gone to zero, deallocate
  // it.
  if (next != NULL) {
    next->refCount--;
    print4("refCount for ", next, " := ", next->refCount);
    if (next->refCount == 0) {
      delete(next);
    }
  }
}
