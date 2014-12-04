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
    char* pageStart;
    char* pageEnd;
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
            start = titleNode->next_sibling("revision")->first_node("text")->value();//takes iterator to first text in page
//            pageStart = start;//for returning the page on search
            pageEnd = strchr(start, '<');//goes to end of text
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
                stemEnd = stem(buffer, 0, length) + 1;//gets the end of the new string
                inputWord = inputWord.substr(0, stemEnd);//creates a new truncated (stemmed) string
                if(stopWord == false)
                {
                    hasWord = AVLindex.preorderSearch(page, AVLindex.getRoot(), inputWord);
                    if(hasWord == false)
                    {
                        AVLindex.insert(inputWord, page, AVLindex.getRoot());
                        //cout << "inputWord: " << inputWord << endl;
                    }
                }
            }
            titleNode = titleNode->next_sibling("title");

        }
        curNode = curNode->next_sibling("page");
        string pageText(start, pageEnd);//creates a string of all the text in one page (won't work because bigger than maxsize)
        cout << pageText;
        webPage.setPage(page);//sets page number
        webPage.setText(pageText);//sets the pageText
        pages.push_back(webPage);//adds the page to the vector of pages
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

void Parser::prepWord(string &word)
{
    word.erase(std::remove_if(word.begin(), word.end(), std::not1(std::ptr_fun(::isalnum))), word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);//forces to lowercase
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
