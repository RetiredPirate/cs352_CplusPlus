////////////////////////////////////////////////////////////////
//  map.cpp
//
//  implements a dictionary (map) class
//
//  author: Steven R. Vegdahl
//  author: Andrew Williams
//  version: 19 October 2017
////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
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
template<typename T, typename S>
void map<T,S>::put(T key, S value) {
    treeNode<T,S>* initNode = new treeNode<T,S>(key, value);

    if (root == NULL) {
        root = initNode;
        size++;
    }
    else {
        treeNode<T,S>* tempNode = root;
        while(true) {
            if (initNode->key < tempNode->key) {
                //go left
                if (tempNode->left == NULL) {
                    tempNode->left = initNode;
                    initNode->parent = tempNode;
                    size++;
                    return;
                }
                else {
                    tempNode = tempNode->left;
                }
            }
            else if (initNode->key > tempNode->key){
                //go right
                if (tempNode->right == NULL) {
                    tempNode->right = initNode;
                    initNode->parent = tempNode;
                    size++;
                    return;
                }
                else {
                    tempNode = tempNode->right;
                }
            }
            if (initNode->key == tempNode->key) {
                //replace
                tempNode->value = initNode->value;
                return;
            }
        }//loop
    }//else

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
template<typename T, typename S>
bool map<T,S>::get(T key, S& value) const {
    treeNode<T,S>* getNode = findNode(key, root);

    if (getNode == NULL) {
        return false;
    }
    else {
        value = getNode->value;
        return true;
    }
}

////////////////////////////////////////////////////////////////
// remove: removes an element from the map
//
// parameters:
// - key: the lookup key that specifies the element to remove
//
// returns:
//   true if the value was removed, false if it was not there
////////////////////////////////////////////////////////////////
template<typename T, typename S>
bool map<T,S>::remove(T key) {
    // dummied up
    treeNode<T,S>* remNode = findNode(key, root);

    if (remNode->parent == NULL) {
        //root node
        treeNode* tempNode = remNode;
        if (remNode->right == NULL) {
            if (remNode->left == NULL) {
                remNode->refCount--;
            }
        }
        while (true) {

        }
    }
    else if ()


    size--;
    return false;
}

////////////////////////////////////////////////////////////////
// unary + operator: size
//
// returns:
//   the number of elements in the map
////////////////////////////////////////////////////////////////
template<typename T, typename S>
int map<T,S>::operator+() const {
  return size;
}


////////////////////////////////////////////////////////////////
// findNode: find a node in the tree, assuming not NULL
//
// returns:
//   a reference to the node with the given key
//   returns null if the node is not found
////////////////////////////////////////////////////////////////
template<typename T, typename S>
treeNode<T,S>* map<T,S>::findNode(T findKey, treeNode<T,S>* currNode) const {
    if (currNode == NULL) {
        return NULL;    //node not found
    }

    if (currNode->key == findKey) {
        return currNode;    //node found
    }

    // keep looking
    if (currNode->key < findKey) {
        return findNode(findKey, currNode->left);
    }
    else {
        return findNode(findKey, currNode->right);
    }

}



////////////////////////////////////////////////////////////////
// << operator: prints to a stream
//
// parameters:
// - os: the output stream to print to
// - dict: the map to print
//
// returns:
//   a reference to the output stream
////////////////////////////////////////////////////////////////
template<typename T, typename S>
ostream& operator<<(ostream& os, const map<T,S>& dict) {

  if (dict.root != NULL) {
      os << getMapString(os, dict.root);
  }
  else {
      os << "Map is empty.";
  }

  return os;
}



////////////////////////////////////////////////////////////////
// getMapString: returns a string representation of the map
//
// parameters:
// - os: the output stream to print to
// - currNode: the node to print
//
// returns:
//   a reference to the output stream
////////////////////////////////////////////////////////////////
template<typename T, typename S>
ostream& getMapString(ostream& os, treeNode<T,S>* currNode) {
    //go left
    if (currNode->left != NULL) {
        getMapString(os, currNode->left);
    }

    os << "[" << currNode->key << "=>" << currNode->value << "]\n";

    //go right
    if (currNode->right != NULL) {
        getMapString(os, currNode->right);
    }

    return os;
}
