#include "AVLTree.h"

AVLTree::AVLTree()
{
    root = nullptr;
}

int AVLTree::height(AVLNode *t)
{
    if(t==nullptr)
    {
        return -1;
    }
    else
    {
        return treeHeight;
    }
}

bool AVLTree::search(int page, string& searchWord, AVLNode *k)
{
    if(k == nullptr)
    {
        return false;
    }
    if(searchWord < k->word)
    {
        search(page, searchWord, k->left);
    }
    else if(searchWord > k->word)
    {
        search(page, searchWord, k->right);
    }
    else if(searchWord == k->word)
    {
        k->pages.push_back(page);
        return true;
    }
}

AVLTree::AVLNode* AVLTree::insert(string& word, int page, AVLNode* t)//change the root actually
{
    if(t==nullptr)
    {
        t = new AVLNode(word, page, nullptr, nullptr);
        return t;
    }
    else if(word < t->word)
    {
        t->left = insert(word, page, t->left);
        if((height(t->left) - height(t->right)) == 2)
        {
            if(word < (t->left->word))  //case1
                rotateWithLeftChild(t);
            else					  //case2
                doubleWithLeftChild(t);
        }
    }
    else if((t->word) < word)
    {
        t->right = insert(word, page, t->right);
        if(height(t->right)-height(t->left) == 2)
        {
            if(word > (t->right->word))
                rotateWithRightChild(t);//case 4
            else
                doubleWithRightChild(t);//case 3
        }
    }
    t->height = max(height(t->left),height(t->right))+1;
    return t;
}

void AVLTree::rotateWithLeftChild(AVLNode* &k1)   //k1 node above alpha
{
    AVLNode* k2 = k1->left;

    k1->left = k2->right;
    k2->right = k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height = max(height(k2->left),height(k2->right))+1;
}

void AVLTree::rotateWithRightChild(AVLNode* &k1)
{
    AVLNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height = max(height(k2->left),height(k2->right))+1;
}

void AVLTree::doubleWithLeftChild(AVLNode* &k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void AVLTree::doubleWithRightChild(AVLNode*& k3)
{
    rotateWithLeftChild(k3->left);
    rotateWithRightChild(k3);
}

