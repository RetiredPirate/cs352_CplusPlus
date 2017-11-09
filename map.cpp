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
// constructor: creates an empty map object
////////////////////////////////////////////////////////////////
template<typename T, typename S>
map<T,S>::map() {
    root = NULL;
    size = 0;
  // presently, just sets the root to NULL
}



////////////////////////////////////////////////////////////////
// copy constructor: creates an empty map object
////////////////////////////////////////////////////////////////
template<typename T, typename S>
map<T,S>::map(const map& initMap) {
    size = initMap.size;
    root = copyTree(initMap.root);
}



////////////////////////////////////////////////////////////////
// destructor: deletes all nodes in tree
////////////////////////////////////////////////////////////////
template<typename T, typename S>
map<T,S>::~map() {
    destroyTree(root);
    root = NULL;
    size = 0;
}



////////////////////////////////////////////////////////////////
// copyTree: returns a pointer to a new tree
//
//  traverses the tree recursively and creates new nodes
////////////////////////////////////////////////////////////////
template<typename T, typename S>
treeNode<T,S>* map<T,S>::copyTree(treeNode<T,S>* oldParent) {
    if (oldParent == NULL) {
        return NULL;
    }

    treeNode<T,S>* retNode = new treeNode<T,S>(oldParent->key, oldParent->value);
    retNode->left = copyTree(oldParent->left);
    retNode->right = copyTree(oldParent->right);

    if (retNode->left != NULL) {
        retNode->left->parent = retNode;
    }

    if (retNode->right != NULL) {
        retNode->right->parent = retNode;
    }

    return retNode;
}



////////////////////////////////////////////////////////////////
// destroyTree: deletes all child nodes of given node
//
//      traverses the tree recursively and creates new nodes
////////////////////////////////////////////////////////////////
template<typename T, typename S>
void map<T,S>::destroyTree(treeNode<T,S>* delNode) {
    if (delNode == NULL) {
        return;
    }

    destroyTree(delNode->left);
    destroyTree(delNode->right);

    delete delNode;
}



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

    treeNode<T,S>* remNode = findNode(key, root);
    treeNode<T,S>* tempNode = remNode;

    if (remNode == NULL) {
        return false; // node not found
    }


    if (remNode->right == NULL) {
        if (remNode->left == NULL) {
            if (remNode->parent == NULL) {
                // only node
                root = NULL;
            }
            else {
                if (remNode->parent->right == remNode) {
                    remNode->parent->right = NULL;
                }
                else {
                    remNode->parent->left = NULL;
                }
            }
        }
        else {
            if (remNode->parent == NULL) {
                //no right nodes
                root = remNode->left;
            }
            else {
                if (remNode->parent->right == remNode) {
                    remNode->parent->right = remNode->left;
                }
                else {
                    remNode->parent->left = remNode->left;
                }
            }
            remNode->left->parent = remNode->parent;

        }// if/else left == NULL
    }//if right == NULL
    else {
        //right is not NULL
        tempNode = remNode->right;
        while (true) {
            if (tempNode->left == NULL) {
                //handle tempnodes children
                if (tempNode->parent->left == tempNode) {
                    tempNode->parent->left = tempNode->right;
                }
                else {
                    tempNode->parent->right = tempNode->right;
                }
                if (tempNode->right != NULL) {
                    tempNode->right->parent = tempNode->parent;
                }

                //move tempNode to remNode
                tempNode->left = remNode->left;
                tempNode->right = remNode->right;
                tempNode->parent = remNode->parent;

                if (tempNode->parent == NULL) {
                    root = tempNode;
                }
                else {
                    if (remNode->parent->left == remNode) { tempNode->parent->left = tempNode; }
                    else { tempNode->parent->right = tempNode; }
                }
                if (tempNode->right != NULL) { tempNode->right->parent = tempNode; }//unnecessary if
                if (tempNode->left != NULL) { tempNode->left->parent = tempNode; }
                break;
            }
            else {
                tempNode = tempNode->left;
            }
        }//loop
    }//else

    size--;
    delete remNode;
    return true;
}



////////////////////////////////////////////////////////////////
// binary = operator: assignment
//
// returns:
//   an entirely new tree, calls copy constructor
////////////////////////////////////////////////////////////////
template<typename T, typename S>
map<T,S>* map<T,S>::operator=(const map<T,S>& initMap) {
    destroyTree(root);
    root = copyTree(initMap.root);
    size = initMap.size;

    return this;
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
    if (currNode->key > findKey) {
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
