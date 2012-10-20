/*
HuffmanTree.cpp  - Huffman Tree

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <deque>
#include "HuffmanNode.hpp"

class HuffmanTree {
	private:
	std::deque<HuffmanNode*> nodeDeque;

	public:
	// Constructor
	HuffmanTree();
	HuffmanTree(char);

	// Destructor
	~HuffmanTree();
	void deleteHuffmanNode(HuffmanNode *&);

	void buildTree(const char*);
	void makeTree();
	void makeCode();

	void printDeque();
	void displayPre();
	void displayPre(HuffmanNode *);
	void sortDeque();

	void encode(const char*, const char*);

};


HuffmanTree::HuffmanTree() {
}


HuffmanTree::~HuffmanTree() {
}

void HuffmanTree::deleteHuffmanNode(HuffmanNode *&node) {
	if(node != NULL) {
		deleteHuffmanNode(node->left);
		deleteHuffmanNode(node->right);
		delete node;
	}

	node = NULL;
}

/*
Opens the file which is a frequency file and uses it to create a file with the tree and a file with
and the bit code assignments for each letter.
 */
void HuffmanTree::buildTree(const char* fileName) {

	//create a handle and open the file
	std::ifstream freqfile;
	freqfile.open(fileName);

	//create some variables to stream the file into
	char letter;
	int freq;

	//fill the nodeDeque with nodes, each having a letter + frequency pair
	while (freqfile.good()) {
		freqfile >> letter >> freq;
		HuffmanNode* node = new HuffmanNode(letter, freq);
		nodeDeque.push_back(node);
	}

	//close the fole
	freqfile.close();

	//turn this Deque full of nodes into 1 tree
	makeTree();

	//makeCode();
}

/*
@desc combines the nodes in nodeDeque member into a single tree with head at nodeDeque[0]
 */
void HuffmanTree::makeTree() {

	//while the tree isn't finished
	while (nodeDeque.size() != 1) {

		//maintain order of the Huffman Tree
		sortDeque();

		//nodes a and b are the first 2 (lowest) nodes
		//	1. remove them
		//	2. combine them
		//	3. push the new combined node back to the nodeDeque
		HuffmanNode* a = nodeDeque.front();
		nodeDeque.pop_front();
		HuffmanNode* b = nodeDeque.front();
		nodeDeque.pop_front();
		HuffmanNode* c = new HuffmanNode(a, b);
		nodeDeque.push_back(c);

		//uncomment to watch the tree forming
		nodeDeque[0]->displayNode();
	}

}


void HuffmanTree::makeCode() {

}

//prints each node in the deque nodeDeque
void HuffmanTree::printDeque() {
	for(int i = 0; i < nodeDeque.size(); ++i) {
		nodeDeque[i]->displayNode();
	}

}

//calls the recursive function displayPre
void HuffmanTree::displayPre() {
	displayPre(nodeDeque[0]);
}

/*
@desc recursively prints the tree.
Key:
	$ = Inner branch
	'letter' = leaf
	/ = null
From this, the tree can be reconstructed
@param node the root of the tree or subtree
@return void; prints to console
 */
void HuffmanTree::displayPre(HuffmanNode* node) {
	//std::cout << "pre: ";

	if (node) {
		if(node->left == NULL && node->right == NULL)
			std::cout << node->letters[0].letter;
		else
			std::cout << "$";

		displayPre(node->left);
		displayPre(node->right);
	}
	else
		std::cout << "/";

}

void HuffmanTree::sortDeque() {
	std::sort(nodeDeque.begin(), nodeDeque.end(), compare);
}

/*
Opens a file with bit encoding and a message file and creates an
encoded message file.
 */
void HuffmanTree::encode(const char* bitFileName, const char* messageFileName) {
	std::ifstream bitFile;
	bitFile.open(bitFileName);
	std::ifstream messageFile;
	messageFile.open(messageFileName);

	char letter;
	std::string code;

	std::map<char, std::string> codeMap;
	while(bitFile.good()) {
		bitFile >> letter >> code;
		codeMap[letter] = code;
	}

	std::ofstream encodedFile;
	encodedFile.open("encodedMesage.txt");

	while(messageFile.good()) {
		messageFile >> letter;
		encodedFile << codeMap[letter];
	}

	bitFile.close();
	messageFile.close();
	encodedFile.close();

}
