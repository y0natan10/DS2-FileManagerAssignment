#ifndef TREELIST_H
#define TREELIST_H

#include "MultiTree.h"
#include <list>
#include <memory>

template <typename T>
class TreeList
{
private:
    // never understood why we use std:: when we can just use
    // using namespace std;
    std::list<MultiTree<T> *> trees;
    // but it was how it was given to me through the skeletal overlords
    // praise be thy name and all that

public:
    TreeList() {}; // Constructor
    ~TreeList();   // Destructor

    NodeRecord<T> *search(const T &key) const;
    void addTree(NodeRecord<T> *rootRecord);
    bool addRecord(const T &parentKey, NodeRecord<T> *record);
    bool removeRecord(const T &key);
    void printAllTrees() const;
};

// Implementation

// one liner

// template <typename T>
// TreeList<T>::TreeList()
// {
//     // TODO: complete
// }

template <typename T>
TreeList<T>::~TreeList()
{
    // self explanitary
    for (auto tree : trees)
    {
        delete tree;
    }
}

template <typename T>
void TreeList<T>::addTree(NodeRecord<T> *rootRecord)
{
    // self explanitary
    trees.push_back(new MultiTree<T>(rootRecord));
}

template <typename T>
bool TreeList<T>::addRecord(const T &parentKey, NodeRecord<T> *record)
{
    // i have stockholm syndrome for this looping mechanism
    for (auto tree : trees)
    {
        // this returns a t/f value based on if the parent was found
        if (tree->addRecord(parentKey, record))
        {
            return true; // if we added record successfully, return true
        }
    }
    return false; // only get here after going through every section,
    // if we got here then we must not have found the parent in which we're adding under
}

template <typename T>
bool TreeList<T>::removeRecord(const T &key)
{
    for (auto tree : trees)
    {
        // if we remove the record in this method, it returns true
        if (tree->removeRecord(key))
        {
            return true; // found the record to remove
        }
    }
    return false; // just like above, only here if inside method didn't return true ever
}

template <typename T>
void TreeList<T>::printAllTrees() const
{
    for (auto tree : trees)
    {
        tree->print();
        // cout << "--------" << endl;
        //  THIS IS TEMPORARY DELETE THIS PLEASE
        // i forgetti to delete this
    }
}

template <typename T>
NodeRecord<T> *TreeList<T>::search(const T &key) const
{
    for (auto tree : trees)
    {
        // is the one you are searching for in here?
        MultiTreeNode<T> *result = tree->searchRecord(key);
        if (result != nullptr)
        {
            return (result->getRecord()); // smeagol has found the one
        }
    }
    return nullptr; // smeagol has not found the one
}

#endif // TREELIST_H
