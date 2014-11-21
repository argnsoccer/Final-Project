#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode
{

    private:
        int height;
        int element;
        string word;
        AVLNode* left;
        AVLNode* right;
        friend class AVLTree;


public:
    AVLNode();
    AVLNode(string word, int theElem, AVLNode* l, AVLNode*r, int h = 0):word(word), element(theElem), left(l), right(r), height(h){}
};

#endif // AVLNODE_H
