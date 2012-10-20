

#include "HuffmanTree.hpp"

int main() {

    HuffmanTree HT;
    HT.buildTree("freqfile.txt");
    HT.printVector();
    HT.sortVector();
    std::cout << std::endl;
    HT.printVector();


    HuffmanNode HN;
    HN.addLetter('a', 3);
    HN.addLetter('b', 1);

    HuffmanNode HNb;
    HNb.addLetter('a', 3);

    if(HN < HNb)
        std::cout << "y";


    //HT.encode("code.txt", "messagefile.txt");

    return 0;
}