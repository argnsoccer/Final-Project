#ifndef DRIVER_H
#define DRIVER_H
#include "parser.h"
#include "indexer.h"
#include "query.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Driver
{
public:
    Driver(char* fileName);
    ~Driver(){delete i, buffer, buffer1;}

private:
    Parser p;
    Indexer* i;
    Query q;
    vector<Pages> pages;
    vector<Pages> pageSaver;
    Pages papel;
    string* buffer;
    string* buffer1;

};

#endif // DRIVER_H
