/***************************************************************
 * IntList.cpp
 *
 * method definitions for the IntList class
 ***************************************************************/

#include "IntList.h"
#include <string>
#include "debug.h"

/*
 * constructor: creates an empty list
 */
IntList::IntList() {
  print2("create IntList ", this);
  first = NULL;
}

/*
 * constructor: creates a list with one element
 *
 * parameters:
 * - num: the (singleton) element to go into the list
 */
IntList::IntList(int num) {
  print2("create IntList ", this);

  // create a node with our value in it
  first = new IntListNode(num, NULL);
  print4("linking ", this, " to ", first);

  // increment the ref-count for our new node, since we're pointing
  // to it
  first->refCount++;

  print4("refCount for ", first, " := ", first->refCount);
}

/*
 * copy constructor
 *
 * parameters:
 * - orig: the list to make a copy of
 */
IntList::IntList(const IntList& orig) {
  print1("IntList copy constructor called");

  // set our "first" pointer to be that of the original list
  this->first = orig.first;

  // if the first-pointer is not null, bump the ref count of the node
  if (this->first != NULL) {
    this->first->refCount++;
    print4("refCount for ", this->first, " := ", this->first->refCount);
  }
}

/*
 * destructor
 */
IntList::~IntList() {
  print2("destroy IntList ", this);

  // if our first-pointer is not null:
  // - decrement it's ref-count
  // - if its ref-count has gone to 0, deallocate it
  if (first != NULL) {
    first->refCount--;
    print4("refCount for ", first, " := ", first->refCount);
    if (first->refCount == 0) {
      delete(first);
    }
  }
}

/*
 * assignment operator
 */
IntList IntList::operator =(IntList const& src) {
  print1("assignment operator called");

  // if the assignment-target's pointer is not null
  // - decrement its ref-count
  // - if its ref-count has gone to zero, deallocate it
  // (This is done because the pointer will be overwritten
  if (first != NULL) {
    first->refCount--;
    if (first->refCount == 0) {
      delete(first);
    }
  }

  // copy the first-pointer from the source to that of the target
  first = src.first;

  // if the new first-pointer is not null, increment the ref-count of
  // its target
  if (first != NULL) {
    first->refCount++;
    print4("refCount for ", first, " := ", first->refCount);
  }
  return *this;
}

/*
 * getFirstElement -- gets the first element of the list, returning
 * 0 if the list is empty
 */
int IntList::getFirstElement() const {
  if (first == NULL) {
    // return 0 if the list is empty
    return 0;
  }
  else {
    // otherwise, return the first element of the list
    return first->data;
  }
}

/*
 * addToFront -- adds an element to the front of a list
 *
 * parameters:
 * - n: the element to add
 */
void IntList::addToFront(int n) {
  print1("addToFront");

  // splice in our new node to the front of the list
  first = new IntListNode(n,first);
  print4("linking ", first, " to ", first->next);
  print4("relinking ", this, " to ", first);

  // increment the ref-count for our new node
  first->refCount++;
  print4("refCount for ", first, " := ", first->refCount);
}

/*
 * removeFromFront -- removes (and returns) the element at the
 * front of a list
 *
 * returns:
 * - the element that was removed, or 0 if the list had been empty
 */
int IntList::removeFromFront() {
  print1("removeFromFront");

  // if list is empty, return 0
  if (first == NULL) return 0;

  // save away the return value and its node
  int rtnVal = first->data;
  IntListNode *oldFirst= first;

  // move our first-pointer ahead one, effectively removing the
  // first node from our list
  first = oldFirst->next;

  // increment ref-count of our new first node
  first->refCount++;
  print4("relinking ", this, " to ", first);

  // decrement the ref-count of our old first node. If its ref-count
  // has gone to zero, deallocate it
  oldFirst->refCount--;
  print4("refCount for ", first, " := ", first->refCount);
  print4("refCount for ", oldFirst, " is ", oldFirst->refCount);
  if (oldFirst->refCount == 0) {
    delete(oldFirst);
  }
  return rtnVal;
}

/*
 * length -- returns the length of a list
 *
 * returns:
 *  the list's length
 */
int IntList::length() const {
  print1("length");

  // initialize a count to zero
  int count = 0;

  // loop through and count each element
  for (IntListNode *p = first; p != NULL; p = p->next) {
    count++;
  }
  print2("end length: ", count);

  // return the number of elements counted
  return count;
}

/*
 * getNextNode (helper method); does NOT check whether the parameter is NULL
 *
 * parameters:
 * - p: the node from which to follow the 'next' field
 * returns:
 *  the next field from the element referenced
 */
IntListNode* IntList::getNextNode(IntListNode* p) const {
  // return the next field
  return p->next;
}


/*
 * getData (helper method); does NOT check whether the parameter is NULL
 *
 * parameters:
 * - p: the node from which to get the data
 * returns:
 *  the data from the element referenced
 */
int IntList::getData(IntListNode* p) const {
  return p->data;
}

/*
 * '<<' (output operator) method
 *
 * parameters
 * - os: the stream to which output is to be sent
 * - lst: the list to print
 */
std::ostream& operator<<(std::ostream& os, IntList const& lst) {
  // separator character (which is empty the first time through
  std::string separator = "";

  // loop through and print each element
  for (IntListNode* p = lst.first; p != NULL; p = lst.getNextNode(p)) {
    os << separator; // print separator
    separator = " "; // update separator
    os << lst.getData(p); // print element's data
  }

  // return (reference to) the output stream
  return os;
}
