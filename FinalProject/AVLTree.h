#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include "indexer.h"
#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree : public Indexer
{

    private:
        struct AVLNode
        {
            int height;
            vector<int> pages;
            vector<int> occurrences;
            string word;
            AVLNode* left;
            AVLNode* right;
            AVLNode(string word, int page, AVLNode* left,AVLNode* right):
                word(word), left(left), right(right){height = 0; pages.push_back(page);occurrences.push_back(1);}
            void setHeight(int height){this->height = height;}
            int getHeight(){return height;}
            void setPage(int elem){this->pages.push_back(elem);}
            void setOccurrences(int elem){this->occurrences.push_back(elem);}
            string getWord(){return word;}
            void getInfo(int i)
            {
                cout << endl;
                cout << "word: " << this->word << endl << endl;
                cout << "page at i = " << i << ": " << this->pages.at(i) << endl;
                cout << "occurrences at i = " << i << ": " << this->occurrences.at(i) << endl;
            }

            void setWord(string w){this->word = w;}

        };
        AVLNode* root;
        int treeHeight;
        ifstream AVLLoader;
        ofstream AVLSaver;


    public:
        AVLTree();
        AVLTree(AVLTree *index);
        AVLNode *insert(string& s, int page, AVLNode *k);
        void save();
        void saveToFile(AVLNode *root, ofstream &AVLSaver);
        void load();
        void loadFromFile(ifstream& AVLLoader);
        void appendFile();
        void clearIndex();
        void clear(AVLNode* root);
        Pages searchFile(string &word);
        void rotateWithLeftChild(AVLNode* &k);
        void rotateWithRightChild(AVLNode* &k1);
        void doubleWithLeftChild(AVLNode* &k);
        void doubleWithRightChild(AVLNode* &k);
        int height(AVLNode* t);
        AVLNode *getRoot();
        AVLTree getStructure();
        void *setRoot(AVLNode* r);

        bool search(int page, string &searchWord, AVLNode *k);

};

inline AVLTree::AVLNode *AVLTree::getRoot()
{
    return root;
}

inline void *AVLTree::setRoot(AVLNode *r)
{
    this->root = r;
}

#endif //AVLTREE_H
