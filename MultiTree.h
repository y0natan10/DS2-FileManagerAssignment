#ifndef MULTITREE_H
#define MULTITREE_H

#include "MultiTreeNode.h"
#include <memory>

#include <queue>
// couldn't figure out how to do it without either
// adding another method for recursion or without using a queue (or another data structure)

template <typename T>
class MultiTree
{
private:
    MultiTreeNode<T> *root;

public:
    MultiTree(NodeRecord<T> *rootRecord) : root(new MultiTreeNode<T>(rootRecord)) {};
    ~MultiTree() { delete root; };
    T getRootKey() { return root->getKey(); }

    MultiTreeNode<T> *searchRecord(const T &keyToSearch);
    bool addRecord(const T &parentKey, NodeRecord<T> *record);
    bool removeRecord(const T &key);

    void print() const { printRecursive(root, 0); };
    void printRecursive(MultiTreeNode<T> *node, int indentLevel) const;
    // after finishing this assignment i realize i could've coppied the concepts
    // from this recursive method in the search method (and by extension remove)
    // oh well i thought the queue idea was clever
};

// Implementation

// one liners will be implemented with decleration

// template <typename T>
// MultiTree<T>::MultiTree(NodeRecord<T> *rootRecord) : root(new MultiTreeNode<T>(rootRecord)) {}
// template <typename T>
// MultiTree<T>::~MultiTree()
// {
//     delete root;
// }

template <typename T>
bool MultiTree<T>::addRecord(const T &parentKey, NodeRecord<T> *record)
{

    // search and get a pointer to the parent node
    // if the parent is not found then don't add the new record
    MultiTreeNode<T> *parent = this->searchRecord(parentKey);
    if (parent != nullptr)
    {
        // add the child to parent
        return parent->addChild(record);
    }
    else
    {
        // no record was added
        return false;
    }
}

template <typename T>
bool MultiTree<T>::removeRecord(const T &keyToDelete)
{
    if (root->getKey() == keyToDelete)
    {
        return false; // removing root is a bad idea
    }

    queue<MultiTreeNode<T> *> nodes;
    nodes.push(root);

    // first iteration through this loop gives us the root
    while (!nodes.empty())
    {
        MultiTreeNode<T> *current = nodes.front();
        nodes.pop();
        // queue is now empty
        // go through each child of current (root for now)
        for (auto child : current->getChildren())
        {
            // if we find what we're looking for do whatever we needed to do (this case, kill)
            if (child->getKey() == keyToDelete)
            {
                current->removeChild(keyToDelete);
                return true;
            }
            else
            {
                // since the item might have kids
                // we (i) need to add it to the literal and figuritive queue
                nodes.push(child);
            }
        }
    }
    return false;
}

template <typename T>
MultiTreeNode<T> *MultiTree<T>::searchRecord(const T &keyToSearch)
{
    // same concept used in remove record
    queue<MultiTreeNode<T> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        MultiTreeNode<T> *current = nodes.front();
        nodes.pop();

        // check if the current node's key matches
        if (current->getKey() == keyToSearch)
        {
            return current; // return the MultiTreeNode if found
        }

        // add all children to queue for next round of searching
        for (auto child : current->getChildren())
        {
            nodes.push(child);
        }
    }
    return nullptr; // nullptr if not found
}

template <typename T>
// would indentLevel be better than depth? yes says me. depth sounds more like vertical space than horizontal
void MultiTree<T>::printRecursive(MultiTreeNode<T> *node, int indentLevel) const
{
    if (!node)
    {
        return;
    }
    // print the current node with indentationLevel based on indentLevel
    cout << string(indentLevel * 3, ' ') << node->getKey() << endl;
    // string contrsuctor ftwwwwww
    // recursively print each child, increasing 'indentLevel' by 1
    for (auto child : node->getChildren())
    {
        // the best way to explain recursion is to explain recursion with the best way (see beginning of sentence for more info)
        printRecursive(child, indentLevel + 1);
    }
}

#endif // MULTITREE_H
