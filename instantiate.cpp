////////////////////////////////////////////////////////////////
// instantiates the versions of the map and treeNode classes
// that we will use
////////////////////////////////////////////////////////////////

#include "treeNode.cpp"
#include "map.cpp"

// instantiate for map<string,string>
template class map<string,string>;
template class treeNode<string,string>;
template ostream& operator<<(ostream& os, const map<string,string>& dict);

// instantiate for map<int,int>
template class map<int,int>;
template class treeNode<int,int>;
template ostream& operator<<(ostream& os, const map<int,int>& dict);
