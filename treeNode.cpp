////////////////////////////////////////////////////////////////
//  treeNode.cpp
//
//  treeNode.cpp, which implements a BST
//
//  author: Steven R. Vegdahl
//  author: Andrew Williams
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#include <iostream>
#include "treeNode.h"

using namespace std;

/* treeNode()
 *
 */
template<typename T, typename S>
treeNode<T, S>::treeNode(T initKey, S initValue) {
    key = initKey;
    value = initValue;
    parent = NULL;
    left = NULL;
    right = NULL;
}


// this class is presently dummied up
