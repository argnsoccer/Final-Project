#ifndef PARSER_H
#define PARSER_H
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "stemmer.h"
#include "AVLTree.h"
#include <string>
#include <iostream>
#include <cstring>
#include <set>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <functional>
#include <vector>

using namespace rapidxml;
using namespace std;

class Parser
{
public:
    Parser();
    ~Parser(){delete AVLIndex;}
    void prepWord(string &word);
    bool removeStopWords(string &word);
    void relevancyRanking();
    vector<Pages> getPages();
    AVLTree* parse(char *fileName);
    int getWordCount();

private:
    int wordCount;
    file<> *inputFile;
    xml_node<> *curNode;
    AVLTree* AVLIndex;
    vector<Pages> pages;
    Pages webPage;

};

inline vector<Pages> Parser::getPages()
{
    return pages;
}

inline int Parser::getWordCount()
{
    return wordCount;
}

#endif // PARSER_H
