////////////////////////////////////////////////////////////////
//  treeNode.h
//
//  include-file for treeNode.cpp, which implements a BST
//
//  author: Steven R. Vegdahl
//  author: Andrew Williams
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
    T key;
    S value;
    treeNode(T initKey, S initValue);
    treeNode(const treeNode& copyNode);
    ~treeNode();
private:
    int refCount;
};

#endif // #ifndef __treeNode_h__
