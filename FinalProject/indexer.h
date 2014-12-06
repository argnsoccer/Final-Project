#ifndef INDEXER_H
#define INDEXER_H
#include <string>
#include "pages.h"

class Indexer
{
public:
    Indexer();
    virtual ~Indexer(){}

    virtual void save() = 0;
    virtual void load() = 0;
    virtual void appendFile() =0;
    virtual void clearFile() = 0;
    virtual Pages searchFile(std::string& word) = 0;

private:

};

#endif // INDEXER_H
