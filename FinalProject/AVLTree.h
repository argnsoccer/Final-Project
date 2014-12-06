#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include "indexer.h"
using namespace std;

class AVLTree : public Indexer
{

    private:
        struct AVLNode
        {
            int height;
            vector<int> pages;
            string word;
            AVLNode* left;
            AVLNode* right;
            AVLNode(string word, int page, AVLNode* left,AVLNode* right):
                word(word), left(left), right(right){pages.push_back(page);}
            void setHeight(int height){this->height = height;}
            int getHeight(){return height;}
            void setPage(int elem){this->pages.push_back(elem);}
            int getPage(int i){return pages[i];}
            string getWord(){return word;}
            void setWord(string w){this->word = w;}

        };
        AVLNode* root;
        int treeHeight;
        ifstream AVLLoader;
        ofstream AVLSaver;


    public:
        AVLTree();
        AVLTree(AVLTree *root);
        AVLNode *insert(string& s, int page, AVLNode *k);
        void save(AVLNode *&myTree);//fix this soon
        void load();
        void appendFile();
        void rotateWithLeftChild(AVLNode* &k);
        void rotateWithRightChild(AVLNode* &k1);
        void doubleWithLeftChild(AVLNode* &k);
        void doubleWithRightChild(AVLNode* &k);
        int height(AVLNode* t);
        AVLNode *getRoot();
        AVLNode *setRoot(AVLNode* r);
        bool search(int page, string &searchWord, AVLNode *k);

};

inline AVLTree::AVLNode *AVLTree::getRoot()
{
    return root;
}

inline AVLTree::AVLNode *AVLTree::setRoot(AVLNode *r)
{
    this->root = r;
}

#endif //AVLTREE_H
