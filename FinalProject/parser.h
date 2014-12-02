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

using namespace rapidxml;
using namespace std;

class Parser
{
public:
    Parser();
    string stemWord(string &word);
    bool removeStopWords(string &word);
    void relevancyRanking();
    void parse(char *fileName);

private:
    file<> *inputFile;
    xml_node<> *curNode;
    AVLTree AVLindex;

};

#endif // PARSER_H
