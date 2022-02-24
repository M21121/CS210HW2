#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;

struct Employee {
    int id;
    int age;
    string name;

    Employee(int id = -1, int age = -1, string name = "")
        : id{ id }, age{ age }, name{ name } { }
};

class BinarySearchTree
{

public:

    struct BinaryNode
    {
        Employee element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const Employee& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{ theElement }, left{ lt }, right{ rt } { }

        BinaryNode(Employee&& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{ std::move(theElement) }, left{ lt }, right{ rt } { }
        
        BinaryNode() {}
    };

    BinarySearchTree() : root{ nullptr }
    {
    }

    /**
     * Destructor for the tree
     */
    ~BinarySearchTree()
    {
        makeEmpty();
    }

    /**
     * Find the smallest item in the tree.
     * return default employee if empty
     */
    const Employee& findMin() const
    {
        return findMin(root)->element;
    }

    /**
     * Find the largest item in the tree.
     * return default employee if empty
     */
    const Employee& findMax() const
    {
        return findMax(root)->element;
    }

    /**
     * Prints employee info if id found in tree
     */
    bool find(const int id) const
    {
        find(id, root);
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty() const
    {
        if (root != nullptr)
        {
            return true;
        }
        return false;
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty()
    {
        while (!isEmpty())
        {
            remove(root->element.id, root);
        }
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert(const Employee& x)
    {
        insert(x, root);
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(const int id)
    {
        remove(id, root);
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void report() const
    {
        //use stack implementation
    }

private:

    BinaryNode* root;

    BinaryNode* insert(BinaryNode*& t, const Employee& x)
    {
        if (t == nullptr)
        {
            BinaryNode* newNode = new BinaryNode(x, nullptr, nullptr);
            return newNode;
        }
        if (t->element.id < x.id)
        {
            t->right = insert(t->right, x);
        }
        else
        {
            t->left = insert(t->left, x);
        }
        return t;
    }

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(const Employee& x, BinaryNode*& t)
    {
        insert(t, x);
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove(const int id, BinaryNode*& t)
    {
        BinaryNode* delNode = findNode(id, t);
        int children = 0;
        if (delNode->left == nullptr) { children++; }
        if (delNode->right == nullptr) { children++; }

        if (children == 0)
        {

        }
        else if (children == 1)
        {

        }
        else
        {

        }

    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode* findMin(BinaryNode* t) const
    {
        if (isEmpty())
        {
            return nullptr;
        }
        BinaryNode* currentNode = t;
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }
        return currentNode;
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode* findMax(BinaryNode* t) const
    {
        if (isEmpty())
        {
            return nullptr;
        }
        BinaryNode* currentNode = t;
        while (currentNode->right != nullptr)
        {
            currentNode = currentNode->right;
        }
        return currentNode;
    }

    // Code inspired by https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    BinaryNode* findNode(const int id, BinaryNode* t) const
    {
        Stack<BinaryNode*> s;
        BinaryNode* curr = t;

        while (curr != NULL || s.isEmpty() == false)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            BinaryNode* copy = s.pop();
            if (copy->element.id == id)
            {
                return copy;
            }

            cout << curr->element.name << " ";

            curr = curr->right;
        }

        return nullptr;
    }

    /**
     * id is item to search for.
     * t is the node that roots the subtree.
     */
    bool find(const int id, BinaryNode* t) const
    {
        if (findNode(id, t) == nullptr)
        {
            return false;
        }
        return true;
    }

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty(BinaryNode*& t)
    {
        while (!isEmpty())
        {
            remove(root->element.id, root);
        }
    }
};

#endif
