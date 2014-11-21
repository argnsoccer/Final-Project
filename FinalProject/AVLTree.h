#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"
#include <string>
using namespace std;

class AVLTree
{

    private:
        AVLNode* root;
        void insert(int val, AVLNode* t);
        int height(AVLNode* t){if(t==nullptr){return -1;}else{return height;};


    public:
        AVLTree();
        void insert(string, int, AVLNode*);
};

#endif // AVLTREE_H
