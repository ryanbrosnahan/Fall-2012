#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

class websearch {

private:

    //each url is tied together in a list
    struct webUrl{
        std::string url;
        webUrl* next;
    };

    //keywords each have a list of pageNodes that point to the various webUrl containing relevant keywords
    struct pageNode{
        webUrl* url;
        pageNode* next;
    };

    //the leftmost array in the diagram, each keyword is listed once, with a list of pageNodes for each
    struct keyword{
        std::string word;
        pageNode* next;
    };

    //array of keywords
    keyword words[1000];
    int numWords;

    webUrl* head;


public:
    websearch(const char*, const char*, const char*);
    websearch();

    void readData(const char*);
    void addsite(std::string);
    void insertWord(std::string, std::string);
    bool wordExists(std::string);
    bool compare(keyword*, keyword*);
    void sortWords();
    void displayWords();
    void addPageNode(std::string, std::string);
    void displayUrls();
    void addWebUrl(std::string);

};



websearch::websearch(const char* datafile, const char*searchfile, const char* outfile) {
    numWords = 0;
    head = NULL;
    readData(datafile);
    displayWords();
    displayUrls();

}

websearch::websearch() {
}

/*
@ desc reads the datafile and sends each line to the addsite function
@ param the name of the datafile
 */
void websearch::readData(const char* datafile) {

    //open the file
    std::ifstream data(datafile);

    //check if it's good
    if(data) {

        //temporary string
        std::string line;

        //go through the file
        while(data.good()) {

            getline(data, line);

            //add the website
            addsite(line);
        }
    }

    sortWords();
}

void websearch::addsite(std::string site) {

    std::vector<std::string> strings;
    std::stringstream stream(site);
    std::string item;

    while (getline(stream, item, ' ')) {
        strings.push_back(item);
    }

    if (strings.empty())
        return;

    addWebUrl(strings[0]);


    for (int i = 1; i < strings.size(); i++) {
        insertWord(strings[i], strings[0]);
    }

}



void websearch::insertWord(std::string word, std::string website) {

    if(!wordExists(word)) {
        keyword key;
        key.word = word;
        key.next = NULL;
        words[numWords] = key;
        numWords++;
        sortWords();
    }


    addPageNode(word, website);

}

bool websearch::wordExists(std::string word) {
    for (int i = 0; i < numWords; i++)
        if(words[i].word == word)
            return true;

    return false;
}

void websearch::addPageNode(std::string word, std::string website) {

}

bool websearch::compare(keyword* keyA, keyword* keyB) {
    return keyA->word < keyB->word;
}

//selection sort
void websearch::sortWords() {
    int min;

    for (int j = 0; j < numWords-1; j++) {

    min = j;
        for (int i = j+1; i < numWords; i++) {
            if (words[i].word < words[min].word) {
                min = i;
            }
        }

    if ( min != j )
        std::swap(words[j], words[min]);
    }
}

void websearch::displayWords() {
    for (int i = 0; i < numWords; i++)
        std::cout << words[i].word << std::endl;
}

void websearch::displayUrls() {
    webUrl *temp;

    if(!head)
        return;

    else {
        temp = head;

        while(temp->next) {
            std::cout << temp->url << std::endl;
            temp = temp->next;
        }
        std::cout << temp->url << std::endl;
    }
}

void websearch::addWebUrl(std::string url) {
    //std::cout << "add url: " << url << std::endl;

    //make a new webUrl (a node)
    webUrl *wu = new webUrl;
    wu->next = NULL;
    wu->url = url;

    //if there are no nodes, make it the head
    if(!head)
        head = wu;

    else {
        //to traverse
        webUrl *temp;
        temp = head;

        //get to the end
        while(temp->next)
            temp = temp->next;

        //last node is the new one
        temp->next = wu;
    }
}

