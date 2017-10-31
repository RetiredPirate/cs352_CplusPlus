////////////////////////////////////////////////////////////////
//  treeNode.cpp
//
//  treeNode.cpp, which implements a BST
//
//  author: Steven R. Vegdahl
//  author: Andrew M. Williams
//  version: 30 October 2017
////////////////////////////////////////////////////////////////

#include <iostream>
#include "treeNode.h"

using namespace std;



treeNode::treeNode(string initKey, string initValue, treeNode& initParent) {
    key = initKey;
    value = initValue;
    parent = initParent;
}

// this class is presently dummied up
