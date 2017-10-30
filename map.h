////////////////////////////////////////////////////////////////
//  map.h
//
//  include-file for map.cpp, which implements a dictionary
//
//  author: Steven R. Vegdahl
//  author: **** PUT YOUR NAME HERE ****
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#ifndef __map_h__
#define __map_h__

#include "treeNode.h"

using namespace std;

////////////////////////////////////////////////////////////////
// class definition
////////////////////////////////////////////////////////////////
class map {
 private:
  // instance variable: the root of our tree
  treeNode* root;
  
 public:

  ////////////////////////////////////////////////////////////////
  // constructor: creates an empty map object
  ////////////////////////////////////////////////////////////////
  inline map(): root(NULL) {
    // presently, just sets the root to NULL
  }

  ////////////////////////////////////////////////////////////////
  // put: puts a value into the dictionary
  //
  // parameters:
  // - key: the key that will be used to look the value up
  // - value: the value to associate with that key
  //
  // If there is already an entry in the table with the given key,
  // that entry is overwritten.
  ////////////////////////////////////////////////////////////////
  void put(string key, string value);

  ////////////////////////////////////////////////////////////////
  // get: gets the value that is associated with the key, if present
  //
  // parameters:
  // - key: the lookup key
  // - value: the location through which the looked-up value will be
  //   returned, if present
  //
  // returns:
  //   true if the value was found, false otherwise
  //
  // The 'value' variable will be updated only if the function returns
  // true.
  ////////////////////////////////////////////////////////////////
  bool get(string key, string& value) const;
  
  ////////////////////////////////////////////////////////////////
  // remove: removes an elementn from the map
  //
  // parameters:
  // - key: the lookup key that specifies the element to remove
  //
  // returns:
  //   true if the value was removed, false if it was not there
  ////////////////////////////////////////////////////////////////
  bool remove(string key);


  ////////////////////////////////////////////////////////////////
  // unary + operator: size
  //
  // returns:
  //   the number of elements in the map
  ////////////////////////////////////////////////////////////////
  int operator+() const;

  // declare output operator as friend function
  friend ostream& operator<<(ostream& os, const map& dict);
};


////////////////////////////////////////////////////////////////
// << operator: prints to a stream
//
// parameters:
// - os: the output stream to print to
// - dict: the map to print
//
// returns:
//   a reference to the output stream
////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const map& dict);

#endif // #ifndef __map_h__

