/*
Node.cpp  - Templated node for use in linked list

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */

#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
public:
    T value;
    Node* next;

    Node() {
        next = NULL;
    }

    Node(T t) {
        value = t;
        next = NULL;
    }

    T getValue() {
        return value;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* n) {
        next = n;
    }
};

#endif
