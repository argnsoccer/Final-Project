#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Query
{
public:
    Query();
    void run();

private:
    string str;
    vector<string> words;
    bool checkSingleWord(string temp);
    bool checkOpp(string temp);
    string getNextWord();

};

#endif // QUERY_H
