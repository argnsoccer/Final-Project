#ifndef AVLNODE_H
#define AVLNODE_H

class AVLNode
{

    private:
        int height;
        int element;
        AVLNode* left;
        AVLNode* right;
        AVLNode(int theElem, AVLNode* l, AVLNode*r, int h = 0):element(theElem), left(l), right(r), height(h),{}
        friend class AVLTree;




public:
    AVLNode();
};

#endif // AVLNODE_H
