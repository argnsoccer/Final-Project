#include "parser.h"

Parser::Parser()
{
}

string Parser::parse(char *fileName)
{
    xml_document<> doc;
    inputFile = new file<>(fileName);
    doc.parse<0>((*inputFile).data());
    parentNode = new xml_node<string>(doc.first_node(0));
    doc.first_node(0)->first_node(0)->next_sibling("page"); //goes to first <page> marking



}

string removeStopWords()
{

}





















//IndexInterface
//virtual ~IndexInterface();
//virtual void addToIndex(string&, int) = 0;
//virtual void removeFromIndex(string&) = 0;
//virtual vector<int> search(string&) = 0;
//virtual bool contains(string&) = 0;
//virtual vector<Data <string, int> >* save() = 0;
//virtual void load(vector<Data<string, int> >&) = 0;
//virtual void printReverseFileIndex() = 0;
//virtual void deleteIndexes() = 0;
