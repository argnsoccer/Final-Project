#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <functional>

#include "indexer.h"
using namespace std;

class Query
{
public:
    Query();
    void run(Indexer *i, vector<Pages> &pages);
    bool removeStopWords(string& word);

private:
    string str;
    vector<string> words;
    bool checkSingleWord(string temp);
    bool checkOpp(string temp);
    string getNextWord();
    bool getSearchWords();

};

#endif // QUERY_H
