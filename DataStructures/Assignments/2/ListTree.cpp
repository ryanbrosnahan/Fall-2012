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
	insert(val);
}

template <typename T>
ListTree<T>::~ListTree() {

}

template <typename T>
void ListTree<T>::display() {
	displayPre(head);
	std::cout << "test1";
}

template <typename T>
void ListTree<T>::displayPre(TreeNode<T> *node) {
	if (node != NULL) {
		cout << node->value << " ";
		displayPre(node->left);
		displayPre(node->right);
			std::cout << "test2";
	}
		std::cout << "test3";
}

template <typename T>
void ListTree<T>::insert(T val) {

	addTreeNode(head, val);
	return;
}

template <typename T>
void ListTree<T>::addTreeNode(TreeNode<T> *node, T val) {
	if(node == NULL)
		node = new TreeNode<T>(val);
	else if(val < node->value)
		addTreeNode(node->left, val);
	else
		addTreeNode(node->right, val);
	return;
}

template <typename T>
T ListTree<T>::sum(TreeNode<T> *node) {
	if(node->value == NULL)
		return NULL;

	std::cout << node->value << std::endl;
	return (node->value + sum(node->left) + sum(node->right));
}