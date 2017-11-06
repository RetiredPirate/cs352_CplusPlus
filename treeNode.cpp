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
    refCount = 1;
    parent = NULL;
    left = NULL;
    right = NULL;
}



template<typename T, typename S>
treeNode<T,S>::treeNode(const treeNode& copyNode) {
    key = copyNode->key;
    value = copyNode->value;
    parent = copyNode->parent;
    left = copyNode->left;
    right = copyNode->right;
    refCount = 1;
}


template<typename T, typename S>
treeNode<T, S>::~treeNode() {

}

// this class is presently dummied up
