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
    std::string getText();
    void setText(std::string &text);


private:
    int page;
    rapidxml::xml_node<>* pageNode;
    std::string text;

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

inline std::string Pages::getText()
{
    return text;
}

inline void Pages::setText(std::string& text)
{
    this->text = text;
}






#endif // PAGES_H
