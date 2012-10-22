/*
HuffmanNode.cpp  - Templated node for use in binary tree

This is a pretty genious way of implementing the Huffman logic.

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */


#include <vector>
#include <cstring>

#ifndef HUFFMANNODE_HPP
#define HUFFMANNODE_HPP


class HuffmanNode {
public:

    //trees may be sorted based on when they were created
    double timestamp;

    //each leaf has a letter and its frequency
    struct letterPair{
        int frequency;
        char letter;
    };

    //every node contains all letters and their respective freqencies from
    //all nodes below it; from this the frequency of an inner node can be
    //derived and traversal is faster for decoding
    std::vector <letterPair> letters;

    //pointers to the left and right children of a node
    HuffmanNode* left;
    HuffmanNode* right;

    //default contructor
    HuffmanNode() {
        timestamp = 0;
        left = right = NULL;
    }

    //constructor for a node with a letter + frequency pair
    HuffmanNode(char letter, int freq) {
        timestamp = 0;
        addLetter(letter, freq);
        left = right = NULL;
    }

    HuffmanNode(std::string l) {
        timestamp = 0;
        left = right = NULL;

        for(int i = 0; i < l.length(); i++) {
            addLetter(l[i], -1);
        }
    }

    /*
    @desc Complex constructor takes 2 nodes and makes them the children of this
    newly contructed node. By definition, the parent must have the data from the
    children, so their members are each copied into the new node as well
    @param a The first node, should be the lesser of the 2
    @param b The second node, should be the greater of the 2
    @return void
     */
    HuffmanNode(HuffmanNode* a, HuffmanNode* b, int t) {
        //timestamp (psuedotime) from the tree
        timestamp = t;

        //initialize left and right to null
        left = right = NULL;

        //for each member of the vector in a, append one in the new HuffmanNode
        for (int i = 0; i < a->letters.size(); ++i)
            addLetter(a->letters[i].letter, a->letters[i].frequency);

        //for each member of the vector in b, append one in the new HuffmanNode
        for (int i = 0; i < b->letters.size(); ++i)
            addLetter(b->letters[i].letter, b->letters[i].frequency);

        //make the parameter nodes children of the new one
        left = a;
        right = b;

    }

    /*
    @desc add a letter + frequency pair to the vector of pairs in the node
    @param letter the letter
    @param freq the frequency of occurence for that letter
    @return void
     */
    void addLetter(char letter, int freq) {
        //create a new letterPair struct and push it to the vector
        letterPair pair;
        pair.letter = letter;
        pair.frequency = freq;
        letters.push_back(pair);

    }

    int getWeight(){
        int weight =  0;
        for (int i = 0; i < letters.size(); ++i)
            weight += letters[i].frequency;
        return weight;
    }

    //displays a node in the format "(letter: freq, letter: freq, ... letter: freq)(totalfreq)"
    void displayNode() {
        int sum = 0;
        std::cout << "(";
        for (int i = 0; i < letters.size(); ++i) {
            std::cout << letters[i].letter << ": " <<letters[i].frequency << ", ";
            sum+=letters[i].frequency;
        }
        std::cout << ")(" << sum << ")(" << timestamp << ")";
    }

    bool letterExists(char l) {
        for (int i = 0; i < letters.size(); ++i)
            if(letters[i].letter == l)
                return 1;
        return 0;
    }

    bool isLeaf() {
        return (left == NULL && right == NULL);
    }

    //overloaded < operator used by std::algorithm in HuffmanTree.hpp to sort the nodes
    //friend bool operator<(const HuffmanNode& nodea, const HuffmanNode& nodeb);

};

/*
@desc for special cases of space, newline, eof, and period, the ascii is adjusted so
the order is correct relative to the other alphanumeric values
@param letter The letter to be converted
@return if it is a special case, it returns the new ascii, otherwise it returns the input unchanged
 */
char convert(char letter) {
    if (letter == char(45))
        return 123;
    if (letter == char(46))
        return 124;
    if (letter == char(33))
        return 125;
    if (letter == char(43))
        return 126;
    return letter;
}

/*
@params nodea < nodeb
@return bool(nodea < nodeb) evaluated
 */
bool compare(HuffmanNode* nodea, HuffmanNode* nodeb)  {

    //get the "weight" of both the left and right trees
    int sumA = nodea->getWeight();
    int sumB = nodeb->getWeight();

    //if the weight of both nodes is equal
    if (sumA == sumB) {

        //if they are both leaf nodes, use order in aphabet
        if(nodea->isLeaf() && nodeb->isLeaf()) {
            //run the convert function on each leaf and compare
            char a = convert(nodea->letters[0].letter);
            char b = convert(nodeb->letters[0].letter);
            return a < b;
        }

        //at least one of the nodes must be an inner branch; leaves get lower priority
        if(nodea->isLeaf())
            return 0;
        if(nodeb->isLeaf())
            return 1;

        //if both are inner branches, compare by most recently created
        return nodeb->timestamp < nodea->timestamp;
    }

    //if the weights are different, evaluate
    return sumA < sumB;
}





#endif
