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
	TreeNode<T> *head;

	public:
	// Constructor
	ListTree() {
		head = NULL;
	}

	// Destructor
	~ListTree();

	T sum(TreeNode<T> *);

	void addTreeNode(T);
	void deleteTreeNode(T);
	void displayPre(TreeNode<T> *);

};

template <typename T>
ListTree<T>::~ListTree() {

}

template <typename T>
void ListTree<T>::displayPre(TreeNode<T> *node = head) {
	if ( node != NULL ) {
		cout << node->item << " ";
		preorderPrint( node->left );
		preorderPrint( node->right );
	}
}

template <typename T>
T ListTree<T>::sum(TreeNode<T> *node) {
	if(node->value == NULL)
		return NULL;

	return (node->value + sum(node->left) + sum(node->right));
}

template <typename T>
void ListTree<T>::addTreeNode(T val) {

	if(head == NULL) {
		head->value = val;
		return;
	}

	TreeNode<T> *temp = head;
	while(temp->left != NULL || temp->right != NULL) {

		if(temp->value > val) {

			if(temp->left == NULL) {
				temp = temp->left;
			}

		}

		temp = temp->right;
	}
}


