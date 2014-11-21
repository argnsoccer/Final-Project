#include "parser.h"

Parser::Parser()
{
}

string Parser::parse(char *fileName)
{
    xml_document<> doc;
    inputFile = new file<>(fileName);
    doc.parse<0>((*inputFile).data());
    curNode = doc.first_node()->first_node();
    curNode = curNode->next_sibling("page"); //goes to first <page> marking
    curNode = curNode->next_sibling("page");
    curNode = curNode->next_sibling("page");
    while(curNode != nullptr)
    {
        cout << "firstNode: " << curNode->first_node()->value() << endl;
        curNode = curNode->first_node();
        curNode = curNode->first_node();
        curNode = curNode->next_sibling("text");
        cout << "nextSibling: " << curNode->next_sibling()->value() << endl;
    }



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
