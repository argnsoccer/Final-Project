#ifndef INDEXER_H
#define INDEXER_H


class Indexer
{
public:
    Indexer();
    virtual ~Indexer(){}

private:
    virtual void save() = 0;
    virtual void load() = 0;
    virtual void appendFile() =0;
    virtual void clearFile() = 0;

};

#endif // INDEXER_H
