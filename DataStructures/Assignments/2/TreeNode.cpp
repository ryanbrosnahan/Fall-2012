/*
TreeNode.cpp  - Templated node for use in linked list

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */

#ifndef TREENODE_CPP
#define TREENODE_CPP

template<class T>
class TreeNode {
public:
    T value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        left = right = NULL;
        value = NULL;
    }

    TreeNode(T t) {
        value = t;
        left = right = NULL;
    }

};

#endif
