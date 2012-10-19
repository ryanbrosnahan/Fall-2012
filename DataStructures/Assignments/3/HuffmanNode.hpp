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

    struct letterPair{
        int frequency;
        char letter;
    };

    std::vector <letterPair> letters;

    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode() {
        left = right = NULL;
    }

    HuffmanNode(char letter, int freq) {

        addLetter(letter, freq);

        left = right = NULL;
    }

    void addLetter(char letter, int freq) {

        letterPair pair;
        pair.letter = letter;
        pair.frequency = freq;
        std::cout << pair.letter << " " << pair.frequency <<std::endl;
        letters.push_back(pair);

    }

};

#endif
