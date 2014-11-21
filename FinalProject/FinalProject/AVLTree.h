#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree
{

    private:
        AVLNode* root;
        void insert(int val, AVLNode* t);
        int height(AVLNode* t){return t==null?-1:t->height};


    public:
        AVLTree();
        void insert(int);
};

#endif // AVLTREE_H
