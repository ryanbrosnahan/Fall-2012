#include <cstring>
#include <iostream>
#include "websearch.hpp"

int main(int argc, char *argv[]) {
    if(argc != 4) {
        std::cout << "This program requires 4 arguments. Example invocation:" << std::endl <<std::endl
                    << "test datafile.txt searchfile.txt outputfile.txt" << std::endl;
        return 1;
    }


    std::cout << "Datafile: " << argv[1] << " Searchfile: " << argv[2] << " Outputfile: " << argv[3] <<std::endl;
    websearch* ws = new websearch(argv[1], argv[2], argv[3]);


    return 0;

}
