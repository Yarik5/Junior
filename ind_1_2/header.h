#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string ToString(bool res) {return res? "true":"false"; }

class Node
{
    friend class Tree;
private:
    Node *left;
    Node *right;
    char Data;
    bool isend;
public:
    Node() {
        left = right = nullptr;
        isend = false;
    }
    virtual ~Node () {};
};

class Tree
{
private:
    Node *first;

    bool search_helper(Node * , string ) const;
    void add_helper(Node * , string ) const;
    void show_helper(Node * , string) const;

public:
    Tree() {first = nullptr;}

    void add_word(string word)
    {
        if(first == nullptr)
            first = new Node;
        add_helper(first, word);
    }

    void show_all()
    {
        show_helper(first, "");
        cout << endl;
    }

    void search(string word)
    {
        cout << ToString(search_helper(first, word)) << endl;
    }

    virtual ~Tree () {};
};

void Tree::add_helper(Node *temp, string word) const
{
    if(word.size() == 0)
    {
        temp->isend = true;
        return;
    }
    if(temp->Data)
    {
        if(temp->Data == word[0] )
        {
            if(temp->left == nullptr)
            {
                temp->left = new Node;
            }
            word.erase(0, 1);
            add_helper(temp->left, word);
        }
        else
        {
            if(temp->right == nullptr)
                temp->right = new Node;
            add_helper(temp->right, word);
        }
    }
    else if(!temp->Data)
    {
        temp->Data = word[0];
        word.erase(0, 1);
        temp->left = new Node;
        temp->right = nullptr;
        add_helper(temp->left, word);
    }
}

void Tree::show_helper(Node *temp, string word = "") const
{
    if(temp == nullptr)
        return;
    if(temp->isend)
        cout << word << endl;

    if(temp->right != nullptr)
        show_helper(temp->right, word);
    word += temp->Data;
    show_helper(temp->left, word);

}

bool Tree::search_helper(Node *temp, string word) const
{
    bool res = true;
    while(temp != nullptr)
    {
        if(word.size() == 0)
        {
            if(!temp->isend)
                return false;
            break;
        }
        if(temp->right != nullptr)
        {
            if(search_helper(temp->right, word))
                break;
        }
        res &= (temp->Data == word[0]);
        word.erase(0, 1);
        temp = temp->left;
    }
    return res;
}
#endif
