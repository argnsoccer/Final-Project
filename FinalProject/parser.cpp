#include "parser.h"
#include "AVLTree.h"

Parser::Parser()
{
    AVLTree index;
}

string Parser::parse(char *fileName)
{
    xml_document<> doc;
    inputFile = new file<>(fileName);
    doc.parse<0>((*inputFile).data());
    curNode = doc.first_node()->first_node("page");//goes to first <page> marking
    xml_node<>* titleNode;
    int page = 1;
    for(int i = 0; i < 1000; ++i)
    {
        titleNode = curNode->first_node("title");
        while(titleNode != nullptr)
        {
            cout << "tile: " << titleNode->value() << endl;
            cout << "text: " << titleNode->next_sibling("revision")->first_node("text")->value() << endl;
            titleNode = titleNode->next_sibling("title");

        }
        curNode = curNode->next_sibling("page");
        page++;
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
