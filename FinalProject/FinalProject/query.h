#ifndef QUERY_H
#define QUERY_H

class query
{
public:
    query();
    void run();

private:
    int count;
    int curr;
    char* wordList[];
    bool checkSingleWord(int count, char *words[]);
    bool checkOpp();
    char* getNextWord();

};

#endif // QUERY_H
