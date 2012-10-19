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

	void buildTree(const char*);
	void makeTreefile();
	void makeCode();

	void encode(const char*, const char*);

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

/*
Opens the file which is a frequency file and uses it to create a file with the tree and a file with
and the bit code assignments for each letter.
 */
void HuffmanTree::buildTree(const char* fileName) {
	std::ifstream freqfile;
	freqfile.open(fileName);
	char letter;
	int freq;
	head = new HuffmanNode;

	while (freqfile.good()) {
		freqfile >> letter >> freq;
		std::cout << letter << " " << freq << std::endl;
		head->addLetter(letter, freq);
	}

	freqfile.close();

	makeTreefile();
	makeCode();
}

void HuffmanTree::makeTreefile() {

}

void HuffmanTree::makeCode() {

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
