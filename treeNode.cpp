////////////////////////////////////////////////////////////////
//  treeNode.cpp
//
//  treeNode.cpp, which implements a BST
//
//  author: Steven R. Vegdahl
//  author: **** PUT YOUR NAME HERE ****
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#include <iostream>
#include "treeNode.h"

using namespace std;


template<typename T, typename S> treeNode<T, S>::treeNode(T initKey, S initValue) {
    key = initKey;
    value = initValue;
}



template<typename T, typename S> treeNode<T, S>::treeNode() {
    
}

// this class is presently dummied up
