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
#include "HuffmanNode.hpp"

class HuffmanTree {
	private:
	HuffmanNode *head;
	std::vector<HuffmanNode*> nodeVector;

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

	void printVector();
	void sortVector();

	void encode(const char*, const char*);

};


HuffmanTree::HuffmanTree() {
	head = new HuffmanNode;
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

	//fill the nodeVector with nodes, each having a letter, frequency pair
	while (freqfile.good()) {
		freqfile >> letter >> freq;
		//std::cout << letter << " " << freq << std::endl;
		HuffmanNode* node;
		node = new HuffmanNode;
		node->addLetter(letter, freq);
		nodeVector.push_back(node);
	}

	freqfile.close();

	makeTreefile();
	makeCode();
}

void HuffmanTree::makeTreefile() {

}

void HuffmanTree::makeCode() {

}

void HuffmanTree::printVector() {

	for(int i = 0; i < nodeVector.size(); ++i) {
		for (int n = 0; n < nodeVector[i]->letters.size(); ++n)
			std::cout << nodeVector[i]->letters[n].letter << " " << nodeVector[i]->letters[n].frequency << std::endl;
	}
}

void HuffmanTree::sortVector() {
	std::sort(nodeVector.begin(), nodeVector.end());
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
