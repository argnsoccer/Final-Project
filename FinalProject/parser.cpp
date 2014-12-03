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
    bool hasWord = false;
    int length;
    for(int i = 0; i < 50; ++i)
    {
        titleNode = curNode->first_node("title");
        while(titleNode != nullptr)
        {
            start = titleNode->next_sibling("revision")->first_node("text")->value();
            endWord = strchr(start, ' ');
            while(endWord != nullptr)
            {
                string inputWord(start, endWord);
                transform(inputWord.begin(), inputWord.end(), inputWord.begin(), ::tolower);//forces to lowercase
                inputWord.erase(std::remove_if(inputWord.begin(), inputWord.end(), ::ispunct), inputWord.end());//removes punctuation
                start = endWord+1;
                endWord = strchr(start,' ');
                stopWord = removeStopWords(inputWord);//removes if stop word
                buffer = const_cast<char*>(inputWord.c_str());//casts as non-const to pass in
                length = strlen(buffer)-1;
                stemEnd = stem(buffer, 0, length) + 1;//gets the end of the new string
                cout << "stemEnd: " << stemEnd << endl;
                inputWord = inputWord.substr(0, stemEnd);//creates a new truncated (stemmed) string
                if(stopWord == false)
                {
                    hasWord = AVLindex.preorderSearch(page, AVLindex.getRoot(), inputWord);
                    if(hasWord == false)
                    {
                        AVLindex.insert(inputWord, page, AVLindex.getRoot());
                        cout << "inputWord: " << inputWord << endl;
                    }
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
