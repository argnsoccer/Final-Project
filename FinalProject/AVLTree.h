#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"
#include <string>
using namespace std;

class AVLTree
{

    private:
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
