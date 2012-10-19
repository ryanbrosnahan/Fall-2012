

#include "HuffmanTree.hpp"

int main() {

    HuffmanTree HT;
    HT.buildTree("freqfile.txt");


    HT.encode("code.txt", "messagefile.txt");

    return 0;
}