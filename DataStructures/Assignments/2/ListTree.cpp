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
	void deleteTreeNode(TreeNode<T> *&);


	T sum(TreeNode<T> *);
	T sumAll();


	void display();
	void displayLess(T);
	void displayLessHidden(TreeNode<T> *, T);
	void displayPre(TreeNode<T> *);

	void insert(T);
	void addTreeNode(TreeNode<T> *&, T);


	int maxDepth();
	int maxDepthHidden(TreeNode<T> *);
	int minDepth();
	int minDepthHidden(TreeNode<T> *);

	bool isBalanced();

	int nodeDepth(T );
	int nodeDepthHidden(TreeNode<T> *, T, int);

	int maxPath();
	int maxPathHidden(TreeNode<T> *, int);


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
	deleteTreeNode(head);
}

template <typename T>
void ListTree<T>::deleteTreeNode(TreeNode<T> *&node) {
	if(node != NULL) {
		deleteTreeNode(node->left);
		deleteTreeNode(node->right);
		delete node;
	}

	node = NULL;
}

template <typename T>
void ListTree<T>::display() {
	displayPre(head);

}

template <typename T>
void ListTree<T>::displayLess(T val) {
	std::cout << "Print all nodes less than " << val << ": ";
	displayLessHidden(head, val);
}

template <typename T>
void ListTree<T>::displayLessHidden(TreeNode<T> *node, T val) {

   if (node != NULL) {
      displayLessHidden(node->left, val);

      if (node->value < val)
         cout << node->value << " ";

      displayLessHidden(node->right, val);
   }
}

template <typename T>
void ListTree<T>::displayPre(TreeNode<T> *node) {
	if (node != NULL) {
		cout << node->value << " ";
		displayPre(node->left);
		displayPre(node->right);
	}
}

template <typename T>
void ListTree<T>::insert(T val) {
	addTreeNode(head, val);
	return;
}

template <typename T>
void ListTree<T>::addTreeNode(TreeNode<T> *&node, T val) {
	if(node == NULL)
		node = new TreeNode<T>(val);
	else if(val < node->value)
		addTreeNode(node->left, val);
	else
		addTreeNode(node->right, val);
	return;
}


template <typename T>
T ListTree<T>::sumAll() {
	return sum(head);
}

template <typename T>
T ListTree<T>::sum(TreeNode<T> *node) {
	if(node == NULL)
		return 0;

	return (node->value + sum(node->left) + sum(node->right));
}

template <typename T>
int ListTree<T>::maxDepth() {
	maxDepthHidden(head);
}

template <typename T>
int ListTree<T>::maxDepthHidden(TreeNode<T> *node) {
	if(node == NULL)
		return 0;

	int left = maxDepthHidden(node->left);
	int right = maxDepthHidden(node->right);

	if(left > right)
		return(left+1);
	else
		return (right+1);
}

template <typename T>
int ListTree<T>::minDepth() {
	minDepthHidden(head);
}

template <typename T>
int ListTree<T>::minDepthHidden(TreeNode<T> *node) {
	if(node == NULL)
		return 0;

	int left = minDepthHidden(node->left);
	int right = minDepthHidden(node->right);

	if(left < right)
		return(left+1);
	else
		return (right+1);
}

template <typename T>
bool ListTree<T>::isBalanced() {
	if((maxDepth() - minDepth()) <= 1)
		return 1;

	return 0;
}

template <typename T>
int ListTree<T>::nodeDepth(T value) {
    return nodeDepthHidden(head, value, 1);
}

template <typename T>
int ListTree<T>::nodeDepthHidden(TreeNode<T> *node, T value, int level) {
    if (node == NULL)
       return 0;

    if (node->value == value)
       return level - 1;

    return max(nodeDepthHidden(node->left, value, level+1), nodeDepthHidden(node->right, value, level+1));
}



template <typename T>
int ListTree<T>::maxPath() {
	return maxPathHidden(head, 0);
}

template <typename T>
int ListTree<T>::maxPathHidden(TreeNode<T> *node, int total){
	if(node == NULL)
		return 0;

	return total + node->value + max(maxPathHidden(node->left, total), maxPathHidden(node->right, total));

}


