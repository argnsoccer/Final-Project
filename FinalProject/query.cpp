#include "query.h"

query::query(int &numWords, char *words)
{
    count = numWords;
    curr = 0;
    wordList = words;

}

void query::run()
{

}

bool query::checkSingleWord()
{
    if(wordList[0] != "OR" || wordList[0] != "AND" || wordList[0] == "NOT")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool query::checkOpp()
{
    if(wordList[curr] == "AND" || wordList[curr] == "OR" || wordList[curr] == "NOT")
        return true;
    else
        return false;
}

char* query::getNextWord()
{

}




