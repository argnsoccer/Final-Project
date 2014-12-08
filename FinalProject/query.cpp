#include "query.h"
#include "stemmer.h"
using namespace std;

Query::Query()
{



}

void Query::run(Indexer *i, vector<Pages> &pages)
{
    //cout << "page Size 0: " << pages.size() << endl;
    vector<Pages> resultPages;
    if(getSearchWords() == false)//remove stop words and stem then search
    {
        char* buffer = const_cast<char*>(str.c_str());
        int len = str.length()-1;
        int stemEnd;
        stemEnd = stem(buffer,0, len);
        str = str.substr(0, stemEnd);
        resultPages = i->searchFile(str, pages);
    }

    Pages page;
    if(resultPages.size() > 0)
    {
        cout << "resultPages size: " << resultPages.size() << endl;
      int size = resultPages.size();
      for(int i = 1; i < size+1; ++i) //display contents of vector
      {
          cout << "in for" << endl;
          page = resultPages.at(i-1);
          cout << i << ": " << page.getTitle() << endl;
      }

      cout << "Which page would you like to see?" << endl;
      int command;
      cin >> command;
      page = resultPages.at(command-1);
      cout << page.getText() << endl;
    }
    else
        cout << "Sorry there are no pages with this word." << endl;

}

bool Query::getSearchWords()
{
    cout << "Search: ";
    cin >> str;
    //getline(cin,str);

//    char * cstr = new char [str.length()+1];
//    strcpy (cstr, str.c_str());

    str.erase(std::remove_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isalnum))), str.end());
    transform(str.begin(), str.end(), str.begin(), ::tolower);//forces to lowercase

    bool stopWord = removeStopWords(str);

    // cstr now contains a c-string copy of str

    /*char * p = strtok (cstr," ");
    while (p!=0)
    {
      words.push_back(p);
      p = strtok(NULL," ");
    }
    cout << "got here" << endl;

    delete[] cstr;*/
    return stopWord;
}

bool Query::removeStopWords(string& word)
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

bool Query::checkSingleWord(string temp)
{
    if(temp == "OR" || temp == "AND" || temp == "NOT")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Query::checkOpp(string temp)
{
    if(temp == "AND" || temp == "OR" || temp == "NOT")
        return true;
    else
        return false;
}

string Query::getNextWord()
{

}
