#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <vector>
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
            void setElement(int elem){this->element = elem;}
            int getElement(){return element;}
            string getWord(){return word;}
            void setWord(string w){this->word = w;}

        };
        AVLNode* root;
        int treeHeight;


    public:
        AVLTree();
        void insert(string& s, int i, AVLNode* &k);
        void rotateWithLeftChild(AVLNode* &k);
        void rotateWithRightChild(AVLNode* &k);
        void doubleWithLeftChild(AVLNode* &k);
        void doubleWithRightChild(AVLNode* &k);
        int height(AVLNode* t);

};

#endif //AVLTREE_H
