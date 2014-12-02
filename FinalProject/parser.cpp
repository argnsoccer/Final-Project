#include "parser.h"


Parser::Parser()
{

}

void Parser::parse(char *fileName)
{
    xml_document<> doc;
    inputFile = new file<>(fileName);
    doc.parse<0>((*inputFile).data());
    char* start;
    char* endWord;
    bool stopWord;
    curNode = doc.first_node()->first_node("page");//goes to first <page> marking
    xml_node<>* titleNode;
    int page = 1;
    int stemEnd;
    char* buffer;
    for(int i = 0; i < 50; ++i)
    {
        titleNode = curNode->first_node("title");
        while(titleNode != nullptr)
        {
            //cout << "tile: " << titleNode->value() << endl;
            //cout << "text: " << titleNode->next_sibling("revision")->first_node("text")->value() << endl;
            start = titleNode->next_sibling("revision")->first_node("text")->value();
            endWord = strchr(start, ' ');
            while(endWord != nullptr)
            {
                string inputWord(start, endWord);
                transform(inputWord.begin(), inputWord.end(), inputWord.begin(), ::tolower);//forces to lowercase
                inputWord.erase(std::remove_if(inputWord.begin(), inputWord.end(), ::ispunct), inputWord.end());
                start = endWord+1;
                endWord = strchr(start,' ');
                buffer = const_cast<char*>(inputWord.c_str());//casts as non-const to pass in
                stemEnd = stem(buffer, 0, inputWord.length());//gets the end of the new string
                inputWord = inputWord.substr(0, stemEnd);//creates a new truncated string
                stopWord = removeStopWords(inputWord);//removes if stop word
                if(stopWord == false)
                {
                    AVLindex.insert(inputWord, page, AVLindex.getRoot());
                    cout << "inputWord: " << inputWord << endl;
                }
            }
            titleNode = titleNode->next_sibling("title");

        }
        curNode = curNode->next_sibling("page");
        page++;
    }
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

string Parser::stemWord(string& word)
{

}





















//IndexInterface
//virtual ~IndexInterface();
//virtual void addToIndex(string&, int) = 0;
//virtual void removeFromIndex(string&) = 0;
//virtual vector<int> search(string&) = 0;
//virtual bool contains(string&) = 0;
//virtual vector<Data <string, int> >* save() = 0;
//virtual void load(vector<Data<string, int> >&) = 0;
//virtual void printReverseFileIndex() = 0;
//virtual void deleteIndexes() = 0;
