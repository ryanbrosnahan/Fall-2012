

#include "websearch.hpp"

websearch::websearch(const char* datafile, const char*searchfile, const char* outfile)
: output(outfile)
, numWords(0)
, totalLookups(0)
, totalwebPages(0)
, totalKeywords(0)
, head(NULL)
{

    readData(datafile);
    displayWords();
    //displayUrls();
    readSearch(searchfile);
    appendtotals();

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

    //std::cout << "word: " << word <<std::endl;

    if(!wordExists(word)) {
        if(word[0] == 0 || word[0] == 32 || word[0] == 9)
            return;
        keyword key;
        key.word = word;
        key.next = NULL;
        key.numResults = 0;
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
    int position = wordLoc(word);
    words[position].numResults++;
    //create the pageNode
    pageNode *pn = new pageNode;
    //pn->url = tempUrl;
    pn->next = NULL;

    //find where the webUrl is
    webUrl *tempUrl;
    if(!head)
        output << "ERROR Cannot find URL matching " << website << std::endl;

    else {
        tempUrl = head;
        if(tempUrl->url == website)
            pn->url = tempUrl;

        else {
            while(tempUrl->next) {
                tempUrl = tempUrl->next;

                if(tempUrl->url == website)
                    pn->url = tempUrl;
            }
        }
    }

    //find where to put the pageNode (the end)
    if(words[position].next) {
        pageNode *tempNode = words[position].next;

        while (tempNode->next)
            tempNode = tempNode->next;

        tempNode->next = pn;
    }
    else
        words[position].next = pn;
}

int websearch::wordLoc(std::string word) {
    int a = 0;
    int b = numWords;
    int c;

    int i = 0;
    int max = log(numWords)/log(2);

    while(i <= max) {
        c = (a + b)/2;

        if (words[c].word == word)
            return c;

        if (words[c].word < word)
            a = c;

        else
            b = c;

        i++;
    }

    return -1;

    output << "ERROR Could not find: " << word << std::endl;
}


int websearch::numLookups(std::string word) {
    int a = 0;
    int b = numWords;
    int c;

    int i = 1;
    int max = log(numWords)/log(2);

    while(i < max) {
        c = (a + b)/2;

        if (words[c].word == word || c == a || c == b)
            break;

        if (words[c].word < word)
            a = c;

        else
            b = c;

        i++;
    }

    return i;

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
        std::cout << i << " " << words[i].word << std::endl;
}

//display every url in the list
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
    //output << "add url: " << url << std::endl;

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


void websearch::readSearch(const char* searchfile) {
     //open the file
    std::ifstream data(searchfile);

    //check if it's good
    if(data) {

        //temporary string
        std::string line;

        //go through the file
        while(data.good()) {

            getline(data, line);
            search(line);
        }
    }
}

void websearch::search(std::string search) {
    int position = wordLoc(search);
    totalKeywords++;

    if(position > -1)
        displayPages(words[position]);
    else {
        int lookups = numLookups(search);
        totalLookups += lookups;
        output << "test " << search << std::endl;
        output << search << ": " << words[position].numResults << " webpages found, "
                    << lookups << " lookups." << std::endl <<std::endl;
    }

}

void websearch::displayPages(keyword& word) {

    //find where to put the pageNode (the end)
    if(word.next) {
        int lookups = numLookups(word.word);
        totalLookups += lookups;
        int results = word.numResults;
        totalwebPages += results;
        output << word.word << ": " << results << " webpages found, "
                    << lookups << " lookups." << std::endl;
        pageNode *tempNode = word.next;

        while (tempNode->next) {
            output << tempNode->url->url << std::endl;
            tempNode = tempNode->next;
        }

        output << tempNode->url->url << std::endl <<std::endl;
    }
}


void websearch::appendtotals() {
    output << "TOTALS: " << totalKeywords << " keywords, "
                << totalwebPages << " web pages returned, "
                << totalLookups << " keyword lookups." << std::endl;
}

