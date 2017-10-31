////////////////////////////////////////////////////////////////
//  main.cpp
//
//  main/driver program for testing the map class
//
//  author: Steven R. Vegdahl
//  author: Andrew M. Williams
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "map.h"

using namespace std;

// define the array of pairs, for populating the map
string pairs[][2] = {
  {"John", "Stanford"},
  {"Fred", "Portland"},
  {"Susan", "Yale"},
  {"Nathan", "CMU"},
  {"Jane", "Brown"},
  {"Savannah", "MIT"},
};

////////////////////////////////////////////////////////////////
// method for printing the result of a lookup, or that the lookup
// failed
//
// parameters:
// - dict: the dictionary (map) to use
// - name: the name to look up
////////////////////////////////////////////////////////////////
void printSearchResult(map& dict, string name) {
  string result;
  if (dict.get(name, result)) {
    cout << "found " << name << " => " << result << endl;
  }
  else {
    cout << "not found: " << name << endl;
  }
}

////////////////////////////////////////////////////////////////
// the main method: populates a map; prints; does additional
// operations; prints again
////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {

  // the map to use
  map dict;

  // populate with some elements
  for (int i = 0; i < sizeof(pairs)/sizeof(*pairs); i++) {
    dict.put(pairs[i][0], pairs[i][1]);
  }

  // print the contents before modifying
  cout << "======== before modifications ========" << endl;
  for (int i = 0; i < sizeof(pairs)/sizeof(*pairs); i++) {
    printSearchResult(dict, pairs[i][0]);
  }

  // print the map
  cout << dict << endl;

  // do some modifications
  dict.remove(pairs[0][0]);
  dict.remove(pairs[4][0]);
  dict.put(pairs[2][0],pairs[5][1]);

  // print the contents after modifying
  cout << "======== after modifications ========" << endl;
  for (int i = 0; i < sizeof(pairs)/sizeof(*pairs); i++) {
    printSearchResult(dict, pairs[i][0]);
  }

  // print the map
  cout << dict << endl;

  // print the size of the map
  cout << "size: " << +dict << endl;

  return 0;
}
