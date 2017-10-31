////////////////////////////////////////////////////////////////
//  treeNode.h
//
//  include-file for treeNode.cpp, which implements a BST
//
//  author: Steven R. Vegdahl
//  author: Andrew M. Williams
//  version: 30 October 2017
////////////////////////////////////////////////////////////////

#ifndef __treeNode_h__
#define __treeNode_h__

using namespace std;

class treeNode {
    public:
        treeNode();
        ~treeNode();
    private:
        string key;
        string value;
        treeNode* parent;
        treeNode* left;
        treeNode* right;
};

#endif // #ifndef __treeNode_h__
