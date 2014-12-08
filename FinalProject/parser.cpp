#include "parser.h"


Parser::Parser()
{

}

AVLTree *Parser::parse(char *fileName)
{
    xml_document<> doc;
    inputFile = new file<>(fileName);
    doc.parse<0>((*inputFile).data());
    char* start;
    char* endWord;
    char* pageStart;
    bool stopWord;
    curNode = doc.first_node()->first_node("page");//goes to first <page> marking
    xml_node<>* titleNode;
//    Index = new AVLTree();
    AVLIndex = new AVLTree();
    int page = 1;
    int stemEnd;
    char* buffer;
    bool hasWord = false;
    int length;
    while(curNode != nullptr)
    {
        titleNode = curNode->first_node("title");
        start = titleNode->next_sibling("revision")->first_node("text")->value();//takes iterator to first text in page
        pageStart = start;
        endWord = strchr(start, ' ');//gets first word
        while(endWord != nullptr)
        {
            string inputWord(start, endWord);//creates string to be indexed
            prepWord(inputWord);//preps the word to be indexed
            start = endWord+1;//moves the char pointer to the start of the next word
            endWord = strchr(start,' ');//gets the ending of the word
            stopWord = removeStopWords(inputWord);//removes if stop word
            buffer = const_cast<char*>(inputWord.c_str());//casts as non-const to pass in
            length = strlen(buffer)-1;//sets to length minus 1 to be pointing to the last char
            stemEnd = stem(buffer, 0, length);//gets the end of the new string
            inputWord = inputWord.substr(0, stemEnd);//creates a new truncated (stemmed) string
            if(stopWord == false)
            {
                hasWord = AVLIndex->search(page, inputWord, AVLIndex->getRoot());//checks to see if word is already in index
                if(hasWord == false)
                {
                    AVLIndex->setRoot(AVLIndex->insert(inputWord, page, AVLIndex->getRoot()));
                    //cout << "inputWord: " << inputWord << endl;
                }
            }
        }
        curNode = curNode->next_sibling("page");
        webPage.setPage(page);//sets page number
        webPage.setText(pageStart);//sets the pageText
        webPage.setTitle(titleNode->value());
        pages.push_back(webPage);//adds the page to the vector of pages
        page++;
    }
    return AVLIndex;
}

bool Parser::removeStopWords(string& word)
{
    ifstream fileReader;
    set<string> StopWords;
    string temp;
    fileReader.open("stopwords_en.txt");
    while(fileReader.eof() == false)
    {
        getline(fileReader,temp);
        StopWords.insert(temp);
    }
    if(StopWords.find(word) == StopWords.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Parser::prepWord(string &word)
{
    word.erase(std::remove_if(word.begin(), word.end(), std::not1(std::ptr_fun(::isalnum))), word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);//forces to lowercase
}




















