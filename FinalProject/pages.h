#ifndef PAGES_H
#define PAGES_H

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <string>

class Pages
{
public:
    Pages();
    Pages(int page, rapidxml::xml_node<>* node);
    int getPage();
    void setPage(int p);
    rapidxml::xml_node<>* getPageNode();
    void setPageNode(rapidxml::xml_node<>* pgNode);
    char *getText();
    void setText(char *text);
    char *getTitle();
    void setTitle(char *title);


private:
    int page;
    rapidxml::xml_node<>* pageNode;
    char* text;
    char* title;

};

inline int Pages::getPage()
{
    return page;
}

inline void Pages::setPage(int p)
{
    this->page = p;
}

inline rapidxml::xml_node<>* Pages::getPageNode()
{
    return pageNode;
}

inline void Pages::setPageNode(rapidxml::xml_node<>* pgNode)
{
    this->pageNode = pgNode;
}

inline char* Pages::getText()
{
    return text;
}

inline void Pages::setText(char* text)
{
    this->text = text;
}

inline char* Pages::getTitle()
{
    return title;
}

inline void Pages::setTitle(char* t)
{
    this->title = t;
}






#endif // PAGES_H
