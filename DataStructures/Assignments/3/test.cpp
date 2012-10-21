

#include "HuffmanTree.hpp"
#include <cstring>

char* trimBrackets(char*);

int main(int argc, char *argv[]) {
       // std::cout << trimBrackets(argv[1]) << std::endl;

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
        //HT.encode(argv[2], argv[3], argv[4]);
    }

    else if(!strcmp(argv[1], "decode")) {
        std::cout << "opening: " << argv[2] << " and " << argv[3] << " creating: " << argv[4] <<std::endl;
        HuffmanTree HT;
        //HT.decode(argv[2], argv[3], argv[4]);
    }



}


/*
@desc Command line input arguments are filenames; in the case of windows the arguments need to
        be surrounded by <> brackets, or cmd will think bad things. But in the case of bash, it
        isn't necessary. This program doesn't take advantage of Bash piping feature.
        See http://codeidol.com/unix/suse/Cool-Shell-Tricks/Piping-and-Directing-Output/
@param the char[] argument passed from the command line
@return the char[] trimmed if brackets <> are present
 */
char* trimBrackets(char* argument) {
    char *trimmed = new char;
    if(argument[0] == 60) {
        for(int i = 1; i = strlen(argument) - 2; ++i)
             trimmed[i-1] = argument[i];
        return trimmed;
    }
    return argument;
}