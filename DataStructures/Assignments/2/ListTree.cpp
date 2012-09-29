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
	ListTree();
	ListTree(T);

	// Destructor
	~ListTree();

	T sum(TreeNode<T> *);


	void display();
	void displayPre(TreeNode<T> *);

	void insert(T);
	void addTreeNode(TreeNode<T> *, T);

	void deleteTreeNode(T);

};

template <typename T>
ListTree<T>::ListTree() {
	head = NULL;
}

template <typename T>
ListTree<T>::ListTree(T val) {
	TreeNode<T> temp;
	temp->value = val;
	head = temp;
}

template <typename T>
ListTree<T>::~ListTree() {

}

template <typename T>
void ListTree<T>::display() {
	ListTree<T>::displayPre(head);
}

template <typename T>
void ListTree<T>::displayPre(TreeNode<T> *node) {
	if (node != NULL) {
		cout << node->value << " ";
		ListTree<T>::displayPre(node->left);
		ListTree<T>::displayPre(node->right);
	}
}

template <typename T>
void ListTree<T>::insert(T val) {
	ListTree<T>::addTreeNode(head, val);
}

template <typename T>
void ListTree<T>::addTreeNode(TreeNode<T> *node, T val) {
	if(node == NULL)
		node = new TreeNode<T>(val);
	else if(val < node->value)
		addTreeNode(node->left, val);
	else
		addTreeNode(node->right, val);
}

template <typename T>
T ListTree<T>::sum(TreeNode<T> *node) {
	if(node->value == NULL)
		return NULL;

	return (node->value + sum(node->left) + sum(node->right));
}