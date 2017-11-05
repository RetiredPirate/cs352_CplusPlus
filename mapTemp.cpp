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
template<typename T, typename S> void map<T,S>::put(T key, S value) {
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
template<typename T, typename S> bool map<T,S>::get(T key, S& value) const {
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
template<typename T, typename S> bool map<T,S>::remove(T key) {
  // dummied up
  return false;
}
