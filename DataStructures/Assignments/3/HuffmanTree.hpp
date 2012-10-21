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
#include <cstdlib>
#include "HuffmanNode.hpp"

class HuffmanTree {
private:
	std::deque<HuffmanNode*> nodeDeque;
	std::string tree;

public:
	// Constructor
	HuffmanTree();
	HuffmanTree(char);

	// Destructor
	~HuffmanTree();
	void deleteHuffmanNode(HuffmanNode *&);

	void buildTree(const char*, const char*, const char*);
	void makeTree();

	void generateCodefile(const char*);
	std::string getLetterCode(const char);

	void generateTreeFile(const char* );
	void generateTreeFile(HuffmanNode *);

	void printDeque();
	void displayPre();
	void displayPre(HuffmanNode *);
	void sortDeque();

	void encode(const char*, const char*, const char*);

};


HuffmanTree::HuffmanTree() {
}


HuffmanTree::~HuffmanTree() {
	deleteHuffmanNode(nodeDeque[0]);
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
void HuffmanTree::buildTree(const char* freqfileName, const char* treefileName, const char* codefileName) {

	//create a handle and open the file
	std::ifstream freqfile;
	freqfile.open(freqfileName);

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
	generateTreeFile(treefileName);
	generateCodefile(codefileName);
}

/*
@desc combines the nodes in nodeDeque member into a single tree with head at nodeDeque[0]
 */
void HuffmanTree::makeTree() {

	//in the sort, trees may be compared based on time created; faking it is ok!
	int psuedotime = 0;

	//while the tree isn't finished
	while (nodeDeque.size() != 1) {

		//increment the time for the next node
		psuedotime++;

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
		HuffmanNode* c = new HuffmanNode(a, b, psuedotime);
		nodeDeque.push_back(c);

		//uncomment to watch the tree forming
		//nodeDeque[0]->displayNode();
		//printDeque();
	}

}


void HuffmanTree::generateCodefile(const char* codefileName) {
	std::ofstream codefile;
	codefile.open(codefileName);

	for (int i = 0; i < nodeDeque[0]->letters.size(); i++){
		char currentLetter = nodeDeque[0]->letters[i].letter;
		codefile << currentLetter << " " << getLetterCode(currentLetter) << std::endl;
	}

	codefile.close();

}

std::string HuffmanTree::getLetterCode(const char l) {
	std::string code = "";
	HuffmanNode* temp = nodeDeque.front();

	if(!temp->letterExists(l)) {
		std::cout << "This letter does not exist in the tree";
		return "";
	}


	while( !(temp->isLeaf()) ){

		if(temp->left->letterExists(l)) {
			code += "0";
			temp = temp->left;
		}
		else if(temp->right->letterExists(l)) {
			code += "1";
			temp = temp->right;
		}

	}


	return code;

}

//prints each node in the deque nodeDeque
void HuffmanTree::printDeque() {
	for(int i = 0; i < nodeDeque.size(); ++i) {
		nodeDeque[i]->displayNode();
		std::cout << std::endl;
	}
	std::cout << std::endl;
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

//calls the recursive function generateTreeFile
void HuffmanTree::generateTreeFile(const char* treefileName) {

	std::ofstream treefile;
	treefile.open(treefileName);

	generateTreeFile(nodeDeque[0]);

	treefile << tree;

	treefile.close();
}

/*
@desc writes a local file called "treefile.txt that "
Key:
	$ = Inner branch
	'letter' = leaf
	/ = null
From this, the tree can be reconstructed
@param node the root of the tree or subtree
@return void; prints to console
 */
void HuffmanTree::generateTreeFile(HuffmanNode* node){

	if (node) {
		if(node->left == NULL && node->right == NULL)
			tree += node->letters[0].letter;
		else
			tree += "$";
		generateTreeFile(node->left);
		generateTreeFile(node->right);
	}
	else
		tree += "/";

}

void HuffmanTree::sortDeque() {
	std::sort(nodeDeque.begin(), nodeDeque.end(), compare);
}

/*
@desc encodes a message to binary
@param bitFileName name of the file containing bitcodes for each letter
@param messageFileName Name of the file containing the message to be encoded
@param encodedMessageFileName the name of the file to be created to hold the encoded message
 */
void HuffmanTree::encode(const char* bitFileName, const char* messageFileName, const char* encodedMessageFileName) {

	//open the 2 files used to encode the message
	std::ifstream bitFile;
	bitFile.open(bitFileName);
	std::ifstream messageFile;
	messageFile.open(messageFileName);

	//the letter and code variables
	char letter;
	std::string code;

	//and a table to hold them
	std::map<char, std::string> codeMap;

	//contruct the table
	while(bitFile.good()) {
		bitFile >> letter >> code;
		codeMap[letter] = code;
	}

	//a string to hold the encoded message
	std::string encodedMessage;

	//stream the ecnoded file to the string
	while(messageFile.good()) {
		messageFile >> letter;
		encodedMessage += codeMap[letter];
	}

	std::cout << "Encoded String: " << encodedMessage <<std::endl;

	//open (create) a file to put the encoded message
	std::ofstream encodedFile;
	encodedFile.open(encodedMessageFileName);

	std::cout << "messagelength: " << encodedMessage.length() << "iterations: " << int(encodedMessage.length() / 8)<< std::endl;

	//Create the encoded message
	for (int i = 0; i < int(encodedMessage.length() / 8); i++) {

		//string to hold 8 "bits" at a time
		std::string smallString = "00000000";

		//breaks up the encodedMessage string into each 8-"bit" section
		for (int j = 0; j < 8; j++) {
			smallString[j] = encodedMessage[(8*i)+j];
		}

		//8 "bit" code converted to decimal
		int code = 0;

		std::cout << smallString << std::endl;

		smallString = std::string (smallString.rbegin(), smallString.rend());

		for (int n = 0; n < 8; n++) {
			if(smallString[n] == 49)
				code += pow(2, n);
		}

		std::cout << code << std::endl;

		//char typecast is 1 byte
		encodedFile << char(code);
	}


	//close the files
	bitFile.close();
	messageFile.close();
	encodedFile.close();

}
