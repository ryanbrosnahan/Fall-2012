/*
ListStack.cpp  - Linked list implementation of a stack

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */

#include <cstdlib>
#include <iostream>
#include "Node.cpp"

template <class T>
class ListStack {
private:

    ListStack(const ListStack<T>&);  // disable copy constructor
    Node<T>* head;
    Node<T>* node;
    Node<T>* temp;
    int elements;

public:

    ListStack() {
        head = NULL;
        elements = 0;
    }

    virtual ~ListStack() {
    	while(!isempty())
    		pop();
    }

    void push(T val) {

    	node = new Node<T>(val);

    	if(!isempty()) {
    		temp = head;
    		head = node;
    		node->setNext(temp);
    	}

    	else {
    		head = node;
    	}

    	elements++;
    	return;
    }


    T pop() {
        if (!isempty()){

        	T val = head->getValue();
     		head = head->getNext();
            elements--;
            return val;
        }

        return 0;
    }

    bool isempty() {
        return !(bool)elements;
    }
};
