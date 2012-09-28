/*
Node.cpp  - Templated node for use in linked list

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */

#ifndef TREENODE_H
#define TREENODE_H

template<class T>
class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node() {
        left = right = NULL;
        value = NULL;
    }

    Node(T t) {
        value = t;
        left = right = NULL;
    }

};

#endif
