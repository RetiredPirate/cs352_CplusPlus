////////////////////////////////////////////////////////////////
//  map.cpp
//
//  implements a dictionary (map) class
//
//  author: Steven R. Vegdahl
//  author: **** PUT YOUR NAME HERE ****
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "map.h"
#include "treeNode.h"


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
void map::put(string key, string value) {
  // dummied up
}

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
bool map::get(string key, string& value) const {
  // dummied up
  return false;
}

////////////////////////////////////////////////////////////////
// remove: removes an elementn from the map
//
// parameters:
// - key: the lookup key that specifies the element to remove
//
// returns:
//   true if the value was removed, false if it was not there
////////////////////////////////////////////////////////////////
bool map::remove(string key) {
  // dummied up
  return false;
}


////////////////////////////////////////////////////////////////
// unary + operator: size
//
// returns:
//   the number of elements in the map
////////////////////////////////////////////////////////////////
int map::operator+() const {
  // dummied up: return an obviously incorrect value
  return -6;
}

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
ostream& operator<<(ostream& os, const map& dict) {
  // dummied up, so just print a dummy string
  os << "dummied up";
  
  // return
  return os;
}
