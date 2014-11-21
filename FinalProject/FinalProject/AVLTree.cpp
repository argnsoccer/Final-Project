#include "AVLTree.h"

AVLTree::AVLTree()
{

}


            void AVLTree::insert(int val, AVLNode* &t)
            {
                if(t==nullptr)
                    t = new AVLNode(val, nullptr, nullptr);
                else if(val < t->element)
                {
                    insert(val, t->left)
                    if( height(t->left) - hight(t->right) == 2)
                    {
                        if(val < t->left->element())  //case1
                            rotateWithLeftChild(t);
                        else					  //case2
                            doubleWithLeftChild(t);
                    }

                }
                else if(t->element < val)
                {
                    insert(val, t->right);
                    if(height(t->right)-height(t->left) == 2)
                    {
                        if(val > t->right->element)
                            rotateWithRightChild(t);
                        else
                            doubleWithRightChild(t);
                    }
                }
                t->height = max(height(t->left),height(t->right))+1

            }

            void AVLTree::rotateWithLeftChild(AVLNode* &k1)   //k1 node above alpha
            {
                AVLNode* k2 = k1->left;

                k1->left = k2->right;
                k2->right = k1;
                k1->height = max(height(k1->left),height(k1->right))+1;
                k2->height = max(height(k2->left),height(k2->right))+1;


            }

            void AVLTree::doubleWithLeftChild(AVLNode*& k3)
            {
                rotateWithRightChild(k3->left);
                rotateWithLeftChild(k3);
            }
            void AVLTree::doubleWithRightChild
            {
                rotateWithLeftChild(k3->left);
                rotateWithRightChild(k3);
            }

