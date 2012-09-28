/*
ListTree.cpp  - Templated binary tree using list

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */


#include <cstdlib>
#include <iostream>
#include "TreeNode.cpp"

using namespace std;

template <typename T>
class ListTree {
	private:
	TreeTreeNode<T> *head; // List head pointer

	public:
	// Constructor
	ListTree();

	// Destructor
	~ListTree();

	T sum();

	void addTreeNode(T);
	void deleteTreeNode(T);
	void displayList() const;

};

template <typename T>
T ListTree::sum(TreeNode<T>* node) {
	if(node->value == NULL)
		return NULL;
	else
		return (node->value + sum(node->left) + sum(node->right));
}

template <typename T>
void ListTree::addTreeNode(T val) {

	if(head == NULL) {
		head->value = val;
		return;
	}

	TreeNode<T> temp = head;
	while(temp->left != NULL || temp->right != NULL)

		if(temp->value > val) {

			if(temp->left == NULL) {
				temp = temp->left;
			}

		}

		temp = temp->right;
	}

	

}