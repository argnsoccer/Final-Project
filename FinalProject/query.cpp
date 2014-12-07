#include "query.h"

using namespace std;

Query::Query()
{



}

void Query::run(Indexer *i, vector<Pages> &pages)
{
    getSearchWords();
    vector<Pages> resultPages;
    resultPages = i->searchFile(words.at(0), pages);

//      for(int i = 0; i < words.size(); i++) //display contents of vector
//      {
//          cout <<"at "<< i << ":" <<words.at(i) << endl;
//      }

}

void Query::getSearchWords()
{
    cout << "enter shit here: ";
    getline(cin,str);

    char * cstr = new char [str.length()+1];
    strcpy (cstr, str.c_str());

    // cstr now contains a c-string copy of str

    char * p = strtok (cstr," ");
    while (p!=0)
    {
      words.push_back(p);
      p = strtok(NULL," ");
    }

    delete[] cstr;
}

bool Query::checkSingleWord(string temp)
{
    if(temp == "OR" || temp == "AND" || temp == "NOT")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Query::checkOpp(string temp)
{
    if(temp == "AND" || temp == "OR" || temp == "NOT")
        return true;
    else
        return false;
}

string Query::getNextWord()
{

}
