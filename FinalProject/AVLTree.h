#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class AVLTree
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


    public:
        AVLTree();
        void insert(string& s, int page, AVLNode *k);
        void rotateWithLeftChild(AVLNode* &k);
        void rotateWithRightChild(AVLNode* &k1);
        void doubleWithLeftChild(AVLNode* &k);
        void doubleWithRightChild(AVLNode* &k);
        int height(AVLNode* t);
        AVLNode *getRoot();
        bool preorderSearch(int page, AVLNode* k, string &searchWord);

};

inline AVLTree::AVLNode *AVLTree::getRoot()
{
    return this->root;
}

#endif //AVLTREE_H
