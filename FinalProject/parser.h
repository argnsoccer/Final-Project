#ifndef PARSER_H
#define PARSER_H
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "stemmer.h"
#include "AVLTree.h"
#include "pages.h"
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
    ~Parser(){delete AVLindex;}
    void prepWord(string &word);
    bool removeStopWords(string &word);
    void relevancyRanking();
    vector<Pages> getPageObject();
    AVLTree* parse(char *fileName);

private:
    file<> *inputFile;
    xml_node<> *curNode;
    AVLTree* AVLindex;
    vector<Pages> pages;
    Pages webPage;

};

inline vector<Pages> Parser::getPageObject()
{
    return pages;
}

#endif // PARSER_H
