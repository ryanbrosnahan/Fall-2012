/*
HuffmanTree.cpp  - Huffman Tree

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */


#include <iostream>
#include "HuffmanNode.hpp"

class HuffmanTree {
	private:
	HuffmanNode *head;

	public:
	// Constructor
	HuffmanTree();
	HuffmanTree(char);

	// Destructor
	~HuffmanTree();
	void deleteHuffmanNode(HuffmanNode *&);

};


HuffmanTree::HuffmanTree() {
	head = NULL;
}

HuffmanTree::HuffmanTree(char val) {
	//insert(val);
}

HuffmanTree::~HuffmanTree() {
	deleteHuffmanNode(head);
}

void HuffmanTree::deleteHuffmanNode(HuffmanNode *&node) {
	if(node != NULL) {
		deleteHuffmanNode(node->left);
		deleteHuffmanNode(node->right);
		delete node;
	}

	node = NULL;
}



