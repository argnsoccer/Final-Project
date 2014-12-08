#ifndef INDEXER_H
#define INDEXER_H
#include <string>
#include <vector>
#include "pages.h"

class Indexer
{
public:
    Indexer();
    virtual ~Indexer(){}

    virtual void save() = 0;
    virtual void load() = 0;
    virtual void appendFile() =0;
    virtual void clearIndex() = 0;
    virtual std::vector<Pages> searchFile(std::string& word, std::vector<Pages>& pages) = 0;

private:

};

#endif // INDEXER_H
