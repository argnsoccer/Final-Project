#ifndef PARSER_H
#define PARSER_H
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "AVLTree.h"
#include <string>
#include <iostream>

using namespace rapidxml;
using namespace std;

class Parser
{
public:
    Parser();
    string stem();
    string removeStopWords();
    void relevancyRanking();
    string parse(char *fileName);

private:
    file<> *inputFile;
    xml_node<> *curNode;
    AVLTree index;

};

#endif // PARSER_H
