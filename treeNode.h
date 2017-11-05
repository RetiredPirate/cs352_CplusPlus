////////////////////////////////////////////////////////////////
//  treeNode.h
//
//  include-file for treeNode.cpp, which implements a BST
//
//  author: Steven R. Vegdahl
//  author: **** PUT YOUR NAME HERE ****
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#ifndef __treeNode_h__
#define __treeNode_h__

using namespace std;

template <typename T, typename S>
class treeNode {
public:
    treeNode* left;
    treeNode* right;
    treeNode* parent;
    S value;
    T key;
    treeNode(T initKey, S initValue);
    ~treeNode();
private:
    int refCount;
};

#endif // #ifndef __treeNode_h__
