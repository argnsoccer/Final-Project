#ifndef DRIVER_H
#define DRIVER_H
#include "parser.h"
#include "indexer.h"
#include <iostream>

using namespace std;

class Driver
{
public:
    Driver(char* fileName);
    ~Driver(){delete i;}

private:
    Parser p;
    Indexer* i;

};

#endif // DRIVER_H
