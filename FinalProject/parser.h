#ifndef PARSER_H
#define PARSER_H
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "english_stem.h"
#include "AVLTree.h"
#include <string>
#include <iostream>
#include <cstring>
#include <set>
#include <fstream>

using namespace rapidxml;
using namespace std;

class Parser
{
public:
    Parser();
    string stem(string &word);
    bool removeStopWords(string &word);
    void relevancyRanking();
    string parse(char *fileName);

private:
    file<> *inputFile;
    xml_node<> *curNode;
    AVLTree AVLindex;

};

#endif // PARSER_H
