#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"

class AVLTree
{

    private:
        AVLNode* root;
        void insert(int val, AVLNode* t);
        int height(AVLNode* t){if(t==nullptr){return -1;}else{return height;};


    public:
        AVLTree();
        void insert(int);
};

#endif // AVLTREE_H
