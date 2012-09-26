/*
ListTree.cpp  - Templated binary tree using list

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */


#include <cstdlib>
#include <iostream>
#include "TreeTreeNode.cpp"

using namespace std;

template <typename T>
class ListTree {
	private:
	TreeTreeNode<T> *head; // List head pointer

	public:
	// Constructor
	ListTree() {
		head = NULL;
	}

	// Destructor
	~ListTree();

	T sum();

	void insertTreeNode(T);
	void deleteTreeNode(T);
	void displayList() const;

};


T ListTree::sum(TreeNode* node) {
	if(node->value == NULL)
		return NULL;
	else
		return (sum)	
}

