/*
* Author: Ryan Brosnahan
*
* A class template for holding a linked list.
* The node type is also a class template.
*/


#include <cstdlib>
#include <iostream>

using namespace std;

/*
* The ListNode class creates a type used to
* store a node of the linked list.
*/
template <typename T>
class ListNode {
	public:
	T value; // Node value
	ListNode<T> *next; // Pointer to the next node

	// Constructor
	ListNode (T nodeValue) {
	value = nodeValue;
	next = NULL;
	}
};

/*
* LinkedList class
*/
template <typename T>
class LinkedList {
	private:
	ListNode<T> *head; // List head pointer

	public:
	// Constructor
	LinkedList() {
		head = NULL;
	}

	// Destructor
	~LinkedList();

	// Linked list operations
	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
	bool findNode(const T& value) const;
	void reverseList();
};

/*
* appendNode
* appends a node containing the value passed
* into newValue, to the end of the list.
*/
template <typename T>
void LinkedList<T>::appendNode(T newValue) {
	ListNode<T> *newNode; // To point to a new node
	ListNode<T> *nodePtr; // To move through the list

	// Allocate a new node and store newValue there
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list, make newNode the first node
	if (!head)
		head = newNode;

	else {
		nodePtr = head;

		// Find the last node in the list
		while (nodePtr->next)
		nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

/*
* displayList
* shows the value stored in each node of the linked list pointed
* to by head
*/
template <typename T>
void LinkedList<T>::displayList() const {
	ListNode<T> *nodePtr; // to move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;
	cout << "[ ";

	// While nodePtr points to a node, traverse the list
	while (nodePtr) {
		// Display the value in this node
		cout << nodePtr->value << " ";

		// Move to the next node
		nodePtr = nodePtr->next;
	}

	cout << "]\n";
}

/*
* insertNode
* inserts a node with newValue copied to its value member
*/
template <typename T>
void LinkedList<T>::insertNode(T newValue) {

	ListNode<T> *newNode; // a new node
	ListNode<T> *nodePtr; // to traverse the list
	ListNode<T> *previousNode = NULL; // the previous node

	// Allocate a new node and store newValue there
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list, make the newNode the first
	// node
	if (!head) {
		head = newNode;
		newNode->next = NULL;
	}

	else {
		// Position nodePtr at the head of list
		nodePtr = head;

		// Initializes previousNode to NULL
		previousNode = NULL;

		// Skip all nodes whose value is less than newValue
		while (nodePtr != NULL && nodePtr->value <= newValue) {
			if (nodePtr->value == newValue)
				return;

			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes
		if (previousNode == NULL) {
			head = newNode;
			newNode->next = nodePtr;
		}

		// otherwise insert after the previous node
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

/*
* deleteNode
* search for a node with searchValue as its value. The node, if
* found, is deleted from the list and from memory
*/
template <typename T>
void LinkedList<T>::deleteNode(T searchValue) {
	ListNode<T> *nodePtr; // to traverse the list
	ListNode<T> *previousNode; // to point to the previous node

	// if the list is empty do nothing
	if (!head)
		return;

	// determine if the first node is the one
	if (head->value == searchValue) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// skip all nodes whose value member is not equal to num
		while (nodePtr != NULL && nodePtr->value != searchValue) {

			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// if nodePtr is not at the end of the list, link the previous
		// node to the node after nodePtr, then delete nodePtr
		if (nodePtr) {

			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//searches all active nodes for a value, returns 1 if found
template <class T>
bool LinkedList<T>::findNode(const T& value) const{

	ListNode<T> *searchnode = head;

	while(searchnode != NULL){

		if (searchnode->value == value)
			return 1;

		searchnode = searchnode->next;
	}

	return 0;
}


/*
* Destructor
* This function deletes every node in the list
*/
template <typename T>
LinkedList<T>::~LinkedList() {
	ListNode<T> *nodePtr; // to traverse the list
	ListNode<T> *nextNode; // to point to the next node

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL) {
	// Save a pointer to the next node
	nextNode = nodePtr->next;

	// Delete the current node
	delete nodePtr;

	// Position nodePtr at the next node
	nodePtr = nextNode;
	}
}

template <typename T>
void LinkedList<T>::reverseList() {

	//use some nodes to traverse the list
	ListNode<T> *nodePtr = NULL;
	ListNode<T> *temp = NULL;

	//we will use head to traverse the list
	while(head) {

		temp = head->next;

		head->next = nodePtr;

		nodePtr = head;

		head = temp;

	}

	//re-establish the proper head
	head = nodePtr;

}
