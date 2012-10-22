

#include "HuffmanTree.hpp"
#include <cstring>

int main(int argc, char *argv[]) {
    if(argc != 5) {
        std::cout << "This program requires 4 arguments. Example invocations:" << std::endl <<std::endl
                    << "test buildtree <freqfile.txt> <treefile.txt> <code.txt>" << std::endl
                    << "test encode <code.txt> <messagefile.txt> <encodedmessage.bin>" << std::endl
                    << "test decode <treefile.txt> <encodedmessage.bin> <messagefile.txt>" << std::endl;
        return 1;
    }



    if(!strcmp(argv[1], "buildtree")) {
        std::cout << "opening: " << argv[2] << " creating: " << argv[3] << " and " << argv[4] <<std::endl;
        HuffmanTree HT;
        HT.buildTree(argv[2], argv[3], argv[4]);
    }

    else if(!strcmp(argv[1], "encode")) {
        std::cout << "opening: " << argv[2] << " and " << argv[3] << " creating: " << argv[4] <<std::endl;
        HuffmanTree HT;
        HT.encode(argv[2], argv[3], argv[4]);
    }

    else if(!strcmp(argv[1], "decode")) {
        std::cout << "opening: " << argv[2] << " and " << argv[3] << " creating: " << argv[4] <<std::endl;
        HuffmanTree HT;
        HT.decode(argv[2], argv[3], argv[4]);
    }

    return 0;


}
