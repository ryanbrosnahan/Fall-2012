/*
HuffmanNode.cpp  - Templated node for use in binary tree

This is a pretty genious way of implementing the Huffman logic.

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */


#include <vector>

#ifndef HUFFMANNODE_HPP
#define HUFFMANNODE_HPP


class HuffmanNode {
public:

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
        left = right = NULL;
    }

    //constructor for a node with a letter + frequency pair
    HuffmanNode(char letter, int freq) {
        addLetter(letter, freq);
        left = right = NULL;
    }


    /*
    @desc Complex constructor takes 2 nodes and makes them the children of this
    newly contructed node. By definition, the parent must have the data from the
    children, so their members are each copied into the new node as well
    @param a The first node, should be the lesser of the 2
    @param b The second node, should be the greater of the 2
    @return void
     */
    HuffmanNode(HuffmanNode* a, HuffmanNode* b) {
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

    //displays a node in the format "(letter: freq, letter: freq, ... letter: freq)(totalfreq)"
    void displayNode() {
        int sum = 0;
        std::cout << "(";
        for (int i = 0; i < letters.size(); ++i) {
            std::cout << letters[i].letter << ": " <<letters[i].frequency << ", ";
            sum+=letters[i].frequency;
        }
        std::cout << ")(" << sum << ")";
    }

    //overloaded < operator used by std::algorithm in HuffmanTree.hpp to sort the nodes
    //friend bool operator<(const HuffmanNode& nodea, const HuffmanNode& nodeb);

    friend bool compare(HuffmanNode* nodea, HuffmanNode* nodeb);

};

/*
@params nodea < nodeb
@return bool(nodea < nodeb) evaluated
 */
bool compare(HuffmanNode* nodea, HuffmanNode* nodeb)  {
    int sumA = 0;
    int sumB = 0;

    for (int i = 0; i < nodea->letters.size(); ++i)
        sumA += nodea->letters[i].frequency;

    for (int i = 0; i < nodeb->letters.size(); ++i)
        sumB += nodeb->letters[i].frequency;

    if (sumA == sumB) {
        if(nodeb->letters.size() == nodea->letters.size())
            return nodeb->letters[0].letter > nodea->letters[0].letter;

        return nodeb->letters.size() < nodea->letters.size();
    }
    return sumA < sumB;
}


#endif
