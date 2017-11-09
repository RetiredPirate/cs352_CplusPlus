////////////////////////////////////////////////////////////////
//  main.cpp
//
//  main/driver program for testing the map class
//
//  author: Steven R. Vegdahl
//  author: Andrew Williams
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "map.h"

#define DO_STRING false // set to true for strings, false for ints

using namespace std;

// define the array of pairs, for populating the map
#if DO_STRING
string pairs[][2] = {
  {"John", "Stanford"},
  {"Fred", "Portland"},
  {"Susan", "Yale"},
  {"Nathan", "CMU"},
  {"Jane", "Brown"},
  {"Savannah", "MIT"},
};
#else
int pairs[][2] = {
  {1,2},
  {2,4},
  {66,3},
  {7,43},
  {8,33},
  //{6,3},
  {23,56}
};
#endif

////////////////////////////////////////////////////////////////
// method for printing the result of a lookup, or that the lookup
// failed
//
// parameters:
// - dict: the dictionary (map) to use
// - name: the name to look up
////////////////////////////////////////////////////////////////
#if DO_STRING
void printSearchResult(map<string,string>& dict, string name) {
  string result;
  if (dict.get(name, result)) {
    cout << "found " << name << " => " << result << endl;
  }
  else {
    cout << "not found: " << name << endl;
  }
}
#else
void printSearchResult(map<int,int>& dict, int val) {
  int result;
  if (dict.get(val, result)) {
    cout << "found " << val << " => " << result << endl;
  }
  else {
    cout << "not found: " << val << endl;
  }
}
#endif

////////////////////////////////////////////////////////////////
// the main method: populates a map; prints; does additional
// operations; prints again
////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {

  // the map to use
#if DO_STRING
    map<string,string> dict;
#else
    map<int, int> dict;
#endif

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
