#include "AVLTree.h"

AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::AVLTree(AVLTree* index)
{
    this->root = index->getRoot();
}

int AVLTree::height(AVLNode *t)
{
    int temp;
    if(t==nullptr)
    {
        return -1;
    }
    else
    {
        temp = t->height;
        return temp;
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
        bool flag = false;
        for(int i = 0; i < k->pages.size(); ++i)
        {
            if(page == k->pages.at(i))
            {
                k->occurrences.at(i) = k->occurrences.at(i) + 1;//increment occurrences
                flag = true;
                //k->getInfo(i);
                break;
            }
        }
        if(flag == false)
        {
            k->pages.push_back(page);
            k->occurrences.push_back(1);
        }
        return true;
    }
    return false;
}

void AVLTree::appendFile()
{
    cout << "in append file" << endl;
}

void AVLTree::clearIndex()
{
    clear(root);
    cout << "Index has been cleared." << endl;
}

void AVLTree::clear(AVLTree::AVLNode* root)
{
    AVLTree::AVLNode* temp;
    if(root != nullptr)
    {
        clear(root->left);
        clear(root->right);
        temp = root;
        free(temp);
        root = nullptr;
    }

}

void AVLTree::save()
{
    AVLSaver.open("SaveFile.txt");
    saveToFile(root, AVLSaver);

}

void AVLTree::saveToFile(AVLNode *root, ofstream& AVLSaver)
{
    if(root != nullptr)
    {
        AVLSaver << root->getWord() << endl;
        for(int i = 0; i < root->pages.size(); ++i)
        {
            AVLSaver << root->pages.at(i) << " ";
            //cout << root->pages.at(i) << " ";
            AVLSaver << root->occurrences.at(i) << " ";
            //cout << "(" << root->occurrences.at(i) << ") ";
        }
        AVLSaver << endl;
        //cout << endl;
        saveToFile(root->left, AVLSaver);
        saveToFile(root->right, AVLSaver);
    }
}

void AVLTree::load()
{
    AVLLoader.open("SaveFile.txt");
    loadFromFile(AVLLoader);
}

void AVLTree::loadFromFile(ifstream& AVLLoader)
{
    vector<int> tempPages;
    vector<int> tempOcc;
    string word; int page, temp;
    while(!AVLLoader.eof())
    {
        int wordCheck = 0;
        char peek = AVLLoader.peek();
        while(peek != '\n')
        {
            if(wordCheck == 0)
            {
                AVLLoader >> word;
                AVLLoader.get();//gets \n
            }
            AVLLoader >> page;
            tempPages.push_back(page);
            tempPages.shrink_to_fit();
            AVLLoader.get();//gets the ' '
            AVLLoader >> temp;
            tempOcc.push_back(temp);
            tempOcc.shrink_to_fit();
            AVLLoader.get();//gets the ' '
            wordCheck++;
            peek = AVLLoader.peek();
            if((int)peek == -1)//would not break if eof() was reached even if part of while check, so I use this break
            {
                break;
            }
        }
        AVLLoader.get();//gets the \n
        root = insert(word, root, tempPages, tempOcc);
        tempPages.clear();
        tempPages.shrink_to_fit();
        tempOcc.clear();
        tempOcc.shrink_to_fit();
    }
}

vector<Pages> AVLTree::searchFile(string &word, vector<Pages>& pages)
{
    cout << "in searchFile" << endl;
    cout << "word: " << word << endl;
    return searchFileHelper(word, root, pages);
}

vector<Pages> AVLTree::searchFileHelper(string &word, AVLNode *root, vector<Pages>& pages)
{
    vector<Pages> resultPages;
    Pages page;
    if(root == nullptr)
    {
        cout << "Root is NULL!!" << endl;
        return resultPages;
    }
    if(word < root->word)
    {
        resultPages = searchFileHelper(word, root->left, pages);
    }
    else if(word > root->word)
    {
        resultPages = searchFileHelper(word, root->right, pages);
    }
    else if(word == root->word)
    {
        int size = pages.size();
        for(int i = 0; i < size; ++i)
        {
            page = pages.at(i);
            cout << "page Size 5000: " << pages.size() << endl;
            cout << i << endl;
            int size2 = root->pages.size();
            for(int j = 0; j < size2; ++j)
            {
//                cout << "Title: " << page.getTitle() << endl;
//                cout << "Page: " << page.getPage() << endl;
//                cout << "Text: " << page.getText() << endl;
                if(root->pages.at(j) == page.getPage())
                {
                    Pages temp = page;
                    cout << "here" << endl;

                    resultPages.push_back(page);
                    temp = resultPages.at(j);
                }
            }
        }
    }
    return resultPages;
}

AVLTree::AVLNode* AVLTree::insert(string& word, int page, AVLNode* t)//change the root actually
{
    if(t==nullptr)
    {
        t = new AVLNode(word, page, nullptr, nullptr);
    }
    else if(word < t->word)
    {
        t->left = insert(word, page, t->left);
        if((height(t->left) - height(t->right)) == 2)
        {
            if(word < (t->left->word))  //case1
                t = rotateWithLeftChild(t);
            else					  //case2
                t = doubleWithLeftChild(t);
        }
    }
    else if((t->word) < word)
    {
        t->right = insert(word, page, t->right);
        if(height(t->right)-height(t->left) == 2)
        {
            if(word > (t->right->word))
                t = rotateWithRightChild(t);//case 4
            else
                t = doubleWithRightChild(t);//case 3
        }
    }
    t->height = max(height(t->left),height(t->right))+1;
    return t;
}

AVLTree::AVLNode* AVLTree::insert(string& word, AVLNode* t, vector<int> &pages, vector<int> &occurrences)//change the root actually
{
    if(t==nullptr)
    {
        t = new AVLNode(word, nullptr, nullptr, pages, occurrences);
    }
    else if(word < t->word)
    {
        t->left = insert(word, t->left, pages, occurrences);
        if((height(t->left) - height(t->right)) == 2)
        {
            if(word < (t->left->word))  //case1
                t = rotateWithLeftChild(t);
            else					  //case2
                t = doubleWithLeftChild(t);
        }
    }
    else if((t->word) < word)
    {
        t->right = insert(word, t->right, pages, occurrences);
        if(height(t->right)-height(t->left) == 2)
        {
            if(word > (t->right->word))
                t = rotateWithRightChild(t);//case 4
            else
                t = doubleWithRightChild(t);//case 3
        }
    }
    t->height = max(height(t->left),height(t->right))+1;
    return t;
}


AVLTree::AVLNode* AVLTree::rotateWithLeftChild(AVLNode* &k1)   //k1 node above alpha
{
    AVLNode* k2 = k1->left;

    k1->left = k2->right;
    k2->right = k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height = max(height(k2->left),k1->height)+1;
    return k2;
}

AVLTree::AVLNode *AVLTree::rotateWithRightChild(AVLNode* &k1)
{
    AVLNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height = max(k1->height,height(k2->right))+1;
    return k2;
}

AVLTree::AVLNode *AVLTree::doubleWithLeftChild(AVLNode* &k3)
{
    k3->left = rotateWithRightChild(k3->left);
    return rotateWithLeftChild(k3);
}

AVLTree::AVLNode *AVLTree::doubleWithRightChild(AVLNode*& k3)
{
    k3->right = rotateWithLeftChild(k3->right);
    return rotateWithRightChild(k3);
}

