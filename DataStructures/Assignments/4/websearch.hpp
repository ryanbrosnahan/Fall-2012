#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>

#ifndef INCLUDED_WEBSEARCH_HPP
#define INCLUDED_WEBSEARCH_HPP

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
        int numResults;
    };

    //array of keywords
    keyword words[1000];
    int numWords;

    webUrl* head;

    int totalKeywords;
    int totalwebPages;
    int totalLookups;

    std::ofstream output;


public:
    websearch(const char*, const char*, const char*);

    void readData(const char*);
    void addsite(std::string);
    void insertWord(std::string, std::string);
    bool wordExists(std::string);
    void sortWords();
    void displayWords();
    void addPageNode(std::string, std::string);
    void displayUrls();
    void addWebUrl(std::string);
    int wordLoc(std::string);
    int numLookups(std::string);

    void readSearch(const char*);
    void search(std::string);
    void displayPages(keyword&);
    void appendtotals();
    void writeout(const char*);

};


#endif