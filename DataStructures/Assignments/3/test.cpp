

#include "HuffmanTree.hpp"

int main() {

    HuffmanTree HT;
    HT.buildTree("freqfile.txt");
   // HT.printVector();
   // HT.sortVector();
    std::cout << std::endl;
    //HT.printVector();
    std::cout << std::endl;

    //HT.displayPre();


    return 0;
}